#include "libmx.h"

char *mx_replace_substr(const char *str, const char *sub, const char *replace) {
    if (!str || !sub || !replace) {
        return NULL;
    }

    int str_len = mx_strlen(str);
    int sub_len = mx_strlen(sub);
    int replace_len = mx_strlen(replace);

    if (sub_len == 0) {
        return mx_strdup(str);
    }

    int occurrences = mx_count_substr(str, sub);

    int new_len = str_len + occurrences * (replace_len - sub_len);

    char *result = (char *)malloc(new_len + 1);
    if (!result) {
        return NULL; 
    }

    const char *current = str;
    char *new_str_ptr = result;

    while ((current = mx_strstr(current, sub)) != NULL) {
        int segment_len = current - str;
        mx_strncpy(new_str_ptr, str, segment_len);
        new_str_ptr += segment_len;

        mx_strcpy(new_str_ptr, replace);
        new_str_ptr += replace_len;

        current += sub_len;
        str = current;
    }

    mx_strcpy(new_str_ptr, str);

    return result;
}
