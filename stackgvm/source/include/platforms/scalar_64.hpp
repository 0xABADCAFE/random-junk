#ifndef _GVM_SCALAR_64_HPP
    #define _GVM_SCALAR_64_HPP  
    
namespace GVM {

    union Scalar;
        
    typedef Scalar* ScalarRef;
   
    #define SCALAR_I int64
    #define SCALAR_U uint64
    #define SCALAR_F float64
    
    /**
     * Scalar
     *
     * Basic machine datatype.
     */
    union Scalar {
        int64     i;
        uint64    u;
        float64   f;
        ScalarRef a;
        Scalar(int i)   : i(i) {}
        Scalar(float f) : f(f) {}
    };
};

#endif
