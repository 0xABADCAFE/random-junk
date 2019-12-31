#ifndef _GVM_SCALAR_32_ON_64_HPP
    #define _GVM_SCALAR_32ON_64_HPP
    
namespace GVM {

    union Scalar;
    
    #define SCALAR_I int32
    #define SCALAR_U uint32
    #define SCALAR_F float32
 
    class ScalarRef {
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
             * @return ScalarRef& fluent
             */
            ScalarRef& operator++() {
                ++offset;
                return *this;
            };

            /**
             * Increment Postfix
             *          
             * @return ScalarRef& fluent
             */
            ScalarRef& operator++(int) {
                ++offset;
                return *this;
            };
    
            /**
             * Decrement Prefix
             * 
             * @return ScalarRef& fluent
             */
            ScalarRef& operator--() {
                --offset;
                return *this;
            };

            /**
             * Decrement Postfix
             *           
             * @return ScalarRef& fluent
             */
            ScalarRef& operator--(int) {
                --offset;
                return *this;
            };
            
            /**
             * Literal assignment operator
             * 
             * @param uint32 x
             * @return ScalarRef& fluent
             */
            ScalarRef& operator=(uint32 x) {
                offset = x;
                return *this;
            };

    };

    /**
     * ScalarPtr
     * 
     * Constructable extension of ScalarRef for external use
     */
    class ScalarPtr : public ScalarRef {
        public:
            ScalarPtr(uint32 address) {
                offset = address;
            }
    };
    
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
