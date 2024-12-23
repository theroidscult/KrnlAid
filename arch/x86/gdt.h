#ifndef __GDT_H__
#define __GDT_H__

#include <stdint.h>


#define GDT_ACCESS_PRESENT 0x80
#define GDT_ACCESS_PRESENT_SHIFT 7

#define GDT_ACCESS_DPL 0x60
#define GDT_ACCESS_DPL_SHIFT 5

#define GDT_ACCESS_DESC_TYPE 0x10
#define GDT_ACCESS_DESC_TYPE_SHIFT 4

#define GDT_ACCESS_EXECUTABLE 0x08
#define GDT_ACCESS_EXECUTABLE_SHIFT 3

#define GDT_ACCESS_DIRECTION 0x04
#define GDT_ACCESS_DIRECTION_SHIFT 2

#define GDT_ACCESS_READ_WRITE 0x02
#define GDT_ACCESS_READ_WRITE_SHIFT 1

#define GDT_ACCESS_ACCESSED 0x01
#define GDT_ACCESS_ACCESSED_SHIFT 0

#define GDT_FLAGS_GRANULARITY 0x80
#define GDT_FLAGS_GRANULARITY_SHIFT 7

#define GDT_FLAGS_LIMIT_32BIT 0x40
#define GDT_FLAGS_LIMIT_32BIT_SHIFT 6

#define GDT_FLAGS_LIMIT_64BIT 0x20
#define GDT_FLAGS_LIMIT_64BIT_SHIFT 5

#define TSS_ACCESS_PRESENT 0x80
#define TSS_ACCESS_PRESENT_SHIFT 7

#define TSS_ACCESS_DPL 0x60
#define TSS_ACCESS_DPL_SHIFT 5

#define TSS_ACCESS_DESC_TYPE 0x10
#define TSS_ACCESS_DESC_TYPE_SHIFT 4

#define TSS_ACCESS_TYPE_16BIT      0x01
#define TSS_ACCESS_TYPE_LDT        0x02
#define TSS_ACCESS_TYPE_16BIT_BUSY 0x03
#define TSS_ACCESS_TYPE_MODE_DEP   0x09
#define TSS_ACCESS_TYPE_MODE_BUSY  0x0D
#define TSS_ACCESS_TYPE_SHIFT 0

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
    } tss_t;

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
        uint64_t reserved0;
        uint64_t rsp0;
        uint64_t rsp1;
        uint64_t rsp2;
        uint64_t reserved1;
        uint64_t ist[7];
        uint64_t reserved2;
        uint32_t iobase;
    } tss_t;

    typedef struct {
        uint16_t limit_low;
        uint16_t base_low;
        uint8_t base_middle;
        uint8_t access;
        uint8_t flags_limit;
        uint8_t base_mid;
        uint32_t base_high;
        uint32_t zero;
    } __attribute__((packed)) tss_entry_t;

    typedef struct {
        uint16_t limit;
        uint64_t base;
    } __attribute__((packed)) gdt_pointer_t;
#endif

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

static inline tss_entry_t make_tss_entry(tss_t* tss,uint8_t type) {
    tss_entry_t entry;
    entry.limit_low = sizeof(tss_entry_t) - 1;
    entry.base_low = (uint16_t)(uint64_t)tss; // werror ffs
    entry.base_middle = (uint8_t)((uint64_t)tss >> 16);
    entry.access = TSS_ACCESS_PRESENT | 0 << TSS_ACCESS_DPL_SHIFT | TSS_ACCESS_DESC_TYPE | type;
    entry.flags_limit = 0;
    entry.base_mid = (uint8_t)((uint64_t)tss >> 24);
    entry.base_high = (uint32_t)((uint64_t)tss >> 32);
    entry.zero = 0;
    return entry;
}

static inline void load_gdt(gdt_pointer_t* pointer) {
    __asm__ __volatile__ (
        "lgdt (%0)"
        :
        : "r" (pointer)
    );
}

static inline void load_tss(uint16_t index) {
    __asm__ __volatile__ (
        "ltr %0"
        :
        : "r" (index)
    );
}

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