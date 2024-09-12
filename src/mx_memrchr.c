#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n) {
    const unsigned char *ptr = (const unsigned char *)s + n - 1;
    unsigned char uc = (unsigned char)c;

    while (n--) {
        if (*ptr == uc) {
            return (void *)ptr;
        }
        ptr--;
    }
    return NULL;
}
