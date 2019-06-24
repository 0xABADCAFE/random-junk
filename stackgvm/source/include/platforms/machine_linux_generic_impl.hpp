/**
 * TYTLGVM
 *
 * Twenty Years Too Late Game Virtual Machine
 */

struct timezone FloatClock::tz = { 0, 0 };

float32 FloatClock::elapsed() {
    timeval current;
    gettimeofday(&current, &tz);
    return (float32)(current.tv_sec - mark.tv_sec) + (1e-6f * (current.tv_usec - mark.tv_usec));
}
