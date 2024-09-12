#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    
    char *hex_str = malloc(17); 
    if (hex_str == NULL) {
        return NULL; 
    }

    const char hex_digits[] = "0123456789abcdef";

    if (nbr == 0) {
        hex_str[0] = '0';
        hex_str[1] = '\0';
        return hex_str;
    }

    int index = 15;
    hex_str[16] = '\0'; 

    while (nbr > 0) {
        hex_str[index--] = hex_digits[nbr % 16];
        nbr /= 16;
    }

    return &hex_str[index + 1];
}
