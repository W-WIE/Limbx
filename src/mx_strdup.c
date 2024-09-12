#include "libmx.h"

char *mx_strdup(const char *str) {
    if (str == NULL) {
        return NULL;  
    }

    size_t len = mx_strlen(str) + 1;

    char *dup = (char *)malloc(len);

    if (dup == NULL) {
        return NULL;  
    }

    mx_memcpy(dup, str, len);

    return dup;  
}
