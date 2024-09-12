#include "libmx.h"

void mx_del_strarr(char ***arr) {
    if (arr == NULL || *arr == NULL) {
        return;
    }

    for (int i = 0; (*arr)[i] != NULL; i++) {
        free((*arr)[i]);
        (*arr)[i] = NULL;  
    }

    free(*arr);
    *arr = NULL;  
}
