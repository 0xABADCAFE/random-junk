#ifndef _GVM_SCALAR_32_HPP
    #define _GVM_SCALAR_32_HPP
    
namespace GVM {

    union Scalar;

    typedef int32   ScalarI;
    typedef uint32  ScalarU;
    typedef float32 ScalarF;
    typedef Scalar* ScalarA;
    
    /**
     * Scalar
     *
     * Basic machine datatype.
     */
    union Scalar {
        ScalarI i;
        ScalarU u;
        ScalarF f;
        ScalarA a;
        Scalar(int i)   : i(i) {}
        Scalar(float f) : f(f) {}
    };
};

#endif
