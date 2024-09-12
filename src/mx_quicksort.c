#include "libmx.h"

int mx_quicksort(char **array, int start, int end) {
    if (array == NULL) {
        return -1;
    }
    int swaping_count = 0;

    if (start < end) {
        int left = start;
        int right = end;
        char *pivot = array[(left + right) / 2];

        while (left <= right) {
            while (mx_strlen(array[left]) < mx_strlen(pivot)) {
                left++;
            }
            while (mx_strlen(array[right]) > mx_strlen(pivot)) {
                right--;
            }

            if (left <= right) {
                if (mx_strlen(array[left]) != mx_strlen(array[right])) {
                    char *temp = array[left];
                    array[left] = array[right];
                    array[right] = temp;
                    swaping_count++;
                }
                left++;
                right--;
            }
        }
        swaping_count += mx_quicksort(array, start, right);
        swaping_count += mx_quicksort(array, left, end);
    }
    return swaping_count;
}
