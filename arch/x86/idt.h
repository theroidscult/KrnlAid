#ifndef __IDT_H__
#define __IDT_H__

#include <stdint.h>

#define IDT_TYPE_INTERRUPT 0x0E
#define IDT_TYPE_TRAP 0x0F

#define IDT_ACCESS_PRESENT 0x80
#define IDT_ACCESS_PRESENT_SHIFT 7

#define IDT_ACCESS_DPL 0x60
#define IDT_ACCESS_DPL_SHIFT 5

#ifdef __i386__
typedef struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t zero;
    uint8_t type_attr;
    uint16_t offset_high;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint32_t base;
} __attribute__((packed)) idt_pointer_t;

#elif defined (__x86_64__)

typedef struct {
    uint16_t offset_low;
    uint16_t selector;
    uint8_t ist;
    uint8_t type_attr;
    uint16_t offset_mid;
    uint32_t offset_high;
    uint32_t zero;
} __attribute__((packed)) idt_entry_t;

typedef struct {
    uint16_t limit;
    uint64_t base;
} __attribute__((packed)) idt_pointer_t;
#endif

static inline idt_pointer_t make_idt_pointer(idt_entry_t* entries, uint16_t count) {
    idt_pointer_t pointer;
    pointer.limit = (count * sizeof(idt_entry_t)) - 1;
    #ifdef __i386__
        pointer.base = (uint32_t)entries;
    #elif defined(__x86_64__)
        pointer.base = (uint64_t)entries;
    #endif
    return pointer;
}

static inline void load_idt(idt_pointer_t* pointer) {
    __asm__ __volatile__ (
        "lidt (%0)"
        :
        : "r" (pointer)
    );
}

static inline void idt_set_gate(idt_entry_t* entry, void* offset, uint8_t selector, uint8_t ist, uint8_t type_attr) {
    #ifdef __i386__
        entry->offset_low = (uint32_t)((uint32_t)offset & 0xFFFF);
    #elif defined(__x86_64__)
        entry->offset_low = (uint32_t)((uint64_t)offset & 0xFFFF);
    #endif
    entry->selector = selector;
    entry->type_attr = type_attr;
    entry->ist = ist;
    entry->type_attr = type_attr;
    #ifdef __i386__
        entry->offset_mid = (uint16_t)((uint32_t)offset >> 16);
    #elif defined(__x86_64__)
        entry->offset_mid = (uint16_t)((uint64_t)offset >> 16);
        entry->offset_high = (uint32_t)((uint64_t)offset >> 32);
        entry->zero = 0;
    #endif
}

#endif // __IDT_H__