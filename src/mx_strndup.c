#include "libmx.h"

char *mx_strndup(const char *s1, size_t n) {
    if (s1 == NULL) {
        return NULL;  
    }

    size_t len = mx_strlen(s1);
    if (len > n) {
        len = n;  
    }

    char *dup = (char *)malloc(len + 1);
    if (dup == NULL) {
        return NULL;  
    }

    for (size_t i = 0; i < len; i++) {
        dup[i] = s1[i];
    }

    dup[len] = '\0';

    return dup;  
}
