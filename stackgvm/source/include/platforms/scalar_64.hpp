#ifndef _GVM_SCALAR_64_HPP
    #define _GVM_SCALAR_64_HPP  
    
namespace GVM {

    union Scalar;

    typedef int64   ScalarI;
    typedef uint64  ScalarU;
    typedef float64 ScalarF;
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
