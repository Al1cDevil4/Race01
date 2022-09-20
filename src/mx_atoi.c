#include "var_init.h"

long long mx_atoi(const char *str) {
    const char *str_element = str;
    long long num = 0;
    bool is_negative = false;

    if (str[0] == '-') {
        is_negative = true;
        str_element++;
    }

    while (mx_isdigit(*str_element)) {
        num *= 10;
        num += *str_element - '0';
        str_element++;
    }
    if (*str_element) return 0;

    return is_negative ? -num : num;
}
