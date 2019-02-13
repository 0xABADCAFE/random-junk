/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#ifndef _GVM_DEBUG_HPP_
    #define _GVM_DEBUG_HPP_
    #ifdef _GVM_DEBUGGING_
        #define gvmDebug(...) std::fprintf(stderr, __VA_ARGS__)
    #else
        #define gvmDebug(...)
    #endif
#endif
