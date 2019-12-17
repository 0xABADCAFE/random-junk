/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#include <cstdio>
#include <cstdlib>
#include "include/gvm_core.hpp"
#include "include/gvm_debug.hpp"
#include "include/gvm_profiling.hpp"

using namespace GVM;

void*                   Interpreter::workingSet            = 0;
Interpreter::CallInfo*  Interpreter::callStack             = 0;
Interpreter::CallInfo*  Interpreter::callStackBase         = 0;
Interpreter::CallInfo*  Interpreter::callStackTop          = 0;
Scalar*                 Interpreter::frameStack            = 0;
Scalar*                 Interpreter::frameStackBase        = 0;
Scalar*                 Interpreter::frameStackTop         = 0;
const uint8*            Interpreter::programCounter        = 0;
const FuncInfo*         Interpreter::functionTable         = 0;
uint32                  Interpreter::functionTableSize     = 0;
const HostCall*         Interpreter::hostFunctionTable     = 0;
uint32                  Interpreter::hostFunctionTableSize = 0;
Scalar**                Interpreter::dataTable             = 0;
uint32                  Interpreter::dataTableSize         = 0;


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Result Interpreter::init(
    const size_t rSize,
    const size_t fSize,
    const FuncInfo* func,
    const HostCall* host,
    Scalar** data
) {
    if (!func || !host || !data) {
        gvmDebug("GVM::Interpreter::init()\n\tTables cannot be empty\n");
        return MISC_ILLEGAL_VALUE;
    }

    if (rSize < MIN_CALL_DEPTH || rSize > MAX_CALL_DEPTH) {
        gvmDebug(
            "GVM::Interpreter::init()\n\tReturn Stack Size %d is not in range %d - %d\n",
            (int)rSize,
            MIN_CALL_DEPTH,
            MAX_CALL_DEPTH
        );
        return MISC_ILLEGAL_VALUE;
    }

    size_t lSize = (fSize ? fSize : rSize * FuncInfo::MAX_FRAME_SIZE);
    if (lSize < MIN_STACK_SIZE || lSize > MAX_STACK_SIZE) {
        gvmDebug(
            "GVM::Interpreter::init()\n\tFrame Stack Size %d is not in range %d - %d\n",
            (int)lSize,
            MIN_STACK_SIZE,
            MAX_STACK_SIZE
        );
        return MISC_ILLEGAL_VALUE;
    }

    size_t callStackSize   = (1 + rSize) * sizeof(CallInfo);
    size_t frameStackSize  = (lSize + REDZONE_BUFFER * 2) * sizeof(Scalar);
    size_t totalAllocation = callStackSize + frameStackSize;

    gvmDebug(
        "GVM::Interpreter::init()\n"
        "\tRequire %d bytes for working set:\n"
        "\t%d bytes for call stack  (%d [+1 redzone] of %d bytes each)\n"
        "\t%d bytes for frame stack (%d of %d bytes each, including start and end red zones of %d entries each)\n",
        (int)totalAllocation,
        (int)callStackSize, (int)rSize, (int)sizeof(CallInfo),
        (int)frameStackSize,(int)lSize, (int)sizeof(Scalar),
        (int)REDZONE_BUFFER
    );

    uint8* readySet = (uint8*)std::calloc(totalAllocation, sizeof(uint8));
    if (!readySet) {
        gvmDebug("GVM::Interpreter::init()\n\tCould not allocate working set\n");
        return INIT_OUT_OF_MEMORY;
    }

    Result result = validateTables(func, host, data);

    if (result != SUCCESS) {
        std::free(readySet);
        return result;
    }

#ifdef _GVM_OPT_PROFILING_
    result = Profiler::init(functionTableSize, rSize);
    if (result != SUCCESS) {
        std::free(readySet);
        return result;
    }
#endif

    workingSet = readySet;

    // Bookend entry so that we don't have to edge case checks for the first entry point
    readySet += sizeof(CallInfo);

    callStackBase      = callStack = (Interpreter::CallInfo*)readySet;
    callStackTop       = &callStackBase[rSize-1];

    frameStackBase     = frameStack = (Scalar*)(readySet + callStackSize) + REDZONE_BUFFER;
    frameStackTop      = &frameStackBase[lSize-1];

    gvmDebug(
        "GVM::Interpreter::init()\n"
        "\tCall Stack          [%p - %p]\n"
        "\tFrame Stack         [%p - %p]\n"
        "\tFunction Table      [%p] : %d entries\n"
        "\tHost Function Table [%p] : %d entries\n"
        "\tGlobal Data Table   [%p] : %d entries\n",
        callStackBase,
        callStackTop,
        frameStackBase,
        frameStackTop,
        functionTable,
        (int)functionTableSize,
        hostFunctionTable,
        (int)hostFunctionTableSize,
        dataTable,
        (int)dataTableSize
    );
    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Interpreter::done() {
#ifdef _GVM_OPT_PROFILING_
    Profiler::dump(stderr);
    Profiler::done();
#endif
    if (workingSet) {
        gvmDebug("GVM::Interpreter::done()\n\tReleased working set\n");
        std::free(workingSet);
        workingSet = 0;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Result Interpreter::validateTables(const FuncInfo* funcTable, const HostCall* hostFuncTable, Scalar** globalData) {

    if (funcTable[0].entryPoint || hostFuncTable[0] || globalData[0]) {
        gvmDebug("Illegal Zero Indexed function\n");
        return INIT_INVALID_FRAME_DEF;
    }

    int numGlobals = 1;
    while (globalData[numGlobals]) {
        if (numGlobals > FuncInfo::MAX_ID) {
            gvmDebug(
                "GVM::Interpreter::validateTables()\n\tGlobal data table too long, exceeded %d entries\n",
                FuncInfo::MAX_ID
            );
            return INIT_TABLE_TOO_BIG;
        }
        ++numGlobals;
    }

    // Host function table is null terminated. Only the overall size is validated.

    int numHostFunctions = 1;
    while (hostFuncTable[numHostFunctions]) {
        // Table Size Check
        if (numHostFunctions > FuncInfo::MAX_ID) {
            gvmDebug(
                "GVM::Interpreter::validateTables()\n\tFunction table too long, exceeded %d entries\n",
                FuncInfo::MAX_ID
            );
            return INIT_TABLE_TOO_BIG;
        }
        ++numHostFunctions;
    }

    // Function table is terminated by a FuncInfo record having a null entry point. We validate the overall size and
    // additionally that the frame specifcation of each record makes sense.

#ifdef _GVM_DEBUGGING_
    const char* illegalSizeMessageTemplate =
        "GVM::Interpreter::validateTables()\n"
        "\tFunction funcTable entry %d has %s size %d\n";
#endif
    int numFunctions = 1;
    while (funcTable[numFunctions].entryPoint) {
        // Table Size Check
        if (numFunctions > FuncInfo::MAX_ID) {
            gvmDebug(
                "GVM::Interpreter::validateTables()\n\tFunction funcTable too long, exceeded %d entries\n",
                FuncInfo::MAX_ID
            );
            return INIT_TABLE_TOO_BIG;
        }

        // Function Total Frame Size
        if (funcTable[numFunctions].frameSize > FuncInfo::MAX_LOCAL_SIZE) {
            gvmDebug(
                illegalSizeMessageTemplate,
                numFunctions,
                "illegal frame",
                (int)funcTable[numFunctions].frameSize
            );
            return INIT_INVALID_FRAME_DEF;
        }

        // Function Return Size
        if (funcTable[numFunctions].returnSize > FuncInfo::MAX_RETURN_SIZE) {
            gvmDebug(
                illegalSizeMessageTemplate,
                numFunctions,
                "illegal return",
                (int)funcTable[numFunctions].returnSize
            );
            return INIT_INVALID_FRAME_DEF;
        }

        // Function Parameter Size
        if (funcTable[numFunctions].paramSize > FuncInfo::MAX_PARAM_SIZE) {
            gvmDebug(
                illegalSizeMessageTemplate,
                numFunctions,
                "illegal param",
                (int)funcTable[numFunctions].paramSize
            );
            return INIT_INVALID_FRAME_DEF;
        }

        // Function Local Data Size
        if (funcTable[numFunctions].localSize > FuncInfo::MAX_LOCAL_SIZE) {
            gvmDebug(
                illegalSizeMessageTemplate,
                numFunctions,
                "illegal local",
                (int)funcTable[numFunctions].localSize
            );
            return INIT_INVALID_FRAME_DEF;
        }

        // Function Size Sanity Checks
        if (
            funcTable[numFunctions].frameSize != (
                funcTable[numFunctions].returnSize +
                funcTable[numFunctions].paramSize +
                funcTable[numFunctions].localSize
            )
        ) {
            gvmDebug(
                illegalSizeMessageTemplate,
                numFunctions,
                "inconsistent frame",
                (int)funcTable[numFunctions].frameSize
            );
            return INIT_INVALID_FRAME_DEF;
        }
        ++numFunctions;
    }

    functionTable         = funcTable;
    functionTableSize     = numFunctions--;
    hostFunctionTable     = hostFuncTable;
    hostFunctionTableSize = numHostFunctions--;
    dataTable             = globalData;
    dataTableSize         = numGlobals--;

    gvmDebug(
        "GVM::Interpreter::validateTables()\n"
        "\tFunction table has %d entries\n"
        "\tHost function table has %d entries\n"
        "\tGlobal data table has %d entries\n",
        (int)numFunctions,
        (int)numHostFunctions,
        (int)numGlobals
    );

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Result Interpreter::invoke(uint16 functionId) {
    Result result = enterFunction(0, functionId);
    if (result == SUCCESS) {
        result = run();
    }
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Result Interpreter::enterFunction(const uint8* returnAddress, uint16 functionId) {
    if (functionId == 0 || functionId > functionTableSize) {
        gvmDebug(
            "GVM::Interpreter::enterFunction(%d) : ID is out of range 1-%d.\n",
            (int)functionId,
            (int)functionTableSize
        );
        return EXEC_ILLEGAL_CALL_ID;
    }
    if (callStack < callStackTop) {
        uint32 currentFrameSize = callStack->frameSize;
        if (frameStack + currentFrameSize > frameStackTop) {
            gvmDebug(
                "GVM::Interpreter::enterFunction(%d) : Frame Stack Overflow.\n",
                (int)functionId
            );
            return EXEC_FRAME_STACK_OVERFLOW;
        }
        frameStack += currentFrameSize;
        ++callStack;
        callStack->returnAddress = returnAddress;
        callStack->functionId    = functionId;
        callStack->frameSize     = functionTable[functionId].frameSize;
        programCounter           = functionTable[functionId].entryPoint;
#ifdef _GVM_DEBUG_FUNCTIONS_
        gvmDebug(
            "GVM::Interpreter::enterFunction(%d) { Address: %p, Size: %d, Return Address: %p, PC Entry: %p, Frame Base: %p }\n",
            (int)functionId,
            frameStack,
            (int)callStack->frameSize,
            returnAddress,
            programCounter,
            frameStack
        );
#endif
        PROFILE_ENTRY(functionId);
        return SUCCESS;
    }

    gvmDebug(
        "GVM::Interpreter::enterFunction(%d) : Call Stack overflowed.\n",
        (int)functionId
    );
    return EXEC_CALL_STACK_OVERFLOW;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Result Interpreter::enterClosure(const uint8* returnAddress, int16 branch, uint8 frameSize) {
    if (callStack < callStackTop) {
        uint32 currentFrameSize = callStack->frameSize;
        if (frameStack + currentFrameSize > frameStackTop) {
            gvmDebug("GVM::Interpreter::enterClosure() : Frame Stack Overflow.\n");
            return EXEC_FRAME_STACK_OVERFLOW;
        }
        frameStack += currentFrameSize;
        ++callStack;
        callStack->returnAddress = returnAddress;
        callStack->functionId    = 0;
        callStack->frameSize     = frameSize;
        programCounter           += branch;
#ifdef _GVM_DEBUG_FUNCTIONS_
        gvmDebug(
            "GVM::Interpreter::enterClosure() { Address: %p, Size: %d, Return Address: %p, PC Entry: %p }\n",
            frameStack,
            (int)callStack->frameSize,
            returnAddress,
            programCounter
        );
#endif
        PROFILE_ENTRY(0);
        return SUCCESS;
    }

    gvmDebug("GVM::Interpreter::enterClosure() : Call Stack overflowed.\n");
    return EXEC_CALL_STACK_OVERFLOW;
}


////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Result Interpreter::exitFunction() {

    if (callStack > callStackBase) {
        const uint8* returnTo = callStack->returnAddress;
#ifdef _GVM_DEBUG_FUNCTIONS_
        int currentId = callStack->functionId;
#endif
        --callStack;
        if (frameStack - callStack->frameSize < frameStackBase) {
            gvmDebug("GVM::Interpreter::exitFunction() : Frame Stack Underflow.\n");
            return EXEC_FRAME_STACK_UNDERFLOW;
        }
        frameStack -= callStack->frameSize;
        programCounter = returnTo;
#ifdef _GVM_DEBUG_FUNCTIONS_
        gvmDebug(
            "GVM::Interpreter::exitFunction(%d) { Return to function:%d, PC Resume: %p }\n",
            currentId,
            (int)callStack->functionId,
            programCounter
        );
#endif
        PROFILE_EXIT();
        return returnTo ? SUCCESS : EXEC_RETURN_TO_HOST;
    }
    return EXEC_CALL_STACK_UNDERFLOW;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Result Interpreter::invokeHostFunction(uint16 functionId) {
    if (functionId == 0 || functionId > hostFunctionTableSize) {
        gvmDebug(
            "GVM::Interpreter::invokeHostFunction(%d) : ID is out of range 1-%d.\n",
            (int)functionId,
            (int)hostFunctionTableSize
        );
        return EXEC_ILLEGAL_CALL_ID;
    }
    if (!hostFunctionTable[functionId]) {
        gvmDebug(
            "GVM::Interpreter::invokeHostFunction(%d) index does not point at a callable function.\n",
            (int)functionId
        );
        return EXEC_ILLEGAL_CALL_ID;
    }
    uint32 currentFrameSize = callStack->frameSize;
    if (frameStack + currentFrameSize > frameStackTop) {
        gvmDebug(
            "GVM::Interpreter::invokeHostFunction(%d) : Frame Stack Overflow.\n",
            (int)functionId
        );
        return EXEC_FRAME_STACK_OVERFLOW;
    }
    frameStack += currentFrameSize;
#ifdef _GVM_DEBUG_FUNCTIONS_
    gvmDebug(
        "GVM::Interpreter::invokeHostFunction(%d) { Stack Address %p }",
        (int)functionId,
        frameStack
    );
#endif
    Result result = hostFunctionTable[functionId](frameStack);
    frameStack -= currentFrameSize;
    return result;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Interpreter::dumpFrame() {
    if (callStack->functionId) {
        const FuncInfo* fInfo = &functionTable[callStack->functionId];
        int top    = fInfo->frameSize;
        Scalar *s  = &frameStack[fInfo->frameSize];
        while (top >= 0) {
            std::fprintf(
                stderr,
                "\t%3d : 0x%08X %12d %g\n",
                top,
                (unsigned)s->u,
                (int)s->i,
                (float)s->f
            );
            --top;
            --s;
        }
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Interpreter::dumpCallStack() {
    std::fprintf(
        stderr,
        "Call Stack Dump\n"
    );
    CallInfo* call  = callStackBase;
    Scalar*   frame = frameStackBase;
    int n = 0;
    while (call <= callStack) {
        int frameSize = (int)call->frameSize;
        std::fprintf(
            stderr,
            "Level %d\n"
            "\tFunction ID    %d\n"
            "\tIndirection[0] %p\n"
            "\tIndirection[1] %p\n"
            "\tReturn Address %p\n"
            "\tFrameSize      %d\n",
            n++,
            (int)call->functionId,
            call->indirection[0],
            call->indirection[1],
            call->returnAddress,
            frameSize
        );
        if (frameSize > 0) {
            std::fprintf(
                stderr,
                "\tFrame Data\n"
            );
            for (int i=0; i<frameSize; i++) {
                std::fprintf(
                    stderr,
                    "\t\t%3d | %p | 0x%08X | %12d | %12g\n",
                    i,
                    &frame[i],
                    (unsigned)frame[i].u,
                    (int)frame[i].i,
                    frame[i].f
                );
            }
            frame += frameSize;
        }
        call++;
    }
}
