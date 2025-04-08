#ifndef __CPUID_H__
#define __CPUID_H__

//TODO: custom stdint
#include <stdint.h>

//=================CPUID_VENDOR=================
#define CPUID_VENDOR_INTEL  "GenuineIntel"
#define CPUID_VENDOR_AMD    "AuthenticAMD"

//================CPUID_CPU_INFO================
#define CPUID_CPU_INFO_EAX_STEPPING_MASK    0xF
#define CPUID_CPU_INFO_EAX_MODEL_MASK       0xF  << 4
#define CPUID_CPU_INFO_EAX_FAMILY_MASK      0xF  << 8
#define CPUID_CPU_INFO_EAX_TYPE_MASK        0x3  << 12
#define CPUID_CPU_INFO_EAX_EXT_MODEL_MASK   0xF  << 16
#define CPUID_CPU_INFO_EAX_EXT_FAMILY_MASK  0xFF << 20

#define CPUID_CPU_INFO_EBX_BRAND_INDEX  0xFF
#define CPUID_CPU_INFO_EBX_CFLUSH_SIZE  0xFF << 8
#define CPUID_CPU_INFO_EBX_MAX_LOGPROC  0xFF << 16
#define CPUID_CPU_INFO_EBX_INIT_APIC_ID 0xFF << 25

#define CPUID_CPU_INFO_ECX_SSE3          1 << 0
#define CPUID_CPU_INFO_ECX_PCLMULQDQ     1 << 1
#define CPUID_CPU_INFO_ECX_DTES64        1 << 2
#define CPUID_CPU_INFO_ECX_MONITOR       1 << 3
#define CPUID_CPU_INFO_ECX_DS_CPL        1 << 4
#define CPUID_CPU_INFO_ECX_VMX           1 << 5
#define CPUID_CPU_INFO_ECX_SMX           1 << 6
#define CPUID_CPU_INFO_ECX_EIST          1 << 7
#define CPUID_CPU_INFO_ECX_TM2           1 << 8
#define CPUID_CPU_INFO_ECX_SSSE3         1 << 9
#define CPUID_CPU_INFO_ECX_CNXT_ID       1 << 10
#define CPUID_CPU_INFO_ECX_SDBG          1 << 11
#define CPUID_CPU_INFO_ECX_FMA           1 << 12
#define CPUID_CPU_INFO_ECX_CMPXCHG16B    1 << 13
#define CPUID_CPU_INFO_ECX_XTPR_UC       1 << 14
#define CPUID_CPU_INFO_ECX_PDCM          1 << 15
//bit 16 is reserved
#define CPUID_CPU_INFO_ECX_PCID          1 << 17
#define CPUID_CPU_INFO_ECX_DCA           1 << 18
#define CPUID_CPU_INFO_ECX_SSE4_1        1 << 19
#define CPUID_CPU_INFO_ECX_SSE4_2        1 << 20
#define CPUID_CPU_INFO_ECX_X2APIC        1 << 21
#define CPUID_CPU_INFO_ECX_MOVBE         1 << 22
#define CPUID_CPU_INFO_ECX_POPCNT        1 << 23
#define CPUID_CPU_INFO_ECX_TSC_DEADLINE  1 << 24
#define CPUID_CPU_INFO_ECX_AESNI         1 << 25
#define CPUID_CPU_INFO_ECX_XSAVE         1 << 26
#define CPUID_CPU_INFO_ECX_OSXSAVE       1 << 27
#define CPUID_CPU_INFO_ECX_AVX           1 << 28
#define CPUID_CPU_INFO_ECX_F16C          1 << 29
#define CPUID_CPU_INFO_ECX_RDRAND        1 << 30
//bit 31 is unused

#define CPUID_CPU_INFO_EDX_FPU          1 << 0
#define CPUID_CPU_INFO_EDX_VME          1 << 1
#define CPUID_CPU_INFO_EDX_DE           1 << 2
#define CPUID_CPU_INFO_EDX_PSE          1 << 3
#define CPUID_CPU_INFO_EDX_TSC          1 << 4
#define CPUID_CPU_INFO_EDX_MSR          1 << 5
#define CPUID_CPU_INFO_EDX_PAE          1 << 6
#define CPUID_CPU_INFO_EDX_MCE          1 << 7
#define CPUID_CPU_INFO_EDX_CX8          1 << 8
#define CPUID_CPU_INFO_EDX_APIC         1 << 9
//bit 10 is reserved
#define CPUID_CPU_INFO_EDX_SEP          1 << 11
#define CPUID_CPU_INFO_EDX_MTRR         1 << 12
#define CPUID_CPU_INFO_EDX_PGE          1 << 13
#define CPUID_CPU_INFO_EDX_MCA          1 << 14
#define CPUID_CPU_INFO_EDX_CMOV         1 << 15
#define CPUID_CPU_INFO_EDX_PAT          1 << 16
#define CPUID_CPU_INFO_EDX_PSE_36       1 << 17
#define CPUID_CPU_INFO_EDX_PSN          1 << 18
#define CPUID_CPU_INFO_EDX_CLFSH        1 << 19
//bit 20 is reserved
#define CPUID_CPU_INFO_EDX_DS           1 << 21
#define CPUID_CPU_INFO_EDX_ACPI         1 << 22
#define CPUID_CPU_INFO_EDX_MMX          1 << 23
#define CPUID_CPU_INFO_EDX_FXSR         1 << 24
#define CPUID_CPU_INFO_EDX_SSE          1 << 25
#define CPUID_CPU_INFO_EDX_SSE2         1 << 26
#define CPUID_CPU_INFO_EDX_SS           1 << 27
#define CPUID_CPU_INFO_EDX_HTT          1 << 28
#define CPUID_CPU_INFO_EDX_TM           1 << 29
//bit 30 is reserved
#define CPUID_CPU_INFO_EDX_PBE          1 << 31

