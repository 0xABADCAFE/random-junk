#ifndef _AEK_TYPES_HPP_
    #define _AEK_TYPES_HPP

    #ifdef __LP64__
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
    #else
        // 32-bit typedefs
        typedef signed char int8;
        typedef signed short int int16;
        typedef signed long int int32;
        typedef signed long long int int64;
        typedef unsigned char uint8;
        typedef unsigned short int uint16;
        typedef unsigned long int uint32;
        typedef unsigned long long int uint64;
        typedef float float32;
        typedef double float64;

        // Formatting Templates
        #define FS16 "hd"
        #define FU16 "hu"
        #define FS32 "ld"
        #define FU32 "lu"
        #define FS64 "lld"
        #define FU64 "llu"
    #endif

#endif
