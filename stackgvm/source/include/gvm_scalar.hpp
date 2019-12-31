#ifndef _GVM_SCALAR_HPP
    #define _GVM_SCALAR_HPP

namespace GVM {

    /**
     * Scalar
     *
     * Basic GVM machine word type. Union of signed, unsigned, address and floating point value. This is a forwards reference
     * to a varying implementation depending on the host platform, in particular whether it is 32 or 64-bit. Member fields are:
     *
     * ScalarI .i : Signed integer
     * ScalarU .u : Unsigned integer
     * ScalarF .f : Floating point
     * ScalarA .a : Address reference (dereferencable location of another Scalar instance)
     *
     */
    union Scalar;
};

    /**
     * Macro to ensure single definition of Scalar structure and field ordering
     */
    #define DECLARE_SCALAR union Scalar { \
        ScalarI i; \
        ScalarU u; \
        ScalarF f; \
        ScalarA a; \
        Scalar(int i)   : i(i) {} \
        Scalar(float f) : f(f) {} \
    };

    #ifdef __LP64__
        #ifdef _GVM_OPT_64BIT_PURE_
            // Pure 64-bit native implementation
            #include "platforms/scalar_64.hpp"
        #else
            // 32-bit GVM interpreter running on a 64-bit host using a "short pointer", single large memory allocation model
            #include "platforms/scalar_32_on_64.hpp"
        #endif
    #else
        //
        #include "platforms/scalar_32.hpp"
    #endif

namespace GVM {

    /**
     * ScalarAllocator
     *
     * (Interface for) Memory allocator for Scalar.
     */
    class ScalarAllocator {
        public:
            virtual ScalarA alloc(uint32 size)  = 0;
            virtual void free(ScalarA address)  = 0;
            virtual ~ScalarAllocator()          = 0;
    };
};

#endif
