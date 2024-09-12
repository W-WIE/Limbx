#include "libmx.h"

void *mx_memchr(const void *s, int c, size_t n) {
    const unsigned char *ptr = s;  
    unsigned char ch = (unsigned char)c;  
    
    while (n--) {
        if (*ptr == ch) {
            return (void *)ptr; 
        }
        ptr++;
    }
    
    return NULL;  
}
