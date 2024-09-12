#include "libmx.h"

char *mx_strcat(char *restrict s1, const char *restrict s2) {
    char *dest = s1;

    while (*dest) {
        dest++;
    }

    while (*s2) {
        *dest++ = *s2++;
    }

    *dest = '\0';

    return s1;
}
