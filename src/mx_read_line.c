#include "libmx.h"

int mx_read_line(char **lineptr, size_t buf_size, char delim, const int fd) {
    if (fd < 0 || !lineptr || buf_size <= 0) {
        return -2;  
    }

    static char *buffer = NULL;  
    static ssize_t buffer_len = 0;  
    char *result = NULL;  
    size_t result_len = 0;  
    ssize_t total_read = 0;  

    if (buffer == NULL) {
        buffer = mx_strnew(buf_size);
        if (buffer == NULL) {
            return -2;  
        }
    }

    while (1) {
        if (buffer_len == 0) {
            ssize_t bytes_read = read(fd, buffer, buf_size);
            if (bytes_read < 0) {
                mx_strdel(&result);  
                return -2;  
            } else if (bytes_read == 0) {

                if (result_len == 0) {
                    return -1;  
                } else {
                    break;  
                }
            }
            buffer_len = bytes_read;  
        }

        char *delim_pos = NULL;
        for (ssize_t i = 0; i < buffer_len; i++) {
            if (buffer[i] == delim) {
                delim_pos = buffer + i;
                break;
            }
        }
        ssize_t to_copy = delim_pos ? (delim_pos - buffer) : buffer_len;

        char *new_result = mx_strnew(result_len + to_copy);
        if (new_result == NULL) {
            mx_strdel(&result);
            return -2;  
        }

        if (result) {
            mx_strncpy(new_result, result, result_len);
            mx_strdel(&result);
        }

        mx_strncpy(new_result + result_len, buffer, to_copy);
        result = new_result;
        result_len += to_copy;
        total_read += to_copy;

        if (delim_pos) {
            ssize_t remaining = buffer_len - (to_copy + 1);
            for (ssize_t i = 0; i < remaining; i++) {
                buffer[i] = buffer[to_copy + 1 + i];
            }
            buffer_len = remaining;
            break;
        } else {
            buffer_len = 0;  
        }
    }

    *lineptr = result;

    return total_read;
}
