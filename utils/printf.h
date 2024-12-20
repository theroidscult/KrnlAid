#ifndef __PRINTF_H__
#define __PRINTF_H__

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

/*
 * !!! THIS IS AN INTENTIONALLY BAREBONES PRINTF !!!
 * !!! PRINTF NEEDS TO BE IMPLEMENTED IN AT LEAST ONE FILE !!!
 * SUPPORTED FORMATS:
 * - %u
 * - %x
 * - %s
 * - %p
 * - %c
 * SPECIFIERS:
 * - %l*
 * - %h*
 * - %hh*
 *
 * Usage: printf(format,...); (e.g. printf("%s", "Hello world!");)
*/

#ifdef PRINTF_IMPL 
    #if defined(print_callback)
        #error "Please define print_callback(char c) to implement printf"
    #endif

    #define FLAG_IN_THINGY 1
    #define FLAG_SIGNED 1 << 1

    //!!! SUPPORTED FORMATS: %u, %x, %s, %p, %c SPECIFIERS: %l*, %h*, %hh* !!!
    void kprintf(const char* fmt, ...) {
        va_list args;
        va_start(args, fmt);

        uint64_t flags = 0;
        uintptr_t num = 0;
        uint32_t base = 10;
        uint8_t bits = 0;
        char strbuf[1024] = {0};
        uint32_t strbuf_len = 0;
        char* s;
        static char numaplpha[] = "0123456789abcdefghijklmnopqrstuvwxyz";

        for(int i = 0; fmt[i]; i++) {
            if (fmt[i] == '%') {
                flags |= FLAG_IN_THINGY;
                continue;
            }
            if(flags & FLAG_IN_THINGY) {
                switch(fmt[i]) {
                    //Specifiers
                    case 'l':
                        bits = 64;
                        break;
                    case 'h':
                        if(bits == 16){
                            bits = 8;
                        }else {
                            bits = 16;
                        }
                        break;
                    //Commands
                    case 'p':
                        bits = sizeof(uintptr_t) * 8;
                        //fallthru
                    case 'x':
                        base = 16;
                        //fallthru
                    case 'i': //fallthru
                    case 'u':
                        num = va_arg(args, int);

                        do{
                            strbuf [strbuf_len] = numaplpha[num % base];
                            num /= base;
                            strbuf_len++;
                        }while(num);

                        for(int j = bits ? bits / 4 : strbuf_len; j > 0; j--) {
                            if(j > strbuf_len) {
                                print_callback('0');
                            } else {
                                print_callback(strbuf[j-1]);
                            }
                        }

                        strbuf_len = 0;
                        base = 10;
                        bits = 0;
                        flags &= ~FLAG_IN_THINGY;
                        break;
                    case 'c':
                        print_callback(va_arg(args, int));
                        flags &= ~FLAG_IN_THINGY;
                        break;
                    case 's':
                        s = va_arg(args, char*);
                        for(int j = 0; s[j]; j++) {
                            print_callback(s[j]);
                        }
                        flags &= ~FLAG_IN_THINGY;
                        break;
                    case '%':
                        print_callback('%');
                        flags &= ~FLAG_IN_THINGY;
                        break;
                    default:
                        flags &= ~FLAG_IN_THINGY;
                        break;
                }
                continue;
            }

            if(!(flags & FLAG_IN_THINGY)) {
                print_callback(fmt[i]);
            }
        }

        va_end(args);
    }
#else
    //!!! SUPPORTED FORMATS: %u, %x, %s, %p, %c SPECIFIERS: %l*, %h*, %hh* !!!
    void kprintf(const char* fmt, ...);
#endif

#endif // __PRINTF_H__