//===============CPUID_CACHE_TLB===============
//WARNING: I gave up and used ChatGPT for these
#define CPUID_CACHE_TLB_DESC_NULL 0x00
#define CPUID_CACHE_TLB_DESC_TLB_4_KBYTE_4WAY_32E 0x01
#define CPUID_CACHE_TLB_DESC_TLB_4_MBYTE_FULLY_2E 0x02
#define CPUID_CACHE_TLB_DESC_DTLB_4_KBYTE_4WAY_64E 0x03
#define CPUID_CACHE_TLB_DESC_DTLB_4_MBYTE_4WAY_8E 0x04
#define CPUID_CACHE_TLB_DESC_DTLB1_4_MBYTE_4WAY_32E 0x05
#define CPUID_CACHE_TLB_DESC_L1_INST_8K_4WAY_32B 0x06
#define CPUID_CACHE_TLB_DESC_L1_INST_16K_4WAY_32B 0x08
#define CPUID_CACHE_TLB_DESC_L1_INST_32K_4WAY_64B 0x09
#define CPUID_CACHE_TLB_DESC_L1_DATA_8K_2WAY_32B 0x0A
#define CPUID_CACHE_TLB_DESC_TLB_4_MBYTE_4WAY_4E 0x0B
#define CPUID_CACHE_TLB_DESC_L1_DATA_16K_4WAY_32B 0x0C
#define CPUID_CACHE_TLB_DESC_L1_DATA_16K_4WAY_64B 0x0D
#define CPUID_CACHE_TLB_DESC_L1_DATA_24K_6WAY_64B 0x0E
#define CPUID_CACHE_TLB_DESC_L2_128K_2WAY_64B 0x1D
#define CPUID_CACHE_TLB_DESC_L2_256K_8WAY_64B 0x21
#define CPUID_CACHE_TLB_DESC_L3_512K_4WAY_64B_2LPS 0x22
#define CPUID_CACHE_TLB_DESC_L3_1M_8WAY_64B_2LPS 0x23
#define CPUID_CACHE_TLB_DESC_L2_1M_16WAY_64B 0x24
#define CPUID_CACHE_TLB_DESC_L3_2M_8WAY_64B_2LPS 0x25
#define CPUID_CACHE_TLB_DESC_L3_4M_8WAY_64B_2LPS 0x29
#define CPUID_CACHE_TLB_DESC_L1_DATA_32K_8WAY_64B 0x2C
#define CPUID_CACHE_TLB_DESC_L1_INST_32K_8WAY_64B 0x30
#define CPUID_CACHE_TLB_DESC_NO_L2_OR_L3 0x40
#define CPUID_CACHE_TLB_DESC_L2_128K_4WAY_32B 0x41
#define CPUID_CACHE_TLB_DESC_L2_256K_4WAY_32B 0x42
#define CPUID_CACHE_TLB_DESC_L2_512K_4WAY_32B 0x43
#define CPUID_CACHE_TLB_DESC_L2_1M_4WAY_32B 0x44
#define CPUID_CACHE_TLB_DESC_L2_2M_4WAY_32B 0x45
#define CPUID_CACHE_TLB_DESC_L3_4M_4WAY_64B 0x46
#define CPUID_CACHE_TLB_DESC_L3_8M_8WAY_64B 0x47
#define CPUID_CACHE_TLB_DESC_L2_3M_12WAY_64B 0x48
#define CPUID_CACHE_TLB_DESC_L3_4M_16WAY_64B 0x49
#define CPUID_CACHE_TLB_DESC_L3_6M_12WAY_64B 0x4A
#define CPUID_CACHE_TLB_DESC_L3_8M_16WAY_64B 0x4B
#define CPUID_CACHE_TLB_DESC_L3_12M_12WAY_64B 0x4C
#define CPUID_CACHE_TLB_DESC_L3_16M_16WAY_64B 0x4D
#define CPUID_CACHE_TLB_DESC_L2_6M_24WAY_64B 0x4E
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_32E 0x4F
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_2M_4M_64E 0x50
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_2M_4M_128E 0x51
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_2M_4M_256E 0x52
#define CPUID_CACHE_TLB_DESC_TLB_INST_2M_4M_FULLY_7E 0x55
#define CPUID_CACHE_TLB_DESC_DTLB0_4M_4WAY_16E 0x56
#define CPUID_CACHE_TLB_DESC_DTLB0_4K_4WAY_16E 0x57
#define CPUID_CACHE_TLB_DESC_DTLB0_4K_FULLY_16E 0x59
#define CPUID_CACHE_TLB_DESC_DTLB0_2M_4M_4WAY_32E 0x5A
#define CPUID_CACHE_TLB_DESC_DTLB_4K_4M_64E 0x5B
#define CPUID_CACHE_TLB_DESC_DTLB_4K_4M_128E 0x5C
#define CPUID_CACHE_TLB_DESC_DTLB_4K_4M_256E 0x5D
#define CPUID_CACHE_TLB_DESC_L1_DATA_16K_8WAY_64B 0x60
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_FULLY_48E 0x61
#define CPUID_CACHE_TLB_DESC_DTLB_2M_4M_32E_1G_4WAY_4E 0x63
#define CPUID_CACHE_TLB_DESC_DTLB_4K_4WAY_512E 0x64
#define CPUID_CACHE_TLB_DESC_L1_DATA_8K_4WAY_64B 0x66
#define CPUID_CACHE_TLB_DESC_L1_DATA_16K_4WAY_64B_DUPLICATE 0x67 //????????????
#define CPUID_CACHE_TLB_DESC_L1_DATA_32K_4WAY_64B 0x68
#define CPUID_CACHE_TLB_DESC_UTLB_4K_8WAY_64E 0x6A
#define CPUID_CACHE_TLB_DESC_DTLB_4K_8WAY_256E 0x6B
#define CPUID_CACHE_TLB_DESC_DTLB_2M_4M_8WAY_128E 0x6C
#define CPUID_CACHE_TLB_DESC_DTLB_1G_FULLY_16E 0x6D
#define CPUID_CACHE_TLB_DESC_TRACE_12K_8WAY 0x70
#define CPUID_CACHE_TLB_DESC_TRACE_16K_8WAY 0x71
#define CPUID_CACHE_TLB_DESC_TRACE_32K_8WAY 0x72
#define CPUID_CACHE_TLB_DESC_TLB_INST_2M_4M_FULLY_8E 0x76
#define CPUID_CACHE_TLB_DESC_L2_1M_4WAY_64B 0x78
#define CPUID_CACHE_TLB_DESC_L2_128K_8WAY_64B_2LPS 0x79
#define CPUID_CACHE_TLB_DESC_L2_256K_8WAY_64B_2LPS 0x7A
#define CPUID_CACHE_TLB_DESC_L2_512K_8WAY_64B_2LPS 0x7B
#define CPUID_CACHE_TLB_DESC_L2_1M_8WAY_64B_2LPS 0x7C
#define CPUID_CACHE_TLB_DESC_L2_2M_8WAY_64B 0x7D
#define CPUID_CACHE_TLB_DESC_L2_512K_2WAY_64B 0x7F
#define CPUID_CACHE_TLB_DESC_L2_512K_8WAY_64B 0x80
#define CPUID_CACHE_TLB_DESC_L2_256K_8WAY_32B 0x82
#define CPUID_CACHE_TLB_DESC_L2_512K_8WAY_32B 0x83
#define CPUID_CACHE_TLB_DESC_L2_1M_8WAY_32B 0x84
#define CPUID_CACHE_TLB_DESC_L2_2M_8WAY_32B 0x85
#define CPUID_CACHE_TLB_DESC_L2_512K_4WAY_64B 0x86
#define CPUID_CACHE_TLB_DESC_L2_1M_8WAY_64B 0x87
#define CPUID_CACHE_TLB_DESC_DTLB_4K_FULLY_ASSOC_32E 0xA0
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_4WAY_128E 0xB0
#define CPUID_CACHE_TLB_DESC_TLB_INST_2M_4WAY_8E_4M_4WAY_4E 0xB1
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_4WAY_64E 0xB2
#define CPUID_CACHE_TLB_DESC_TLB_DATA_4K_4WAY_128E 0xB3
#define CPUID_CACHE_TLB_DESC_TLB_DATA_4K_4WAY_256E 0xB4
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_8WAY_64E 0xB5
#define CPUID_CACHE_TLB_DESC_TLB_INST_4K_8WAY_128E 0xB6
#define CPUID_CACHE_TLB_DESC_TLB_DATA_4K_4WAY_64E 0xBA
#define CPUID_CACHE_TLB_DESC_TLB_DATA_4K_4M_4WAY_8E 0xC0
#define CPUID_CACHE_TLB_DESC_STLB_2ND_LEVEL_4K_2M_8WAY_1024E 0xC1
#define CPUID_CACHE_TLB_DESC_DTLB_4K_2M_4WAY_16E 0xC2
#define CPUID_CACHE_TLB_DESC_STLB_2ND_LEVEL_4K_2M_6WAY_1536E_1GB_4WAY_16E 0xC3
#define CPUID_CACHE_TLB_DESC_DTLB_2M_4M_4WAY_32E 0xC4
#define CPUID_CACHE_TLB_DESC_STLB_2ND_LEVEL_4K_4WAY_512E 0xCA
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_512KB_4WAY_64B_LINE 0xD0
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_1MB_4WAY_64B_LINE 0xD1
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_2MB_4WAY_64B_LINE 0xD2
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_1MB_8WAY_64B_LINE 0xD6
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_2MB_8WAY_64B_LINE 0xD7
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_4MB_8WAY_64B_LINE 0xD8
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_1_5MB_12WAY_64B_LINE 0xDC
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_3MB_12WAY_64B_LINE 0xDD
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_6MB_12WAY_64B_LINE 0xDE
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_2MB_16WAY_64B_LINE 0xE2
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_4MB_16WAY_64B_LINE 0xE3
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_8MB_16WAY_64B_LINE 0xE4
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_12MB_24WAY_64B_LINE 0xEA
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_18MB_24WAY_64B_LINE 0xEB
#define CPUID_CACHE_TLB_DESC_CACHE_3RD_LEVEL_24MB_24WAY_64B_LINE 0xEC
#define CPUID_CACHE_TLB_DESC_PREFETCH_64_BYTE 0xF0
#define CPUID_CACHE_TLB_DESC_PREFETCH_128_BYTE 0xF1
#define CPUID_CACHE_TLB_DESC_NO_TLB_INFO_CPUID_LEAF_18H 0xFE
#define CPUID_CACHE_TLB_DESC_NO_CACHE_INFO_CPUID_LEAF_4 0xFF

