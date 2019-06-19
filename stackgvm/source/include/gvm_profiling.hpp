#ifndef _GVM_PROFILING_HPP_
    #define _GVM_PROFILING_HPP_
namespace GVM {
	#ifdef _GVM_OPT_PROFILING_
    class Profiler {
        public:
            struct FuncProfile {
                uint32  callCount;
                float32 incWallTime;
            };

        public:
            static Result init(size_t numFunctions, size_t maxCallDepth);
            static void done();
            static void enterFunction(uint16 id);
            static void leaveFunction();

        private:
            struct StackEntry {
                float32 mark;
                uint16  functionId;
                uint16  reserved;
            };

			// All the profiling data is allocated together
			static void*         workingSet;

            // Tracking per function, per recursion depth
            static FuncProfile** funcProfile;

            // Current recursion depth of each function
            static uint32*       funcDepth;
            static StackEntry*   profileStackBase;
            static StackEntry*   profileStackTop;
            static StackEntry*   profileStack;

    };

    #else

	#endif
};
#endif