#include <stdint.h>
#include <stdio.h>

extern void* push_back_string(void *rp_str_array, const char* str);

void* push_back_string_test(void *rp_str_array)
{
    for (int i = 0; i < 10; i++) {
        char str[100];
        sprintf(str, "%d", i + 1000000);
        rp_str_array = push_back_string(rp_str_array, str);
    }
    return rp_str_array;
}
