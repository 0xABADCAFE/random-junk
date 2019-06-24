#ifndef _GVM_PROFILING_HPP_
    #define _GVM_PROFILING_HPP_
namespace GVM {
    #ifdef _GVM_OPT_PROFILING_
    class Profiler {
        public:
            struct FuncProfile {
                uint32  callCount;
                float32 incWallTime;
                float32 childWallTime;
                float32 minIncWallTime;
                float32 maxIncWallTime;
            };

        public:
            static Result init(const size_t numFunctions, const size_t maxCallDepth);
            static void done();
            static void dump(std::FILE* to);
            static void enterFunction(const uint16 id);
            static void leaveFunction();

        private:
            struct StackEntry {
                float32 mark;
                float32 childAccum;
                uint16  functionId;
                uint16  reserved;
            };

            // All the profiling data is allocated together
            static void*         workingSet;

            // Tracking per function, per recursion depth
            static FuncProfile** funcProfile;

            // Current recursion depth of each function
            static int32*        funcDepth;
            static StackEntry*   profileStack;
            static size_t        numFunctions;
            static size_t        maxCallDepth;

            static FloatClock    timer;
    };
        #define PROFILE_ENTRY(f)    Profiler::enterFunction(f)
        #define PROFILE_EXIT()      Profiler::leaveFunction()
        #define PROFILE_DUMP(to)    Profiler::dump((to))
    #else
        #define PROFILE_ENTRY(f)
        #define PROFILE_EXIT()
        #define PROFILE_DUMP(to)
    #endif
};
#endif
