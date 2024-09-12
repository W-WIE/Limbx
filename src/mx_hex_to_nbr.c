#include "libmx.h"

unsigned long mx_hex_to_nbr(const char *hex) {
   
    if (hex == NULL) {
        return 0;
    }

    unsigned long result = 0;
    while (*hex) {
        char c = *hex;

        c = toupper(c);

        if (c >= '0' && c <= '9') {
            result = (result << 4) + (c - '0'); 
        } else if (c >= 'A' && c <= 'F') {
            result = (result << 4) + (c - 'A' + 10); 
        } else {
            
            return 0; 
        }

        hex++;
    }

    return result;
}
