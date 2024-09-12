#include "libmx.h"

int mx_count_substr(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) {
        return -1;
    }

    if (*sub == '\0') {
        return -1;
    }

    int count = 0;
    const char *pos = str;

    while ((pos = mx_strstr(pos, sub)) != NULL) {
        count++;
        pos += mx_strlen(sub);  
    }

    return count;
}
