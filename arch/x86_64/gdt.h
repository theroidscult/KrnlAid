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
        uint16_t limit;
        uint32_t base;
    } __attribute__((packed)) gdt_pointer_t;
#elif defined(__x86_64__)
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

static inline void load_gdt(gdt_pointer_t* pointer) {
    __asm__ __volatile__ (
        "lgdt (%0)"
        :
        : "r" (pointer)
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