//=============CPUID_SERIAL_NUMBER=============
#define CPUID_SERIAL_NUMBER_STITCH(ECX,EDX) (uint64_t)((EDX << 32) | ECX)

//=============CPUID_CACHE_PARAMS==============
#define CPUID_CACHE_PARAMS_EAX_CACHE_TYPE             0xF
#define CPUID_CACHE_PARAMS_EAX_CACHE_LEVEL            0x7 << 4
#define CPUID_CACHE_PARAMS_EAX_IS_SELF_INIT           1 << 8 
#define CPUID_CACHE_PARAMS_EAX_IS_FULLY_ASSOCIATIVE   1 << 9
// bits 10-13 are reserved
#define CPUID_CACHE_PARAMS_EAX_MAX_PROC_SHARING       0xFFF << 14

#define CPUID_CACHE_PARAMS_EAX_CACHE_TYPE_NULL        0x0
#define CPUID_CACHE_PARAMS_EAX_CACHE_TYPE_DATA        0x1
#define CPUID_CACHE_PARAMS_EAX_CACHE_TYPE_INSTRUCTION 0x2
#define CPUID_CACHE_PARAMS_EAX_CACHE_TYPE_UNIFIED     0x3

#define CPUID_CACHE_PARAMS_EBX_COHERENCY_LINE_SIZE    0xFFF
#define CPUID_CACHE_PARAMS_EBX_PHYS_LINE_PARTITIONS   0x3FF << 12
#define CPUID_CACHE_PARAMS_EBX_WAYS_OF_ASSOCIVITY     0x3FF

