/**
 * Scalar64 test
 */
#ifndef __LP64__
#error Scalar64 must be compiled 64-bit
#endif

#include <cstdio>

// 64-bit typedefs
typedef signed char int8;
typedef signed short int int16;
typedef signed int int32;
typedef signed long int int64;
typedef unsigned char uint8;
typedef unsigned short int uint16;
typedef unsigned int uint32;
typedef unsigned long int uint64;
typedef float float32;
typedef double float64;

// Formatting Templates
#define FS16 "hd"
#define FU16 "hu"
#define FS32 "d"
#define FU32 "u"
#define FS64 "ld"
#define FU64 "lu"

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

union Scalar;
class ScalarMemory;

/**
 * ScalarRef32
 * 
 * Represents the 32-bit GVM::Scalar Address for a 64-bit host.
 * Does not have a constructor so that it can be used in the Scalar union type.
 */
class ScalarRef32 {
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
         * @return ScalarRef32& fluent
         */
        ScalarRef32& operator++() {
            ++offset;
            return *this;
        };

        /**
         * Increment Postfix
         *          
         * @return ScalarRef32& fluent
         */
        ScalarRef32& operator++(int) {
            ++offset;
            return *this;
        };
 
        /**
         * Decrement Prefix
         * 
         * @return ScalarRef32& fluent
         */
        ScalarRef32& operator--() {
            --offset;
            return *this;
        };

        /**
         * Decrement Postfix
         *           
         * @return ScalarRef32& fluent
         */
        ScalarRef32& operator--(int) {
            --offset;
            return *this;
        };
        
        /**
         * Literal assignment operator
         * 
         * @param uint32 x
         * @return ScalarRef32& fluent
         */
        ScalarRef32& operator=(uint32 x) {
            offset = x;
            return *this;
        };

};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * ScalarPtr
 * 
 * Constructable extension of ScalarRef32 for external use
 */
class ScalarPtr : public ScalarRef32 {
    public:
        ScalarPtr(uint32 address) {
            offset = address;
        }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * Scalar
 * 
 * Basic GVM 32-bit machine type. Can represent an integer, float or memory location. For 64-bit hosts, the memory location is a ScalarRef32 rather than an
 * actual pointer.
 */
union Scalar {
    int32   i;
    uint32  u;
    float32 f;
    ScalarRef32 a;
    Scalar(int i = 0) : i(i) {}
    Scalar(float f)   : f(f) {}
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * ScalarRef32 reference operator implementation (requires Scalar is fully defined)
 */
inline Scalar* ScalarRef32::operator->() {
    return &base[offset];
}

/**
 * ScalarRef32 dereference operator implementation (requires Scalar is fully defined)
 */
inline Scalar& ScalarRef32::operator*() {
    return base[offset];
}

/**
 * ScalarRef32 dereference operator implementation (requires Scalar is fully defined)
 */
Scalar& ScalarRef32::operator[](const int p)
{
    return base[offset + p];
}

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

/**
 * ScalarMemory
 */
class ScalarMemory {
    private:
        /**
         * Total size (count) of the Scalar allocation
         */
        static uint32  size;

    public:
        /**
         * Initialise the Scalar Memory area
         * 
         * @param uint32 allocSize
         */
        static void init(uint32 allocSize) {
            ScalarRef32::base = new Scalar[allocSize];
            size = allocSize;
            std::printf("Allocated array of %" FU32 " Scalar at host address %p\n", size, ScalarRef32::base);
        }

        /**
         * Dump the contents of the Scalar Memory area
         * 
         * @param uint32 allocSize
         */
        static void dump() {
            if (ScalarRef32::base) {
                for (uint32 u = 0; u < size; u++) {
                std::printf("%4" FU32 ": 0x%08X\n", u, ScalarRef32::base[u].u);
                }
            }
        }

