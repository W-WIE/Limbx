#include "libmx.h"

int mx_sqrt(int x) {
    if (x < 0) {
        return 0; 
    }

    int sqrt = 0;
    while (sqrt * sqrt <= x) {
        if (sqrt * sqrt == x) {
            return sqrt; 
        }
        sqrt++;
    }

    return 0; 
}