#define CPUID_CACHE_PARAMS_EDX_CACHE_INCLUSIVENESS    1
#define CPUID_CACHE_PARAMS_EDX_COMPLEX_CACHE_INDEXING 1 << 1

//=============CPUID_MONITOR_MWAIT=============
#define CPUID_MONITOR_MWAIT_ECX_ENUM_EXTENSIONS       1
#define CPUID_MONITOR_MWAIT_ECX_BREAK_EVENTS          1 << 1

#define CPUID_MONITOR_MWAIT_EDX_C0_SUBC_STATES        0xF
#define CPUID_MONITOR_MWAIT_EDX_C1_SUBC_STATES        0xF << 4
#define CPUID_MONITOR_MWAIT_EDX_C2_SUBC_STATES        0xF << 8
#define CPUID_MONITOR_MWAIT_EDX_C3_SUBC_STATES        0xF << 12
#define CPUID_MONITOR_MWAIT_EDX_C4_SUBC_STATES        0xF << 16
#define CPUID_MONITOR_MWAIT_EDX_C5_SUBC_STATES        0xF << 20
#define CPUID_MONITOR_MWAIT_EDX_C6_SUBC_STATES        0xF << 24
#define CPUID_MONITOR_MWAIT_EDX_C7_SUBC_STATES        0xF << 28

//===========CPUID_THERMAL_AND_POWER===========
#define CPUID_THERMAL_AND_POWER_EAX_TEMP_SENSOR       1
#define CPUID_THERMAL_AND_POWER_EAX_TURBO_BOOST       1 << 1
#define CPUID_THERMAL_AND_POWER_EAX_ARAT              1 << 2
//Bit 3 is reserved
#define CPUID_THERMAL_AND_POWER_EAX_PLN               1 << 3
#define CPUID_THERMAL_AND_POWER_EAX_ECMD              1 << 5
#define CPUID_THERMAL_AND_POWER_EAX_PTM               1 << 6
#define CPUID_THERMAL_AND_POWER_EAX_HWP               1 << 7
#define CPUID_THERMAL_AND_POWER_EAX_HWP_NOTIFICATION  1 << 8
#define CPUID_THERMAL_AND_POWER_EAX_HWP_ACT_WINDOW    1 << 9
#define CPUID_THERMAL_AND_POWER_EAX_HWP_PERF_PREF     1 << 10
#define CPUID_THERMAL_AND_POWER_EAX_HWP_PKG_LVL_REQ   1 << 11
//Bit 12 is reserved
#define CPUID_THERMAL_AND_POWER_EAX_HDC               1 << 13
#define CPUID_THERMAL_AND_POWER_EAX_TURBO_BOOST_MAX   1 << 14
#define CPUID_THERMAL_AND_POWER_EAX_HWP_CAPABILITIES  1 << 15
#define CPUID_THERMAL_AND_POWER_EAX_HWP_PECI          1 << 16
#define CPUID_THERMAL_AND_POWER_EAX_FLEXIBLE_HWP      1 << 17
#define CPUID_THERMAL_AND_POWER_EAX_FAST_HWP_REQUEST  1 << 18
#define CPUID_THERMAL_AND_POWER_EAX_HW_FEEDBACK       1 << 19
#define CPUID_THERMAL_AND_POWER_EAX_IGNORE_HWP_IDLE   1 << 20
//Bits 21 and 22 are reserved
#define CPUID_THERMAL_AND_POWER_EAX_THREAD_DIRECTOR   1 << 23
#define CPUID_THERMAL_AND_POWER_EAX_THERM_INTERRUPT   1 << 24

#define CPUID_THERMAL_AND_POWER_EBX_INT_TRESHOLD      0xf

#define CPUID_THERMAL_AND_POWER_ECX_HW_COORD_FEEDBACK 1
#define CPUID_THERMAL_AND_POWER_ECX_ENERGY_PERF_BIAS  1 << 3
#define CPUID_THERMAL_AND_POWER_ECX_TD_CLASSES        0xff << 8

#define CPUID_THERMAL_AND_POWER_EDX_PERF_REPORT       1
#define CPUID_THERMAL_AND_POWER_EDX_EFFICIENCY_REPORT 1      << 1
#define CPUID_THERMAL_AND_POWER_EDX_HW_FEEDBACK_SIZE  0xf    << 8
#define CPUID_THERMAL_AND_POWER_EDX_THIS_PROC_HW_FB   0xffff << 16

