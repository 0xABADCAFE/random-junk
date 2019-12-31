#ifndef _GVM_SCALAR_32_HPP
    #define _GVM_SCALAR_32_HPP
    
namespace GVM {

    union Scalar;

    typedef Scalar* ScalarRef;
    
    #define SCALAR_I int32
    #define SCALAR_U uint32
    #define SCALAR_F float32
    
    /**
     * Scalar
     *
     * Basic machine datatype.
     */
    union Scalar {
        int32     i;
        uint32    u;
        float32   f;
        ScalarRef a;
        Scalar(int i)   : i(i) {}
        Scalar(float f) : f(f) {}
    };
};

#endif
