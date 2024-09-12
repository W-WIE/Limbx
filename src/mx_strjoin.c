#include "libmx.h"

char *mx_strjoin(const char *s1, const char *s2) {
    if (s1 == NULL && s2 == NULL) {
        return NULL;
    }

    if (s1 == NULL) {
        char *result = mx_strdup(s2);
        return result;
    }

    if (s2 == NULL) {
        char *result = mx_strdup(s1);
        return result;
    }

    size_t len1 = mx_strlen(s1);
    size_t len2 = mx_strlen(s2);
    size_t new_len = len1 + len2 + 1; 

    char *result = (char *)malloc(new_len * sizeof(char));
    if (result == NULL) {
        return NULL; 
    }

    mx_strcpy(result, s1);
    mx_strcat(result, s2);

    return result;
}
