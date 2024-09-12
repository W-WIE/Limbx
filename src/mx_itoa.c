#include "libmx.h"

char *mx_itoa(int number) {
    
    if (number == 0) {
        char *zero_str = malloc(2);
        if (zero_str) {
            zero_str[0] = '0';
            zero_str[1] = '\0';
        }
        return zero_str;
    }

    if (number == -2147483648) {
        char *min_int_str = malloc(12);
        if (min_int_str) {
            for (int i = 0; i < 12; i++) {
                min_int_str[i] = "-2147483648"[i];
            }
        }
        return min_int_str;
    }

    int temp = number;
    int length = (number < 0) ? 2 : 1; 

    while (temp != 0) {
        length++;
        temp /= 10;
    }

    char *str = malloc(length);
    if (!str) return NULL;

    str[length - 1] = '\0'; 

    if (number < 0) {
        str[0] = '-';
        number = -number;
    }

    for (int i = length - 2; number != 0; i--) {
        str[i] = (number % 10) + '0';
        number /= 10;
    }

    return str;
}
