/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#ifndef _GVM_HOST_MACHINE_HPP_
    #define _GVM_HOST_MACHINE_HPP_
    #include <cstdlib>
    #ifdef __LP64__
        #error 64-bit targets are not currently supported
    #endif

    #define _GVM_HOST_BIG    0
    #define _GVM_HOST_LITTLE 1

    // change this for other systems
    #define _GVM_HOST_AMIGAOS3_68K     1
    #define _GVM_HOST_AMIGAOS3_WARPUP  2
    #define _GVM_HOST_AMIGAOS4_PPC     3
    #define _GVM_HOST_MORPHOS_PPC      4
    #define _GVM_HOST_LINUX_INTEL_32   5

    // Target sanity checks
    #if (_GVM_HOST_OS == _GVM_HOST_AMIGAOS3_68K)
        #ifdef __PPC__
            #warning PowerPC directive set for AmigaOS 680x0 target, switching to WarpOS
            #undef _GVM_HOST_OS
            #define _GVM_HOST_OS _GVM_HOST_AMIGAOS3_WARPUP
        #endif
    #endif

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

    // target specific class implementations
    #if (_GVM_HOST_OS == _GVM_HOST_LINUX_INTEL_32)
        #define _GVM_HOST_ENDIAN _GVM_HOST_LITTLE
        #include "platforms/machine_linux_generic.hpp"
    //#elif (_GVM_HOST_OS == _GVM_HOST_AMIGAOS3_68K)
    //    #include "platforms/machine_amiga_68k.hpp"
    //#elif (_GVM_HOST_OS == _GVM_HOST_AMIGAOS3_WARPUP)
    //    #include "platforms/machine_amiga_wos.hpp"
    //#elif (_GVM_HOST_OS == _GVM_HOST_AMIGAOS4_PPC)
    //    #include "platforms/machine_amiga_os4.hpp"
    //#elif (_GVM_HOST_OS == _GVM_HOST_MORPHOS_PPC)
    //    #include "platforms/machine_amiga_mos.hpp"
    #else
        #error Unrecognised Machine
    #endif

#endif

