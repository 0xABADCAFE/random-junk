/**
 * TYTLGVM
 *
 * Twenty Years Too Late Game Virtual Machine
 */

#include <sys/time.h>
#include <time.h>

namespace GVM {

    /**
     * FloatClock
     *
     * Measures wall time in 32-bit floating point seconds.
     */
    class FloatClock {
        private:
            static struct timezone  tz;
            timeval mark;

        public:
            void set() {
                gettimeofday(&mark, &tz);
            }

            float32 elapsed();

            FloatClock() {
                set();
            }
    };

    // High precision timing
    class NanoTime {

        public:
            typedef uint64 Value;
            static Value mark();
    };
}

