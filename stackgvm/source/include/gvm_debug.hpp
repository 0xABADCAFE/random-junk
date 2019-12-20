/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#ifndef _GVM_DEBUG_HPP_
    #define _GVM_DEBUG_HPP_
    #ifdef _GVM_DEBUGGING_
        #define gvmDebug(...) std::fprintf(stderr, __VA_ARGS__)

        #define OPF_S   "#%d"
        #define OPF_L   "{%d}"
        #define OPF_I0  "i0[%u]"
        #define OPF_I1  "i1[%u]"
        #define OPF_I0X "i0[{%d}]"
        #define OPF_I1X "i1[{%d}]"
        #define OPF_R   "{%d}[%u]"
    #else
        #define gvmDebug(...)
    #endif
#endif