//===========CPUID_EXTENDED_FEATURES===========
#define CPUID_EXTENDED_FEATURES_EBX_FSGSBASE          1 
#define CPUID_EXTENDED_FEATURES_EBX_TSC_ADJUST        1 << 1
#define CPUID_EXTENDED_FEATURES_EBX_SGX               1 << 2
#define CPUID_EXTENDED_FEATURES_EBX_BMI1              1 << 3
#define CPUID_EXTENDED_FEATURES_EBX_HLE               1 << 4
#define CPUID_EXTENDED_FEATURES_EBX_AVX2              1 << 5
#define CPUID_EXTENDED_FEATURES_EBX_FDP_EXCPTN_ONLY   1 << 6
#define CPUID_EXTENDED_FEATURES_EBX_SMEP              1 << 7
#define CPUID_EXTENDED_FEATURES_EBX_BMI2              1 << 8
#define CPUID_EXTENDED_FEATURES_EBX_ENHANCED_REP      1 << 9
#define CPUID_EXTENDED_FEATURES_EBX_INVCIP            1 << 10
#define CPUID_EXTENDED_FEATURES_EBX_RTM               1 << 11
#define CPUID_EXTENDED_FEATURES_EBX_RDT_M             1 << 12
#define CPUID_EXTENDED_FEATURES_EBX_NO_FPU_CS         1 << 13
#define CPUID_EXTENDED_FEATURES_EBX_MPX               1 << 14
#define CPUID_EXTENDED_FEATURES_EBX_RDT_A             1 << 15
#define CPUID_EXTENDED_FEATURES_EBX_AVX512F           1 << 16
#define CPUID_EXTENDED_FEATURES_EBX_AVX512DQ          1 << 17
#define CPUID_EXTENDED_FEATURES_EBX_RDSEED            1 << 18
#define CPUID_EXTENDED_FEATURES_EBX_ADX               1 << 19
#define CPUID_EXTENDED_FEATURES_EBX_SMAP              1 << 20
#define CPUID_EXTENDED_FEATURES_EBX_AVX512_IFMA       1 << 21
// Bit 22 is reserved
#define CPUID_EXTENDED_FEATURES_EBX_CLFLUSHOPT        1 << 23
#define CPUID_EXTENDED_FEATURES_EBX_CLWB              1 << 24
#define CPUID_EXTENDED_FEATURES_EBX_TRACE             1 << 25
#define CPUID_EXTENDED_FEATURES_EBX_AVX512PF          1 << 26
#define CPUID_EXTENDED_FEATURES_EBX_AVX512ER          1 << 27
#define CPUID_EXTENDED_FEATURES_EBX_AVX512CD          1 << 28
#define CPUID_EXTENDED_FEATURES_EBX_SHA               1 << 29
#define CPUID_EXTENDED_FEATURES_EBX_AVX512BW          1 << 30
#define CPUID_EXTENDED_FEATURES_EBX_AVX512VL          1 << 31

#define CPUID_EXTENDED_FEATURES_ECX_PREFETCHWT1       1
#define CPUID_EXTENDED_FEATURES_ECX_AFX512_VBMI       1 << 1
#define CPUID_EXTENDED_FEATURES_ECX_UMIP              1 << 2
#define CPUID_EXTENDED_FEATURES_ECX_PKU               1 << 3
#define CPUID_EXTENDED_FEATURES_ECX_OSPKE             1 << 4
#define CPUID_EXTENDED_FEATURES_ECX_WAITPKG           1 << 5
#define CPUID_EXTENDED_FEATURES_ECX_AVX512_VBMI2      1 << 6
#define CPUID_EXTENDED_FEATURES_ECX_CET_SS            1 << 7
#define CPUID_EXTENDED_FEATURES_ECX_GFNI              1 << 8
#define CPUID_EXTENDED_FEATURES_ECX_VAES              1 << 9
#define CPUID_EXTENDED_FEATURES_ECX_VPCLMULQDQ        1 << 10
#define CPUID_EXTENDED_FEATURES_ECX_AVX512_VNNI       1 << 11
#define CPUID_EXTENDED_FEATURES_ECX_AVX512_BITLANG    1 << 12
#define CPUID_EXTENDED_FEATURES_ECX_TME_EN            1 << 13
#define CPUID_EXTENDED_FEATURES_ECX_AVX512_VPOPVNZDQ  1 << 14
//bit 15 is reserved
#define CPUID_EXTENDED_FEATURES_ECX_LA57              1 << 16
#define CPUID_EXTENDED_FEATURES_ECX_MAWAU_VAL         0x1F << 17
#define CPUID_EXTENDED_FEATURES_ECX_RDPID             1 << 22
#define CPUID_EXTENDED_FEATURES_ECX_KL                1 << 23
#define CPUID_EXTENDED_FEATURES_ECX_BUS_LOCK_DETECT   1 << 24
#define CPUID_EXTENDED_FEATURES_ECX_CLDEMOTE          1 << 25
//bit 26 is reserved
#define CPUID_EXTENDED_FEATURES_ECX_MOVDIRI           1 << 27
#define CPUID_EXTENDED_FEATURES_ECX_MOVDIR64B         1 << 28
#define CPUID_EXTENDED_FEATURES_ECX_ENQCMD            1 << 29
#define CPUID_EXTENDED_FEATURES_ECX_SGX_LC            1 << 30
#define CPUID_EXTENDED_FEATURES_ECX_PKS               1 << 31

