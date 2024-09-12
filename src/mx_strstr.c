#include "libmx.h"

char *mx_strstr(const char *haystack, const char *needle) {
    if (!*needle) return (char *)haystack; 
    
    while (*haystack) {
        const char *h = haystack;
        const char *n = needle;

        while (*h && *n && *h == *n) {
            h++;
            n++;
        }

        if (!*n) return (char *)haystack;

        haystack++;
    }

    return NULL;
}
