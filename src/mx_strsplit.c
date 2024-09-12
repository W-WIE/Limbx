#include "libmx.h"

char **mx_strsplit(const char *s, char c) {
    if (s == NULL) return NULL;

    int word_count = mx_count_words(s, c);
    if (word_count == 0) {
        char **result = (char **)malloc(sizeof(char *));
        if (result) {
            result[0] = NULL;
        }
        return result;
    }

    char **result = (char **)malloc((word_count + 1) * sizeof(char *));
    if (result == NULL) return NULL;

    int i = 0;
    const char *start = s;
    while (*s) {
        if (*s != c) {
            if (s == start || *(s - 1) == c) {
                const char *word_start = s;
                while (*s && *s != c) s++;
                size_t word_length = s - word_start;
                result[i] = mx_strnew(word_length);
                if (result[i] == NULL) {
                    for (int j = 0; j < i; j++) {
                        free(result[j]);
                    }
                    free(result);
                    return NULL;
                }
                mx_strncpy(result[i], word_start, word_length);
                i++;
            }
        } else {
            s++;
        }
    }
    result[i] = NULL; 

    return result;
}
