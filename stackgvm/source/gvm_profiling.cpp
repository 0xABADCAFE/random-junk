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

#ifdef _GVM_OPT_PROFILING_

#undef gvmDebug
#define gvmDebug(...) std::fprintf(stderr, __VA_ARGS__)

void*                   Profiler::workingSet       = 0;
Profiler::FuncProfile** Profiler::funcProfile      = 0;
int32*                  Profiler::funcDepth        = 0;
Profiler::StackEntry*   Profiler::profileStack     = 0;
size_t                  Profiler::numFunctions     = 0;
size_t                  Profiler::maxCallDepth     = 0;

FloatClock              Profiler::timer;

Result Profiler::init(size_t numFunctions, size_t maxCallDepth) {

    size_t funcProfileIndexSize = numFunctions * sizeof(FuncProfile*);
    size_t funcProfileSize      = numFunctions * maxCallDepth * sizeof(FuncProfile);
    size_t funcDepthSize        = numFunctions * sizeof(int32);
    size_t callStackSize        = (maxCallDepth + 1) * sizeof(StackEntry);

    size_t totalAllocation =
        funcProfileIndexSize +
        funcProfileSize +
        funcDepthSize +
        callStackSize +
        1024; // in case of overspill

    uint8* readySet = (uint8*)std::calloc(totalAllocation, sizeof(uint8));

    if (!readySet) {
        gvmDebug("GVM::Profiler::init()\n\tCould not allocate profile data\n");
        return INIT_OUT_OF_MEMORY;
    }

    gvmDebug(
        "GVM::Profiler::init()\n"
        "\tAllocated %d bytes for profiling data\n"
        "\tTotal functions tracked: %d\n"
        "\tMaximum call depth: %d\n",
        (int)totalAllocation,
        (int)numFunctions,
        (int)maxCallDepth
    );

    workingSet  = readySet;
    Profiler::numFunctions = numFunctions;
    Profiler::maxCallDepth = maxCallDepth;

    funcProfile = (FuncProfile**)readySet;

    // The first part of the allocation is the per function profile data. This comprises of N FuncProfile pointers,
    // one per defined function ID (including function ID zero which is used for all closures) that form an index.
    // Each entry points at a row of M FunctionProfile instances, where M is the maximum call depth. These rows
    // follow on immediately from the index.
    FuncProfile* pProfile = (FuncProfile*)(readySet + funcProfileIndexSize);
    for (unsigned i = 0; i < numFunctions; i++) {
        gvmDebug("\tfuncProfile[%u]: %p\n", i, pProfile);
        funcProfile[i] = pProfile;
        pProfile += maxCallDepth;
    }

    // The next part of the allocation is a set of N counters, one per defined function ID (including function ID zero
    // which is used for all closures). This part of the structure counts the effective recursion depth per function
    // and thus the position in the FunctionProfile row that we will be recording our metric to.

    funcDepth = (int32*)(readySet + funcProfileIndexSize + funcProfileSize);
    for (unsigned i = 0; i < numFunctions; i++) {
        funcDepth[i] = -1;
    }
    gvmDebug("\tfuncDepth: %p\n", funcDepth);

    // The final part of the allocation is a set of M StackEntry instances, where M is the maximum call depth. This
    // stack tracks the current function's invocation and it's entry timestamp.

    profileStack = (StackEntry*)(readySet + funcProfileIndexSize + funcProfileSize + funcDepthSize);
    gvmDebug(
        "\tprofileStackBase: %p\n",
        profileStack
    );

    return SUCCESS;
}

void Profiler::done() {

    for (unsigned i=0; i<numFunctions; i++) {
        std::fprintf(
            stderr,
            "Profile for function %u\n",
            i
        );
        for (unsigned j=0; j<maxCallDepth; j++) {
            uint32 totalCount = funcProfile[i][j].callCount;
            if (totalCount > 0) {
                float64 totalCallTime = 1e6 * funcProfile[i][j].incWallTime;
                std::fprintf(
                    stderr,
                    "\t@%4u: %8" FU32 " calls, %12.3f us, avg. %12.3f us\n",
                    j,
                    totalCount,
                    totalCallTime,
                    totalCallTime / totalCount
                );
            }
        }
    }

    if (workingSet) {
        std::free(workingSet);
        gvmDebug("GVM::Profiler::done()\n\tFreed profiling data\n");
    }
    workingSet       = 0;
    funcProfile      = 0;
    funcDepth        = 0;
    profileStack     = 0;
}

void Profiler::enterFunction(uint16 id) {
    ++profileStack;
    profileStack->mark       = timer.elapsed();
    profileStack->functionId = id;
    ++funcProfile[id][++funcDepth[id]].callCount;
}

void Profiler::leaveFunction() {
    uint16 functionId = profileStack->functionId;
    funcProfile[functionId][funcDepth[functionId]--].incWallTime += timer.elapsed() - profileStack->mark;
    --profileStack;
}

#endif