//bit 0 is reserved
#define CPUID_EXTENDED_FEATURES_EDX_SGX_KEYS          1 << 1
#define CPUID_EXTENDED_FEATURES_EDX_AVX512_4VNNIW     1 << 2
#define CPUID_EXTENDED_FEATURES_EDX_AVX512_4FMAPS     1 << 3
#define CPUID_EXTENDED_FEATURES_EDX_FAST_REP_MOV      1 << 4
#define CPUID_EXTENDED_FEATURES_EDX_UINTR             1 << 5
//bits 6 and 7 are reserved
#define CPUID_EXTENDED_FEATURES_EDX_AVX512_VPINTERSECT 1 << 8 // intel you son of a bitch
#define CPUID_EXTENDED_FEATURES_EDX_SRBDS_CTRL        1 << 9
#define CPUID_EXTENDED_FEATURES_EDX_MD_CLEAR          1 << 10
#define CPUID_EXTENDED_FEATURES_EDX_RTM_ALWAYS_ABORT  1 << 11
//bit 12 is reserved
#define CPUID_EXTENDED_FEATURES_EDX_RTM_FORCE_ABORT   1 << 13
#define CPUID_EXTENDED_FEATURES_EDX_SERIALIZE         1 << 14
#define CPUID_EXTENDED_FEATURES_EDX_HYBRID            1 << 15
#define CPUID_EXTENDED_FEATURES_EDX_TSXLDTRK          1 << 16
//bit 17 is reserved
#define CPUID_EXTENDED_FEATURES_EDX_PCONFIG           1 << 18
#define CPUID_EXTENDED_FEATURES_EDX_ARCHITECTURAL_LBR 1 << 19
#define CPUID_EXTENDED_FEATURES_EDX_CET_IBT           1 << 20
//bit 21 is reserved
#define CPUID_EXTENDED_FEATURES_EDX_AMX_BF16          1 << 22
#define CPUID_EXTENDED_FEATURES_EDX_AVX512_FP16       1 << 23
#define CPUID_EXTENDED_FEATURES_EDX_AMX_TILE          1 << 24
#define CPUID_EXTENDED_FEATURES_EDX_AMX_INT8          1 << 25
#define CPUID_EXTENDED_FEATURES_EDX_IBRS              1 << 26
#define CPUID_EXTENDED_FEATURES_EDX_STIBP             1 << 27
#define CPUID_EXTENDED_FEATURES_EDX_L1D_FLUSH         1 << 28
#define CPUID_EXTENDED_FEATURES_EDX_ARCH_CAPABS_MSR   1 << 29
#define CPUID_EXTENDED_FEATURES_EDX_CORE_CAPABS_MSR   1 << 30
#define CPUID_EXTENDED_FEATURES_EDX_SSBD              1 << 31

//=========CPUID_EXTENDED_FEATURES_SL1=========
//bits 0-3 are reserved
#define CPUID_EXTENDED_FEATURES_SL1_EAX_AVX_VNNI     1 << 4
#define CPUID_EXTENDED_FEATURES_SL1_EAX_AVX512_BF16  1 << 5
//bits 6-9 are reserved 
#define CPUID_EXTENDED_FEATURES_SL1_EAX_0_REP_MOVSB  1 << 10
#define CPUID_EXTENDED_FEATURES_SL1_EAX_FAST_STOSB   1 << 11
#define CPUID_EXTENDED_FEATURES_SL1_EAX_FAST_CMPSB   1 << 12
//bits 13-21 are reserved
#define CPUID_EXTENDED_FEATURES_SL1_EAX_HRESET       1 << 22
//bits 23-19 are reserved
#define CPUID_EXTENDED_FEATURES_SL1_EAX_INVD_POSTPOST 1 << 30
//bit 31 is reserved

#define CPUID_EXTENDED_FEATURES_SL1_EBX_PPIN         1

#define CPUID_EXTENDED_FEATURES_SL1_EDX_CET_SSS      1 << 18

//=========CPUID_EXTENDED_FEATURES_SL2=========
#define CPUID_EXTENDED_FEATURES_SL2_EDX_PSFD         1
#define CPUID_EXTENDED_FEATURES_SL2_EDX_IPRED_CTRL   1 << 1
#define CPUID_EXTENDED_FEATURES_SL2_EDX_RRSBA_CTRL   1 << 2
#define CPUID_EXTENDED_FEATURES_SL2_EDX_DDPD_U       1 << 3
#define CPUID_EXTENDED_FEATURES_SL2_EDX_BHI_CTRL     1 << 4
//The rest of the bits are reserved


