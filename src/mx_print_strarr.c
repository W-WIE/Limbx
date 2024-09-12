#include "libmx.h"

void mx_print_strarr(char **arr, const char *delim) {
    if (!arr || !delim) {
        return;  
    }

    char **current = arr;  

    if (*current) {  
        while (*current) {  
            mx_printstr(*current);  
            current++;  

            if (*current) {  
                mx_printstr(delim);
            }
        }
    }

    mx_printstr("\n");  
}
