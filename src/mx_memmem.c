#include "libmx.h"

void *mx_memmem(const void *big, size_t big_len, const void *little, size_t little_len) {
    if (little_len == 0 || big_len < little_len) {
        return NULL;
    }

    const unsigned char *big_ptr = (const unsigned char *)big;
    const unsigned char *little_ptr = (const unsigned char *)little;

    for (size_t i = 0; i <= big_len - little_len; ++i) {
        if (mx_memcmp(big_ptr + i, little_ptr, little_len) == 0) {
            return (void *)(big_ptr + i);
        }
    }
    return NULL;
}
