#include "libmx.h"

char *mx_strtrim(const char *str) {
    if (str == NULL) {
        return NULL;
    }
    
    while (isspace((unsigned char)*str)) {
        str++;
    }
    
    if (*str == '\0') {
        char *empty_str = malloc(1);
        if (empty_str == NULL) {
            return NULL; 
        }
        empty_str[0] = '\0';
        return empty_str;
    }
    
    const char *end = str + mx_strlen(str) - 1;
    while (end > str && isspace((unsigned char)*end)) {
        end--;
    }
    
    size_t length = end - str + 1;
    
    char *trimmed_str = malloc(length + 1);
    if (trimmed_str == NULL) {
        return NULL; 
    }

    mx_strncpy(trimmed_str, str, length);
    trimmed_str[length] = '\0'; 
    
    return trimmed_str;
}
