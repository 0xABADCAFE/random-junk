#ifndef _GVM_SCALAR_HPP
    #define _GVM_SCALAR_HPP

namespace GVM {

    union Scalar;

    /**
     * Scalar
     *
     * Basic machine datatype.
     */

    #ifdef __LP64__
        #ifdef _GVM_OPT_64BIT_PURE_

            #define SCALAR_I int64
            #define SCALAR_U uint64
            #define SCALAR_F float64
    union Scalar {
        int64   i;
        uint64  u;
        float64 f;
        Scalar* a;
        Scalar(int i)   : i(i) {}
        Scalar(float f) : f(f) {}
    };
        #else
            #error "No 32bit on 64-bit target definition yet"
        #endif
    #else
        #define SCALAR_I int32
        #define SCALAR_U uint32
        #define SCALAR_F float32

    union Scalar {
        int32   i;
        uint32  u;
        float32 f;
        Scalar* a;
        Scalar(int i)   : i(i) {}
        Scalar(float f) : f(f) {}
    };
    #endif
};

#endif
