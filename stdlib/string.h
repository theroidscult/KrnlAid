/******************************************************************************
 * KrnlAid - String Manipulation Library (Header: string.c)
 * 
 * This header file provides (mostly) ISO C compliant string and memory manipulation functions.
 *
 * IMPORTANT: 
 * - To use these functions, you must define `STRING_IMPL` in **exactly one** 
 *   source file before including this header. This ensures the function 
 *   implementations are compiled.
 * - For functions requiring dynamic memory allocation (e.g., `strdup`), you 
 *   must define the `MALLOC_IMPL(n)` macro to provide your custom allocation 
 *   function.
 * 
 * Dependent Functions Omitted:
 * - `strcoll()`
 * - `strerror()`
 * - `strxfrm()`
 * These functions are intentionally omitted from this header due to their use of the UNIX locale system.
 *
 * Example usage:
 * 
 * // In exactly one source file:
 * #define STRING_IMPL
 * #include "string.h"
 *
 * // For memory-requiring functions:
 * #define STRING_IMPL
 * #define MALLOC_IMPL(n) malloc(n)  // Define your allocation function
 * #include "string.h"
 * 
 * ****************************************************************************
 */

#ifndef __STRING_H__
#define __STRING_H__


#include <stddef.h>

#ifdef __cplusplus
extern "C" {
#endif

//Memory stuff
void    *memccpy(void *, const void *, int, size_t);
void    *memchr(const void *, int, size_t);
int      memcmp(const void *, const void *, size_t);
void    *memcpy(void *, const void *, size_t);
void    *memmove(void *, const void *, size_t);
void    *memset(void *, int, size_t);


//String stuff
char    *strcat(char *, const char *);
char    *strchr(const char *, int);
int      strcmp(const char *, const char *);
char    *strcpy(char *, const char *);
size_t   strcspn(const char *, const char *);
size_t   strlen(const char *);
char    *strncat(char *, const char *, size_t);
int      strncmp(const char *, const char *, size_t);
char    *strncpy(char *, const char *, size_t);
char    *strpbrk(const char *, const char *);
char    *strrchr(const char *, int);
size_t   strspn(const char *, const char *);
char    *strstr(const char *, const char *);
char    *strtok(char *, const char *);
char    *strtok_r(char *, const char *, char **);

//String stuff(requires malloc)
#ifdef MALLOC_IMPL
    char    *strdup(const char *);
#endif

#ifdef STRING_IMPL
    void    *memccpy(void *s1, const void *s2, int c, size_t n){
        char *pdest = s1;
        const char *psrc = s2;

        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
            if (pdest[i] == c) {
                return &pdest[i]+1;
            }
        }

        return (void*)NULL;
    }

    void    *memchr(const void *s, int c, size_t n){
        const char *p = s;

        for (size_t i = 0; i < n; i++) {
            if (p[i] == (unsigned char)c) {
                return (void*)&p[i];
            }
        }

        return (void*)NULL;
    }

    int     memcmp(const void *s1, const void *s2, size_t n) {
        const char *p1 = s1;
        const char *p2 = s2;

        for (size_t i = 0; i < n; i++) {
            if (p1[i] != p2[i]) {
                return p1[i] < p2[i] ? -1 : 1;
            }
        }

        return 0;
    }

    void    *memcpy(void *dest, const void *src, size_t n) {
        char *pdest = dest;
        const char *psrc = src;

        for (size_t i = 0; i < n; i++) {
            pdest[i] = psrc[i];
        }

        return dest;
    }

    void    *memmove(void *dest, const void *src, size_t n) {
        char *pdest = dest;
        const char *psrc = src;

        if (src > dest) {
            for (size_t i = 0; i < n; i++) {
                pdest[i] = psrc[i];
            }
        } else if (src < dest) {
            for (size_t i = n; i > 0; i--) {
                pdest[i-1] = psrc[i-1];
            }
        }

        return dest;
    }

    void    *memset(void *s, int c, size_t n) {
        char *p = s;

        for (size_t i = 0; i < n; i++) {
            p[i] = c;
        }

        return s;
    }

    char    *strcat(char *s1, const char *s2){
        strcpy(s1 + strlen(s1), s2);
        return s1;
    }

    char    *strchr(const char * s, int c){
        while (*s != '\0') {
            if (*s == (unsigned char)c) {
                return (char *)s;
            }
            s++;
        }
        return (void*)NULL;
    }

    int      strcmp(const char *s1, const char *s2){
        for(size_t i = 0; i < strlen(s1); i++){
            if(s1[i] != s2[i]){
                return s1[i] < s2[i] ? -1 : 1;
            }
        }
        return 0;
    }

    char    *strcpy(char *s1, const char *s2){
        char *ret = s1;
        while(*s2 != '\0'){
            *s1 = *s2;
            s1++;
            s2++;
        }
        *s1 = '\0';
        return ret;
    }

    size_t   strcspn(const char *s1, const char *s2){
        size_t ret = 0;
        char* orig_s2 = (char*)s2;
        while(*s1 != '\0'){
            s2 = orig_s2;
            while(*s2 != '\0'){
                if(*s1 == *s2){
                    return ret;
                }
                s2++;
            }
            s1++;
            ret++;
        }
        return ret;
    }

    size_t   strlen(const char *s){
        size_t ret = 0; 
        while(*s != '\0'){
            ret++;
            s++;
        }
        return ret;
    }

    char    *strncat(char *s1, const char *s2, size_t n){
        strncpy(s1 + strlen(s1), s2, n);
        return s1;
    }

    int      strncmp(const char *s1, const char *s2, size_t n){
        for(size_t i = 0; i < strlen(s1) && i < n; i++){
            if(s1[i] != s2[i]){
                return s1[i] < s2[i] ? -1 : 1;
            }
        }
        return 0;
    }

    char    *strncpy(char *s1, const char *s2, size_t n){
        char *ret = s1;
        while(*s2 != '\0' && n-- > 0){
            *s1 = *s2;
            s1++;
            s2++;
        }
        *s1 = '\0';
        return ret;
    }

    char    *strpbrk(const char *s1, const char *s2){
        char* orig_s2 = (char*)s2;
        while(*s1 != '\0'){
            s2 = orig_s2;
            while(*s2 != '\0'){
                if(*s1 == *s2){
                    return (char*)s1;
                }
                s2++;
            }
            s1++;
        }
        return (void*)NULL;
    }

    char    *strrchr(const char *s, int c){
        char* last = (char*)NULL;
        while (*s != '\0') {
            if (*s == (unsigned char)c) {
                last = (char *)s;
            }
            s++;
        }
        return last;
    }

    size_t   strspn(const char *s1, const char *s2){
        size_t ret = 0;
        char* orig_s2 = (char*)s2;
        while(*s1 != '\0'){
            s2 = orig_s2;
            while(*s2 != '\0'){
                if(*s1 != *s2){
                    return ret;
                }
                s2++;
            }
            s1++;

            ret++;
        }
        return ret;
    }

    char    *strstr(const char *s1, const char *s2){
        char* orig_s2 = (char*)s2;
        if(*s2 == '\0'){
            return (char*)s1;
        }
        while(*s1 != '\0'){
            if(*s1 == *s2){
                while (*s2 != '\0') {
                    if (*s1 != *s2) {
                        break;
                    }
                    s1++;
                    s2++;
                }
                if(*s2 == '\0'){
                    return (char*)s1;
                }
                s2 = orig_s2;
            }
            s1++;
        }
        return (void*)NULL;
    }

    static char* last;

    char    *strtok(char *s1, const char *s2){
        if(s1 == NULL){
            s1 = last;
        }
        s1 += strspn(s1, s2);
        if(*s1 == '\0'){
            last = s1;
            return (void*)NULL;
        }
        char* ret = s1;
        s1 += strcspn(s1, s2);
        if(*s1 != '\0'){
            *s1 = '\0';
            s1++;
        }
        last = s1;
        return ret;
    }

    char    *strtok_r(char *s1, const char *s2, char **lasts){
        if(s1 == NULL){
            s1 = *lasts;
        }
        s1 += strspn(s1, s2);
        if(*s1 == '\0'){
            *lasts = s1;
            return (void*)NULL;
        }
        char* ret = s1;
        s1 += strcspn(s1, s2);
        if(*s1 != '\0'){
            *s1 = '\0';
            s1++;
        }
        *lasts = s1;
        return ret;
    }

    #ifdef MALLOC_IMPL
        char    *strdup(const char *s){
            char* ret = (char*)MALLOC_IMPL(strlen(s) + 1);
            if (ret != NULL){
                strcpy(ret, s);
            }
            return ret;
        }
    #endif


#endif

#ifdef __cplusplus
}
#endif

#endif // __STRING_H__