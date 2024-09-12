#include "libmx.h"

int mx_binary_search(char **arr, int size, const char *s, int *count) {
    int start = 0;
    int end = size - 1;
    *count = 0;

    while (start <= end) {
        (*count)++;
        int mid = (start + end) / 2;
        int cmp = mx_strcmp(arr[mid], s);

        if (cmp < 0)
            start = mid + 1;
        else if (cmp == 0)
            return mid;
        else
            end = mid - 1;
    }

    *count = 0;
    return -1;
}