        /**
         * Finalise the Scalar memory area
         */
        static void done() {
            if (ScalarRef32::base) {
                delete[] ScalarRef32::base;
                std::puts("Released scalar array");
            }
            size = 0;
        }
};

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

Scalar* ScalarRef32::base = 0;
uint32  ScalarMemory::size = 0;

///////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////

int main() {
    
    std::printf(
        "sizeof(Scalar)      : %d\n"
        "sizeof(ScalarRef32) : %d\n"
        "sizeof(ScalarPtr)   : %d\n",
        (int)sizeof(Scalar),
        (int)sizeof(ScalarRef32),
        (int)sizeof(ScalarPtr)
    );
    
    // Initialise a region of Scalar memory big enough to hold 4 Scalar entries.
    ScalarMemory::init(8);
    
    // Initialise a new ScalarPtr pointing at Scalar address zero
    ScalarPtr pScalar(0);
    
    // Test the pointer behaviours of ScalarPtr
    
    // Assign address 1 to the Scalar at address zero
    // Expected Scalar at address 0 : 0x00000001
    // Expected Scalar at address 1-7 : 0x00000000
    std::puts("Test 1: 32-bit reference assignment via ->");
    pScalar->a = 1;
    ScalarMemory::dump();

    
    // Write to the Scalar pointed to by the Scalar at address zero
    // Expected Scalar at address 0 : 0x00000001
    // Expected Scalar at address 1 : 0xDEADBEEF
    // Expected Scalar at address 2-7 : 0x00000000
    std::puts("Test 2: 32-bit integer assignment via indirect reference");
    pScalar->a->u = 0xDEADBEEF;
    ScalarMemory::dump();
    
    // Increment the address held in the Scalar at address zero and write (prefix)
    // Expected Scalar at address 0 : 0x00000002
    // Expected Scalar at address 1 : 0xDEADBEEF
    // Expected Scalar at address 2 : 0x01234567
    // Expected Scalar at address 3-7 : 0x00000000
    std::puts("Test 3: 32-bit integer assignment via indirect reference with pre increment");
    (++pScalar->a)->u = 0x01234567;
    ScalarMemory::dump();
    
    // Increment the address held in the Scalar at address zero and write (postfix)
    // Expected Scalar at address 0 : 0x00000003
    // Expected Scalar at address 1 : 0xDEADBEEF
    // Expected Scalar at address 2 : 0x01234567
    // Expected Scalar at address 3 : 0x89ABCDEF
    // Expected Scalar at address 4-7 : 0x00000000
    std::puts("Test 4: 32-bit integer assignment via indirect reference with post increment");
    (pScalar->a++)->u = 0x89ABCDEF;
    ScalarMemory::dump();

    // Incremenent the address held in the Scalar at address zero, dereference and write
    // Expected Scalar at address 0 : 0x00000004
    // Expected Scalar at address 1 : 0xDEADBEEF
    // Expected Scalar at address 2 : 0x01234567
    // Expected Scalar at address 3 : 0x89ABCDEF
    // Expected Scalar at address 4 : 0x45454545
    // Expected Scalar at address 5-7 : 0x00000000
    std::puts("Test 5: 32-bit integer assignment via indirect reference with * dereference step");
    (*(pScalar->a++)).u = 0x45454545;
    ScalarMemory::dump();
    
    // Array subscript and write
    // Incremenent the address held in the Scalar at address zero, dereference and write
    // Expected Scalar at address 0 : 0x00000004
    // Expected Scalar at address 1 : 0xDEADBEEF
    // Expected Scalar at address 2 : 0x01234567
    // Expected Scalar at address 3 : 0x89ABCDEF
    // Expected Scalar at address 4 : 0x45454545
    // Expected Scalar at address 5 : 0xABADCAFE
    // Expected Scalar at address 6-7 : 0x00000000
    std::puts("Test 6: 32-bit integer assignment via [] subscripting");
    pScalar[5].u = 0xABADCAFE;    
    ScalarMemory::dump();
    
    // Repoint pointer at memory top, decrement and write (prefix)
    // Expected Scalar at address 0 : 0x00000004
    // Expected Scalar at address 1 : 0xDEADBEEF
    // Expected Scalar at address 2 : 0x01234567
    // Expected Scalar at address 3 : 0x89ABCDEF
    // Expected Scalar at address 4 : 0x45454545
    // Expected Scalar at address 5 : 0xABADCAFE
    // Expected Scalar at address 6 : 0x00000000
    // Expected Scalar at address 7 : 0x10101010
    std::puts("Test 7: 32-bit integer assignment via indirect reference with pre decrement");    
    pScalar = 8;
    (--pScalar)->u = 0x10101010;
    ScalarMemory::dump();
    
    // Repoint pointer at memory top, decrement and write (prefix)
    // Expected Scalar at address 0 : 0x00000004
    // Expected Scalar at address 1 : 0xDEADBEEF
    // Expected Scalar at address 2 : 0x01234567
    // Expected Scalar at address 3 : 0x89ABCDEF
    // Expected Scalar at address 4 : 0x45454545
    // Expected Scalar at address 5 : 0xABADCAFE
    // Expected Scalar at address 6 : 0x01010101
    // Expected Scalar at address 7 : 0x10101010
    std::puts("Test 7: 32-bit integer assignment via indirect reference with post decrement");    
    (pScalar--)->u = 0x01010101;
    ScalarMemory::dump();
    
    ScalarMemory::done();
    return 0;
}
