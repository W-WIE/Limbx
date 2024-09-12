#include "libmx.h"

double mx_pow(double n, unsigned int pow) {
    
    if (pow == 0) {
        return 1.0;
    }
    
    double result = 1.0;
    
    for (unsigned int i = 0; i < pow; i++) {
        result *= n;
    }
    
    return result;
}
