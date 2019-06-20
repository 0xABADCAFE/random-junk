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
uint32*                 Profiler::funcDepth        = 0;
Profiler::StackEntry*   Profiler::profileStackBase = 0;
Profiler::StackEntry*   Profiler::profileStackTop  = 0;
Profiler::StackEntry*   Profiler::profileStack     = 0;

Result Profiler::init(size_t numFunctions, size_t maxCallDepth) {

	size_t funcProfileIndexSize = numFunctions * sizeof(FuncProfile*);
	size_t funcProfileSize      = numFunctions * maxCallDepth * sizeof(FuncProfile);
	size_t funcDepthSize        = numFunctions * sizeof(uint32);
	size_t stackSize            = maxCallDepth * sizeof(StackEntry);

	size_t totalAllocation =
		funcProfileIndexSize +
		funcProfileSize +
		funcDepthSize +
		stackSize;

	uint8* readySet = (uint8*)std::calloc(totalAllocation, sizeof(uint8));

	if (!readySet) {
        gvmDebug("GVM::Profiler::init()\n\tCould not allocate profile data\n");
        return INIT_OUT_OF_MEMORY;
	}

    gvmDebug("GVM::Profiler::init()\n\tAllocated %d bytes for profiling data\n", (int)totalAllocation);

	workingSet = readySet;

	return SUCCESS;
}

void Profiler::done() {
	if (workingSet) {
		std::free(workingSet);
        gvmDebug("GVM::Profiler::done()\n\tFreed profiling data\n");
	}
	workingSet       = 0;
	funcProfile      = 0;
	funcDepth        = 0;
	profileStackBase = 0;
	profileStackTop  = 0;
	profileStack     = 0;
}

void Profiler::enterFunction(uint16 id) {

}

void Profiler::leaveFunction() {

}

#endif

