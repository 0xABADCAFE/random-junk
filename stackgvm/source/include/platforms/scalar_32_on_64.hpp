#ifndef _GVM_SCALAR_32_ON_64_HPP
    #define _GVM_SCALAR_32_ON_64_HPP

namespace GVM {

    /**
     * Scalar definition for 32-bit GVM on 64-bit host. This requires that the ScalarA type is no longer a pointer but a 32-bit proxy with pointer
     * access semantics.
     */
    union Scalar;

    typedef int32   ScalarI;
    typedef uint32  ScalarU;
    typedef float32 ScalarF;

    /**
     * ScalarA - Represents the address of a Scalar instance within some 32-bit confined block within the 64-bit host memory space.
     *
     * Cannot have a constructor as this is used within the Scalar union definition. A straight derivative class ScalarAddress is defined for the
     * express purpose of instantiation.
     */
    class ScalarA {
        friend class ScalarMemory;

        private:
            /**
             * Global base address for the single Scalar vector allocation
             */
            static Scalar* base;

        protected:
            /**
             * Offset of the Scalar from base referenced by this instance
             */
            uint32 offset;

        public:
            /**
             * Reference Operator
             *
             * @return Scalar*
             */
            Scalar* operator->();

            /**
             * Dereference Operator
             *
             * @return Scalar&
             */
            Scalar& operator*();

            /**
             * Array subscript operator
             *
             * @param const int
             * @return Scalar&
             */
            Scalar& operator[](const int);

            /**
             * Increment Prefix
             *
             * @return ScalarA& fluent
             */
            ScalarA& operator++() {
                ++offset;
                return *this;
            };

            /**
             * Increment Postfix
             *
             * @return ScalarA& fluent
             */
            ScalarA& operator++(int) {
                ++offset;
                return *this;
            };

            /**
             * Decrement Prefix
             *
             * @return ScalarA& fluent
             */
            ScalarA& operator--() {
                --offset;
                return *this;
            };

            /**
             * Decrement Postfix
             *
             * @return ScalarA& fluent
             */
            ScalarA& operator--(int) {
                --offset;
                return *this;
            };

            /**
             * Literal assignment operator
             *
             * @param uint32 x
             * @return ScalarA& fluent
             */
            ScalarA& operator=(uint32 x) {
                offset = x;
                return *this;
            };

    };

    /**
     * ScalarAddress
     *
     * Constructable extension of ScalarA for external use
     */
    class ScalarAddress : public ScalarA {
        public:
            ScalarAddress(uint32 address) {
                offset = address;
            }
    };

    DECLARE_SCALAR

    /**
     * ScalarA reference operator implementation (requires Scalar is fully defined)
     */
    inline Scalar* ScalarA::operator->() {
        return &base[offset];
    }

    /**
     * ScalarA dereference operator implementation (requires Scalar is fully defined)
     */
    inline Scalar& ScalarA::operator*() {
        return base[offset];
    }

    /**
     * ScalarA dereference operator implementation (requires Scalar is fully defined)
     */
    Scalar& ScalarA::operator[](const int p) {
        return base[offset + p];
    }
};

#endif
