#ifndef _GVM_SCALAR_64_HPP
    #define _GVM_SCALAR_64_HPP  
    
namespace GVM {

    /**
     * Scalar definition for pure 64-bit GVM on 64-bit hosts.
     */
    union Scalar;

    typedef int64   ScalarI;
    typedef uint64  ScalarU;
    typedef float64 ScalarF;
    typedef Scalar* ScalarA;
       
    DECLARE_SCALAR
};

#endif
