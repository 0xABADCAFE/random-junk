#ifndef _GVM_SCALAR_32_ON_64_HPP
    #define _GVM_SCALAR_32_ON_64_HPP
    
namespace GVM {

    union Scalar;

    typedef int32   ScalarI;
    typedef uint32  ScalarU;
    typedef float32 ScalarF;
    
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
