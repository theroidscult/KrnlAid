#ifndef __PRINTF_H__
#define __PRINTF_H__

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>

/*
 * !!! THIS IS AN INTENTIONALLY BAREBONES PRINTF !!!
 * SUPPORTED FORMATS:
 * - %d/%i
 * - %x
 * - %s
 * - %p
 *
 *
 * Usage: printf("Hello, %s", "world");
 * !!! PRINTF NEEDS TO BE IMPLEMENTED IN AT LEAST ONE FILE !!!
*/

#ifdef PRINTF_IMPL 
    #if defined(print_callback)
        #error "Please define print_callback(char c) to implement printf"
    #endif

    #define FLAG_IN_THINGY 1
    #define FLAG_FORCE_64BIT 1 << 1
    
    //!!! SUPPORTED FORMATS: %d/%i, %x, %s !!!
    void kprintf(const char* fmt, ...) {
        va_list args;
        va_start(args, fmt);

        uint64_t flags = 0;
        int num = 0;
        char strbuf[1024] = {0};
        int strbuf_len = 0;

        for(int i = 0; fmt[i]; i++) {
            if (fmt[i] == '%') {
                flags |= FLAG_IN_THINGY;
                continue;
            }
            if(flags & FLAG_IN_THINGY) {
                switch(fmt[i]) {
                    case 'i': //fallthru
                    case 'd':
                        num = va_arg(args, int);
                        strbuf_len = 0;
                        while(num){
                            strbuf[strbuf_len] = num % 10 + '0';
                            num /= 10;
                            strbuf_len++;
                        }
                        for(int j = strbuf_len - 1; j >= 0; j--) {
                            print_callback(strbuf[j]);
                        }
                        flags &= ~FLAG_IN_THINGY;
                        break;
                    case 'p':
                        flags |= FLAG_FORCE_64BIT;
                        //fallthru
                    case 'x':
                        num = va_arg(args, int);
                        strbuf_len = 0;
                        while(num){
                            strbuf [strbuf_len] = (num % 16 + (num % 16 < 10 ? '0' : 'a' - 10));
                            num /= 16;
                            strbuf_len++;
                        }
                        for(int j = (flags & FLAG_FORCE_64BIT) ? 20 : strbuf_len - 1; j >= 0; j--) {
                            if(j > strbuf_len) {
                                print_callback('0');
                            }
                            print_callback(strbuf[j]);
                        }
                        flags &= ~FLAG_IN_THINGY;
                        break;
                    case 's':
                        char* s = va_arg(args, char*);
                        for(int j = 0; s[j]; j++) {
                            print_callback(s[j]);
                        }
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
    //!!! SUPPORTED FORMATS: %d/%i, %x, %s !!!
    void kprintf(const char* fmt, ...);
#endif

#endif // __PRINTF_H__