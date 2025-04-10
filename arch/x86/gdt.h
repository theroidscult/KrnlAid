#ifndef __GDT_H__
#define __GDT_H__

#include <stdint.h>

//GDT present bit: this marks the entry as valid
#define GDT_ACCESS_PRESENT 0x80
#define GDT_ACCESS_PRESENT_SHIFT 7

//GDT descriptor privilege level, 0-3
#define GDT_ACCESS_DPL 0x60
#define GDT_ACCESS_DPL_SHIFT 5

//GDT descriptor type: either a general(if set) or system(if clear) segment
#define GDT_ACCESS_DESC_TYPE 0x10
#define GDT_ACCESS_DESC_TYPE_SHIFT 4

//GDT executable flag: Can code execute from this segment?
#define GDT_ACCESS_EXECUTABLE 0x08
#define GDT_ACCESS_EXECUTABLE_SHIFT 3

/*
@ Conformance bit(in code segments): Can a lower privilige level execute code from this segment?
@ Direction bit(in data segments): Does the segment grow up(0) or down(1)?
*/
#define GDT_ACCESS_DIRECTION 0x04
#define GDT_ACCESS_DIRECTION_SHIFT 2

/*
@ Read flag(in cide segments): Can the segment be read?(code segments are never writable)
@ Write flag(in data segments): Can the segment be written?(data segments are always readable)
*/
#define GDT_ACCESS_READ_WRITE 0x02
#define GDT_ACCESS_READ_WRITE_SHIFT 1

//CPU sets it to if its not already set on every access
#define GDT_ACCESS_ACCESSED 0x01
#define GDT_ACCESS_ACCESSED_SHIFT 0

/*
@ If set, the limit is in 4k units
@ If its clear, it is in 1k units
*/
#define GDT_FLAGS_GRANULARITY 0x80
#define GDT_FLAGS_GRANULARITY_SHIFT 7

//Whether the segment is 32 bit(DO NOT SET IN CONJUNCTION WITH GDT_FLAGS_LIMIT_64BIT)
#define GDT_FLAGS_LIMIT_32BIT 0x40
#define GDT_FLAGS_LIMIT_32BIT_SHIFT 6

//Whether the segment is 64 bit(DO NOT SET IN CONJUNCTION WITH GDT_FLAGS_LIMIT_32BIT)
#define GDT_FLAGS_LIMIT_64BIT 0x20
#define GDT_FLAGS_LIMIT_64BIT_SHIFT 5

//Whether the segment is valid
#define TSS_ACCESS_PRESENT 0x80
#define TSS_ACCESS_PRESENT_SHIFT 7

//The descriptor privilege level, 0-3
#define TSS_ACCESS_DPL 0x60
#define TSS_ACCESS_DPL_SHIFT 5

//The descriptor type
#define TSS_ACCESS_TYPE 0x10
#define TSS_ACCESS_TYPE_SHIFT 0

//16 bit task state segment
#define TSS_ACCESS_TYPE_16BIT      0x01
//Local descriptor table
#define TSS_ACCESS_TYPE_LDT        0x02
//16 bit task state segment(busy)
#define TSS_ACCESS_TYPE_16BIT_BUSY 0x03
//32/64 bit task state segment
#define TSS_ACCESS_TYPE_MODE_DEP   0x09
//32/64 bit task state segment(busy)
#define TSS_ACCESS_TYPE_MODE_BUSY  0x0D

typedef struct {
    uint16_t limit_low;
    uint16_t base_low;
    uint8_t base_middle;
    uint8_t access;
    uint8_t flags_limit;
    uint8_t base_high;
} __attribute__((packed)) gdt_entry_t;