enum leaves {
   /* @ Basic CPU info
    * @ Returned EAX: Highest basic CPUID leaf present
    * @ Returned EBX: First 4 letters of the vendor identifier string
    * @ Returned ECX: Third 4 letters of the vendor identifier string
    * @ Retruned EDX: Second 4 letters of the vendor identifier string
    */
   CPUID_VENDOR = 0x00000000,
   /* @ CPU Version information
    * @ Returned EAX: Family,Model,Stepping
    * @ Returned EBX: Brand Index,CLFLUSH line size, Max number of logical processors 
    * @ Returned ECX: Featrue information
    * @ Retruned EDX: More feature information
    */
   CPUID_CPU_INFO = 0x00000001,
   /* @ CPU Cache and TLB information
    * @ Returned EAX: 4 Cache, prefetch or TLB descriptors
    * @ Returned EBX: 4 Cache, prefetch or TLB descriptors 
    * @ Returned ECX: 4 Cache, prefetch or TLB descriptors
    * @ Retruned EDX: 4 Cache, prefetch or TLB descriptors
    */
   CPUID_CACHE_TLB = 0x00000002,
   /* @ CPU Serial Number !!! PENTIUM 3 ONLY !!!
    * @ Returned EAX: Reserved
    * @ Returned EBX: Reserved 
    * @ Returned ECX: bits 0-31 of the serial number
    * @ Retruned EDX: bits 32-63 of the serial number
    */
   CPUID_SERIAL_NUMBER = 0x00000003,
   /* @ CPU Deterministic cache parameters !!! Initial ECX = Cache level !!!
    * @ Returned EAX: Cache level,Is self init,Is fully associative,Maximum number of addressable IDs for logical processors sharing this cache
    * @ Returned EBX: L, P and W
    * @ Returned ECX: S
    * @ Retruned EDX: Cache inclusiveness and Complex Cache indexing
    */
   CPUID_CACHE_PARAMS = 0x00000004,
   /* @ MONITOR/MWAIT params
    * @ Returned EAX: Smallest monitor-line size
    * @ Returned EBX: Largest monitor-line size
    * @ Returned ECX: Enumeration of Monitor-Mwait extensions,Supports treating interrupts as break-event for MWAIT
    * @ Retruned EDX: Number of sub C-states supported using MWAIT for each C number thingy IDK
    */
   CPUID_MONITOR_MWAIT = 0x00000005,
   /* @ Thermal and power managment
    * @ Returned EAX: Thermal and power info
    * @ Returned EBX: Thermal and power info
    * @ Returned ECX: Thermal and power info
    * @ Retruned EDX: Thermal and power info
    */
   CPUID_THERMAL_AND_POWER = 0x00000006,
   /* @ Extended features
    * @ Returned EAX: Number of subleaves supported
    * @ Returned EBX: Features
    * @ Returned ECX: Features
    * @ Retruned EDX: Features
    */
   CPUID_EXTENDED_FEATURES = 0x00000007,
   /* @ Direct Cache Access Information
    * @ Returned EAX: Value of the MSR "IA32_PLATFORM_DCA_CAP"
    * @ Returned EBX: Reserved
    * @ Returned ECX: Reserved
    * @ Retruned EDX: Reserved
    */
   CPUID_CACHE_ACCESS_INFO = 0x00000009,
   /* @ Architectural Performance Monitoring
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_PERFORMANCE_MONITORING = 0x0000000A,
   /* @ Extended Topology Enumeration
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_EXTENDENDED_TOPOLOGY = 0x0000000B,
   /* @ Extended Topology Enumeration
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_EXTENDENDED_TOPOLOGY2 = 0x0000000D,
   /* @ RDT Monitoring Enumeration
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_INTEL_RDT = 0x0000000F,
   /* @ RDT Allocation enumeration
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_INTEL_RDT2 = 0x00000010,
   /* @ Intel SGX Attribute Enumeration
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_INTEL_SGX = 0x00000012,
   /* @ Intel Processor Trace Enumeration
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_CPU_TRACE_ENUM = 0x00000014,
   /* @ Time Stamp Counter and Norminal Core Crytal Clock Information
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_TSC = 0x00000015,
   /* @ Processor Frequency Information
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_CPU_FREQ_INFO = 0x00000016,
   /* @ SOC Vendor Information
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_SOC_VENDOR = 0x00000017,
   /* @ Deterministic Address Translation Parameters
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_DETERMINISTIC_ADRESS_TRANSLATION_PARAMS = 0x00000018,
   /* @ Key Locker
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_KEY_LOCKER = 0x000000019,
   /* @ Native Model ID
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_NATIVE_MODEL_ID = 0x0000001A,
   /* @ PCONFIG Information
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_PCONFIG_INFO = 0x0000001B,
   /* @ Last Branch Records Information
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_LAST_BRACH = 0x00000001C,
   /* @ Tile Information
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_TILE_INFO = 0x00000001D,
   /* @ TMUL information
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_TMUL_INFO = 0x00000001E,
   /* @ V2 Extended Topology Enumeration
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_V2_EXTENDED_TOPOLOGY = 0x00000001F,
   /* @ V2 Extended Topology Enumeration
    * @ Returned EAX: Undocumented
    * @ Returned EBX: Undocumented
    * @ Returned ECX: Undocumented
    * @ Retruned EDX: Undocumented
    */
   CPUID_V2_EXTENDED_TOPOLOGY2 = 0x000000020,
   //TODO: add the bitmasks for these Microsoft ones
   /* @ Hypervisor CPUID Leaf Range
    * @ Returned EAX: Highest hypervisor CPUID leaf present
    * @ Returned EBX: Largest monitor-line size
    * @ Returned ECX: Enumeration of Monitor-Mwait extensions,Supports treating interrupts as break-event for MWAIT
    * @ Retruned EDX: Number of sub C-states supported using MWAIT for each C number thingy IDK
    */
   CPUID_HYPERV_IDENT = 0x40000000,
   /* @ Hypervisor Vendor-Neutral Interface Identification
    * @ Returned EAX: Hypervisor interface signature
    * @ Returned EBX: Reserved
    * @ Returned ECX: Reserved
    * @ Retruned EDX: Reserved
    */
   CPUID_MS_HYPERV_INTERFCE_IDENT = 0x40000001,
   /* @ Hypervisor System Identity
    * @ Returned EAX: Build number
    * @ Returned EBX: Major and minor version
    * @ Returned ECX: Reserved
    * @ Retruned EDX: Reserved
    */
   CPUID_MS_HYPERV_SYSTEM_IDENT = 0x40000002,
   /* @ Hypervisor Feature Identification
    * @ Returned EAX: bits 0-31 of HV_PARTITION_PRIVILEGE_MASK
    * @ Returned EBX: bits 31-63 of HV_PARTITION_PRIVILEGE_MASK
    * @ Returned ECX: Hyper-V features
    * @ Retruned EDX: Hyper-V features
    */
   CPUID_MS_HYPERV_FEATURE_IDENT = 0x40000003,
   /* @ Implementation Recommendations
    * @ Returned EAX: Hyper-V feature recommendations
    * @ Returned EBX: Hyper-V feature recommendations
    * @ Returned ECX: Hyper-V feature recommendations
    * @ Retruned EDX: Reserved
    */
   CPUID_MS_HYPERV_RECOMMENDATIONS = 0x40000004,
   /* @ Hypervisor Implementation Limits
    * @ Returned EAX: The maximum number of virtual processors supported
    * @ Returned EBX: The maximum number of logical processors supported
    * @ Returned ECX: The maximum number of physical interrupt vectors available for interrupt remapping.
    * @ Retruned EDX: Reserved
    */
   CPUID_MS_HYPERV_IMPL_LIMITS = 0x40000005,
   /* @ Implementation Hardware Features
    * @ Returned EAX: Hardware features
    * @ Returned EBX: Reserved
    * @ Returned ECX: Reserved
    * @ Retruned EDX: Reserved
    */
   CPUID_MS_HYPERV_HARDWARE_FEATURES = 0x40000006,
   /* @ Nested Hypervisor Feature Identification
    * @ Returned EAX: Nested Hypervisor features
    * @ Returned EBX: Reserved
    * @ Returned ECX: Reserved
    * @ Retruned EDX: Nested Hypervisor features
    */
   CPUID_MS_HYPERV_NESTED_FEATURES = 0x40000009,
   /* @ Nested Hypervisor Nested Virtualization Features
    * @ Returned EAX: Nested Hypervisor features
    * @ Returned EBX: Nested Hypervisor features
    * @ Returned ECX: Reserved
    * @ Retruned EDX: Reserved
    */
   CPUID_MS_HYPERV_NESTED_OPTIMISATIONS = 0x4000000A,
   /* @ Extended processor signature
    * @ Returned EAX: Reserved
    * @ Returned EBX: Reserved
    * @ Returned ECX: Extended feature bits
    * @ Retruned EDX: Extended feature bits
    */
   CPUID_EXTENDED_SIGNATURE = 0x800000001,
   /* @ Full CPU name
    * @ Returned EAX: First 4 characters of the full CPU name
    * @ Returned EBX: Second 4 characters of the full CPU name
    * @ Returned ECX: Third 4 characters of the full CPU name
    * @ Retruned EDX: Fourth 4 characters of the full CPU name
    */
   CPUID_BRAND_STRING1 = 0x800000002,
   /* @ Full CPU name 2
    * @ Returned EAX: Fifth 4 characters of the full CPU name
    * @ Returned EBX: Sexth 4 characters of the full CPU name
    * @ Returned ECX: Seventh 4 characters of the full CPU name
    * @ Retruned EDX: Eightth 4 characters of the full CPU name
    */
   CPUID_BRAND_STRING2 = 0x800000003,
   /* @ Full CPU name 3
    * @ Returned EAX: Nineth 4 characters of the full CPU name
    * @ Returned EBX: Tenth 4 characters of the full CPU name
    * @ Returned ECX: Eleventh 4 characters of the full CPU name
    * @ Retruned EDX: Twelveth 4 characters of the full CPU name
    */
   CPUID_BRAND_STRING3 = 0x800000004,
   /* @ Cache line size and associativity
    * @ Returned EAX: Reserved
    * @ Returned EBX: Reserved
    * @ Returned ECX: Bits 0-7 = Cache line size in bytes, Bits 12-15 = L2 Associativity, Bits 16-31 = Cache size in 1K blocks
    * @ Retruned EDX: Reserved
    */
   CPUID_MORE_CACHE = 0x800000006,
   /* @ Invariant TSC available
    * @ Returned EAX: Reserved
    * @ Returned EBX: Reserved
    * @ Returned ECX: Bit 8 = Invariant TSC available
    * @ Retruned EDX: Reserved
    */
   CPUID_INVARIANT_TSC_AVAILABLE = 0x800000007,
   /* @ Physical adress size
    * @ Returned EAX: Bits 0-7 =  Physical Adress bits, Bits 8-15 = Linear Address bits
    * @ Returned EBX: Bit 9 = WBNOINVD available
    * @ Returned ECX: Reserved
    * @ Retruned EDX: Reserved
    */
   CPUID_PHYS_ADDR_SIZE = 0x800000008,
};

