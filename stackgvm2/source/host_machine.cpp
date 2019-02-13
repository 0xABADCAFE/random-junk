/**
 * TOYTL - GVM
 *
 * Twenty Odd Years Too Late Game Virtual Machine
 */

#include "include/gvm_core.hpp"

using namespace GVM;

#if (_VM_HOST_OS == _VM_HOST_LINUX_INTEL_32)
    #include "include/platforms/machine_linux_generic_impl.hpp"
//#elif (_VM_HOST_OS == _VM_HOST_AMIGAOS3_68K)
//    #include "include/platforms/machine_amiga_68k_impl.hpp"
//#elif (_VM_HOST_OS == _VM_HOST_AMIGAOS3_WARPUP)
//    #include "include/platforms/machine_amiga_wos_impl.hpp"
//#elif (_VM_HOST_OS == _VM_HOST_AMIGAOS4_PPC)
//    #include "include/platforms/machine_amiga_os4_impl.hpp"
//#elif (_VM_HOST_OS == _VM_HOST_MORPHOS_PPC)
//    #include "include/platforms/machine_amiga_mos_impl.hpp"
#endif