#ifdef __i386__
    typedef struct {
        uint32_t link;
        uint32_t esp0;
        uint16_t ss0;
        uint16_t esp1;
        uint16_t ss1;
        uint16_t esp2;
        uint16_t ss2;
        uint16_t cr3;
        uint32_t eip;
        uint32_t eflags;
        uint32_t eax;
        uint32_t ecx;
        uint32_t edx;
        uint32_t ebx;
        uint32_t esp;
        uint32_t ebp;
        uint32_t esi;
        uint32_t edi;
        uint32_t es;
        uint32_t cs;
        uint32_t ss;
        uint32_t ds;
        uint32_t fs;
        uint32_t gs;
        uint32_t ldtr;
        uint32_t iobp;
        uint32_t ssp;
    } __attribute__((packed)) tss_t;

    typedef struct {
        uint16_t limit_low;
        uint16_t base_low;
        uint8_t base_middle;
        uint8_t access;
        uint8_t flags_limit;
        uint8_t base_high;
    } __attribute__((packed)) tss_entry_t;

    typedef struct {
        uint16_t limit;
        uint32_t base;
    } __attribute__((packed)) gdt_pointer_t;
#elif defined(__x86_64__)
    typedef struct {
        uint32_t reserved0; 
        uint64_t rsp0;
        uint64_t rsp1;
        uint64_t rsp2;
        uint64_t reserved1;
        uint64_t ist[7];
        uint64_t reserved2;
        uint32_t iobase;
    } __attribute__((packed)) tss_t;

    typedef struct {
        uint16_t limit_low;
        uint16_t base_low;
        uint8_t base_middle;
        uint8_t access;
        uint8_t flags_limit;
        uint8_t base_mid2;
        uint32_t base_high;
        uint32_t zero;
    } __attribute__((packed)) tss_entry_t;

    typedef struct {
        uint16_t limit;
        uint64_t base;
    } __attribute__((packed)) gdt_pointer_t;
#endif

//Constructs a GDT pointer
static inline gdt_pointer_t make_gdt_pointer(gdt_entry_t* entries, uint16_t count) {
    gdt_pointer_t pointer;
    pointer.limit = (count * sizeof(gdt_entry_t)) - 1;
    #ifdef __i386__
        pointer.base = (uint32_t)entries;
    #elif defined(__x86_64__)
        pointer.base = (uint64_t)entries;
    #endif
    return pointer;
}

//Constructs a TSS entry
static inline tss_entry_t make_tss_entry(tss_t* tss) {
    tss_entry_t entry;
    entry.limit_low = sizeof(tss_t);
    entry.base_low = (uint16_t)((uint64_t)tss & 0xffff); 
    entry.base_middle = (uint8_t)(((uint64_t)tss >> 16) & 0xff);
    entry.access = TSS_ACCESS_PRESENT | TSS_ACCESS_TYPE_MODE_DEP;
    entry.flags_limit = 0;
    entry.base_mid2 = (uint8_t)(((uint64_t)tss >> 24) & 0xff);
    entry.base_high = (uint32_t)((uint64_t)tss >> 32);
    entry.zero = 0;
    return entry;
}

//loads a GDT
static inline void load_gdt(gdt_pointer_t* pointer) {
    __asm__ __volatile__ (
        "lgdt (%0)"
        :
        : "r" (pointer)
    );
}

//loads a TSS
static inline void load_tss(uint16_t index) {
    __asm__ __volatile__ (
        "ltr %0"
        :
        : "r" (index)
    );
}

/*
@ Reloads segments
@ IMPORTANT: DO THIS AFTER ALL GDT CHANGES BECAUSE IT ONLY APPLIES THE NEW GDT ON WRITE TO THE SEGMENT REGISTERS
*/
static inline void flush_cs_ds_etc(uint16_t cs, uint16_t ds) {
    #ifdef __i386__
    __asm__ __volatile__ (
        "mov %%bx, %%ds\n\t"
        "mov %%bx, %%es\n\t"
        "mov %%bx, %%fs\n\t"
        "mov %%bx, %%gs\n\t"
        "mov %%bx, %%ss\n\t"
        "ljmp %%ax, $.reload\n\t"
        ".reload:"
        :
        : "a" (cs), "b" (ds)
    );
    #elif __x86_64__
    uint64_t newcs = 0;
    newcs = cs;
    __asm__ __volatile__ (
        "mov %%bx, %%ds\n\t"
        "mov %%bx, %%es\n\t"
        "mov %%bx, %%fs\n\t"
        "mov %%bx, %%gs\n\t"
        "mov %%bx, %%ss\n\t"
        "pushq %%rax;"
		"pushq $.reload;"
		"lretq;"
		".reload:"
        :
        : "a" (newcs), "b" (ds)
    );
    #endif
}

#endif // __GDT_H__