enum sub_leaves{
   /* @ Extended features available subleaf 1 !!! All fields return 0 is info not available !!!
    * @ Returned EAX: Features
    * @ Returned EBX: PPIN
    * @ Returned ECX: Reserved
    * @ Retruned EDX: CET_SSS
    */
    CPUID_EXTENDED_FEATURES_SL1 = 0x00000001,
   /* @ Extended features available subleaf 2 !!! All fields return 0 is info not available !!!
    * @ Returned EAX: Reserved
    * @ Returned EBX: Reserved
    * @ Returned ECX: Reserved
    * @ Retruned EDX: Features
    */
    CPUID_EXTENDED_FEATURES_SL2 = 0x00000002,
    CPUID_INTEL_RDT_CAPABILITY = 0x00000001,
    CPUID_INTEL_RDT2_ALLOCATION = 0x00000000,
    CPUID_INTEL_RDT2_RESID1 = 0x00000001,
    CPUID_INTEL_RDT2_RESID2 = 0x00000002,
    CPUID_INTEL_RDT2_RESID3 = 0x00000003,
    CPUID_INTEL_SGX_SL1 = 0x00000001,
    CPUID_INTEL_SGX_SL2 = 0x00000002,
    CPUID_CPU_TRACE_ENUM_SL = 0x00000001,
    CPUID_SOC_VENDOR_SL1 = 0x00000001,
    CPUID_SOC_VENDOR_SL2 = 0x00000002,
    CPUID_SOC_VENDOR_SL3 = 0x00000003,
    //NOTE: goes higher than 1
    CPUID_DETERMINISTIC_ADRESS_TRANSLATION_PARAMS_SL = 0x00000001,
    CPUID_TILE_INFO_PALETTE1 = 0x000000001,
};

static inline void cpuid(int leaf, int subleaf, int* a, int* b, int* c, int* d) {
    __asm__ __volatile__ (
        "cpuid"
        : "=a" (*a), "=b" (*b), "=c" (*c), "=d" (*d)
        : "a" (leaf), "c" (subleaf)
    );
}

#endif // __CPUID_H__