#include "libmx.h"

char *mx_file_to_str(const char *file) {
    if (file == NULL) {
        return NULL;
    }

    FILE *fp = fopen(file, "r");
    if (fp == NULL) {
        return NULL;  
    }

    if (fseek(fp, 0, SEEK_END) != 0) {
        fclose(fp);
        return NULL;
    }

    size_t file_size = (size_t)ftell(fp);
    if (file_size == (size_t)-1) {  
        fclose(fp);
        return NULL;  
    }

    rewind(fp);

    char *str = mx_strnew(file_size);
    if (str == NULL) {
        fclose(fp);
        return NULL;  
    }

    size_t read_size = fread(str, sizeof(char), file_size, fp);
    if (read_size != file_size) {
        free(str);
        fclose(fp);
        return NULL;  
    }

    fclose(fp);

    return str;
}
