#include "libmx.h"

void mx_str_reverse(char *s) {
    if (!s) return;

    char *start = s;
    char *end = s;

    while (*end != '\0') {
        end++;
    }
    end--;

    while (start < end) {

        char temp = *start;
        *start = *end;
        *end = temp;

        start++;
        end--;
    }
}
