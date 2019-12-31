#ifndef _GVM_SCALAR_32_HPP
    #define _GVM_SCALAR_32_HPP
    
namespace GVM {

    /**
     * Scalar definition for pure 32-bit GVM on 32-bit hosts.
     */
    union Scalar;

    typedef int32   ScalarI;
    typedef uint32  ScalarU;
    typedef float32 ScalarF;
    typedef Scalar* ScalarA;
    
    DECLARE_SCALAR
};

#endif
