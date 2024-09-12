#include "libmx.h"

void print_unicode_char(wchar_t unicode_char) {
    char utf8[4];  
    int len = 0;   

    if (unicode_char < 0x80) {  
        utf8[len++] = unicode_char;
    } 
    else if (unicode_char < 0x800) {  
        utf8[len++] = (unicode_char >> 6) | 0xC0;  
        utf8[len++] = (unicode_char & 0x3F) | 0x80;  
    } 
    else if (unicode_char < 0x10000) {  
        utf8[len++] = (unicode_char >> 12) | 0xE0;  
        utf8[len++] = ((unicode_char >> 6) & 0x3F) | 0x80;  
        utf8[len++] = (unicode_char & 0x3F) | 0x80;  
    } 
    else if (unicode_char < 0x110000) {  
        utf8[len++] = (unicode_char >> 18) | 0xF0;  
        utf8[len++] = ((unicode_char >> 12) & 0x3F) | 0x80;  
        utf8[len++] = ((unicode_char >> 6) & 0x3F) | 0x80;  
        utf8[len++] = (unicode_char & 0x3F) | 0x80;  
    }

    write(1, utf8, len);  
}
