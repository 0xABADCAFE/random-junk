#ifndef _GVM_SCALAR_HPP
    #define _GVM_SCALAR_HPP
    
namespace GVM {
    
    /**
     * Scalar
     *
     * Basic GVM machine word type. Union of signed, unsigned, address and floating point value. This is a forwards reference
     * to a varying implementation depending on the host platform, in particular whether it is 32 or 64-bit. Member fields are:
     *
     * .i : Signed integer
     * .u : Unsigned integer
     * .f : Floating point
     * .a : Address reference (location of another Scalar instance) 
     * 
     */
    union Scalar;
};
    #ifdef __LP64__
        #ifdef _GVM_OPT_64BIT_PURE_
            // Pure 64-bit native implementation
            #include "platforms/scalar_64.hpp";
        #else
            // 32-bit GVM interpreter running on a 64-bit host using a "short pointer", single large memory allocation model
            #include "platforms/scalar_32_on_64.hpp";
        #endif
    #else
        // 
        #include "platforms/scalar_32.hpp";
    #endif

#endif
