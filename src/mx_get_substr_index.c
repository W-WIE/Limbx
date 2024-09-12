#include "libmx.h"

int mx_get_substr_index(const char *str, const char *sub) {
    if (str == NULL || sub == NULL) 
    {
        return -2;
    }
    const char *result = mx_strstr(str, sub);

    if (result == NULL) 
    {
        return -1;
    }
    return result - str;
}
