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

void*                   Profiler::workingSet       = 0;
Profiler::FuncProfile** Profiler::funcProfile      = 0;
int32*                  Profiler::funcDepth        = 0;
Profiler::StackEntry*   Profiler::profileStack     = 0;
size_t                  Profiler::numFunctions     = 0;
size_t                  Profiler::maxCallDepth     = 0;

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Result Profiler::init(const size_t numFunctions, const size_t maxCallDepth) {

    size_t funcProfileIndexSize = numFunctions * sizeof(FuncProfile*);
    size_t funcProfileSize      = numFunctions * maxCallDepth * sizeof(FuncProfile);
    size_t funcDepthSize        = numFunctions * sizeof(int32);
    size_t callStackSize        = (maxCallDepth + 2) * sizeof(StackEntry);

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

    profileStack = (StackEntry*)(
        readySet +
        funcProfileIndexSize +
        funcProfileSize +
        funcDepthSize +
        sizeof(StackEntry)
    );
    gvmDebug(
        "\tprofileStackBase: %p\n",
        profileStack
    );

    return SUCCESS;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::done() {
    if (workingSet) {
        //calibrate();
        std::free(workingSet);
        gvmDebug("GVM::Profiler::done()\n\tFreed profiling data\n");
    }
    workingSet       = 0;
    funcProfile      = 0;
    funcDepth        = 0;
    profileStack     = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::dump(std::FILE* out) {
    // We take the time of the first function entered (at depth zero) to represent the total time for percentages.
    float64 percentTotalDivisor = 1e-5 * funcProfile[profileStack[0].functionId][0].incWallTime;

    for (unsigned i = 0; i < numFunctions; i++) {
        std::fprintf(
            out,
            "Walltime Profile for function %u\n"
            "+-------+----------+---------------+--------+---------------+---------------+---------------+\n"
            "| Depth |    Calls |  Tot Inc (us) |  %% Tot |  Avg Inc (us) |  Tot Exc (us) |  Avg Exc (us) |\n"
            "+-------+----------+---------------+--------+---------------+---------------+---------------+\n",
            i
        );
        for (unsigned j = 0; j < maxCallDepth; j++) {
            FuncProfile& profile = funcProfile[i][j];
            uint32 totalCount = profile.callCount;
            if (totalCount > 1) {
                float64 totalIncWallTime = 1e-3 * profile.incWallTime;
                float64 totalExcWallTime = 1e-3 * (profile.incWallTime - profile.childWallTime);
                std::fprintf(
                    out,
                    "| %5u | %8" FU32 " | %13.3f | %6.2f | %13.3f | %13.3f | %13.3f |\n",
                    j,
                    totalCount,
                    totalIncWallTime,
                    totalIncWallTime / percentTotalDivisor,
                    totalIncWallTime / totalCount,
                    totalExcWallTime,
                    totalExcWallTime / totalCount
                );
            } else if (totalCount == 1) {
                float64 totalIncWallTime = 1e-3 * profile.incWallTime;
                float64 totalExcWallTime = 1e-3 * (profile.incWallTime - profile.childWallTime);
                std::fprintf(
                    out,
                    "| %5u | %8" FU32 " | %13.3f | %6.2f | %13s | %13.3f | %13s |\n",
                    j,
                    totalCount,
                    totalIncWallTime,
                    totalIncWallTime / percentTotalDivisor,
                    "-",
                    totalExcWallTime,
                    "-"
                );
            } else {
                break;
            }
        }
        std::fprintf(
            out,
            "+-------+----------+---------------+--------+---------------+---------------+---------------+\n\n"
        );
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::enterFunction(const uint16 id) {
    profileStack->mark       = NanoTime::mark();
    profileStack->childAccum = 0;
    profileStack->functionId = id;
    ++funcProfile[id][++funcDepth[id]].callCount;
    ++profileStack;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::leaveFunction() {
    --profileStack;
    uint16          functionId  = profileStack->functionId;
    NanoTime::Value incWallTime = NanoTime::mark() - profileStack->mark;
    FuncProfile& profile        = funcProfile[functionId][funcDepth[functionId]--];
    profile.incWallTime        += incWallTime;
    profile.childWallTime      += profileStack->childAccum;

    // Update parent child accumulator about the time we spent here. This looks scary but it's why we allocate one slot
    // above and below the stack so the -1 has no bad effect.
    profileStack[-1].childAccum += incWallTime;
}

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

void Profiler::calibrate() {
    NanoTime::Value start = NanoTime::mark();
    for (int i=0; i<100000; i++) {
        enterFunction(0);
        leaveFunction();
    }
    NanoTime::Value end   = NanoTime::mark();
    std::fprintf(
        stderr,
        "Profiling overhead per function: %.3f us\n",
        1e-8 * (end - start)
    );
}

#endif

