#include "libmx.h"

char *mx_del_extra_spaces(const char *str) {
    if (str == NULL) {
        return NULL;
    }

    char *trimmed_str = mx_strtrim(str);
    if (trimmed_str == NULL) {
        return NULL;
    }

    size_t len = mx_strlen(trimmed_str);
    char *result = (char *)malloc(len + 1); 
    if (result == NULL) {
        free(trimmed_str);
        return NULL;
    }

    char *ptr = result;
    int space_needed = 0;

    for (size_t i = 0; i < len; i++) {
        if (isspace((unsigned char)trimmed_str[i])) {
            if (!space_needed) {
                *ptr++ = ' ';
                space_needed = 1;
            }
        } else {
            *ptr++ = trimmed_str[i];
            space_needed = 0;
        }
    }

    if (ptr > result && *(ptr - 1) == ' ') {
        ptr--;
    }

    *ptr = '\0'; 

    free(trimmed_str);
    return result;
}
