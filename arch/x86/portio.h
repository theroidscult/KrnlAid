#ifndef __PORTIO_H__
#define __PORTIO_H__

#include <stdint.h>

//Outputs a byte(1 bytes) to an I/O port
static inline void outb(uint16_t port, uint8_t value) {
    __asm__ __volatile__ (
        "outb %b0, %w1"
        :
        : "a" (value), "Nd" (port)
    );
}

//Reads a byte(1 bytes) from an I/O port
static inline uint8_t inb(uint16_t port) {
    uint8_t value;
    __asm__ __volatile__ (
        "inb %w1, %b0"
        : "=a" (value)
        : "Nd" (port)
    );
    return value;
}

//Outputs a word(2 bytes) to an I/O port
static inline void outw(uint16_t port, uint16_t value) {
    __asm__ __volatile__ (
        "outw %w0, %w1"
        :
        : "a" (value), "Nd" (port)
    );
}

//Reads a word(2 bytes) from an I/O port
static inline uint16_t inw(uint16_t port) {
    uint16_t value;
    __asm__ __volatile__ (
        "inw %w1, %w0"
        : "=a" (value)
        : "Nd" (port)
    );
    return value;
}

//Outputs a long(4 bytes) to an I/O port
static inline void outl(uint16_t port, uint32_t value) {
    __asm__ __volatile__ (
        "outl %0, %1"
        :
        : "a" (value), "Nd" (port)
    );
}

//Reads a long(4 bytes) from an I/O port
static inline uint32_t inl(uint16_t port) {
    uint32_t value;
    __asm__ __volatile__ (
        "inl %1, %0"
        : "=a" (value)
        : "Nd" (port)
    );
    return value;
}

//Outputs a quadword(8 bytes) to an I/O port
static inline void outq(uint16_t port, uint64_t value) {
    __asm__ __volatile__ (
        "outq %0, %1"
        :
        : "a" (value), "Nd" (port)
    );
}

//Reads a quadword(8 bytes) from an I/O port
static inline uint64_t inq(uint16_t port) {
    uint64_t value;
    __asm__ __volatile__ (
        "inq %1, %0"
        : "=a" (value)
        : "Nd" (port)
    );
    return value;
}

//Waits for the I/O bus to be available
static inline void io_wait() {
    outb(0x80, 0); //0x80 is unused port
}

#endif // __PORTIO_H__