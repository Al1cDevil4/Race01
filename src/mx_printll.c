#include "output.h"

void mx_printll(LL n) {
    bool is_negative = false;

    if (n == 0) {
        mx_printchar('0');
        return;
    }

    char reversed_number_as_string[30];
    char *str_element = reversed_number_as_string + 25;

    *str_element = '\0';
    str_element--;

    if (n < 0) {
        is_negative = true;
        n *= -1;
    }
    for (; n != 0; n /= 10, str_element--) {
        *str_element = (char)((n % 10) + '0');
    }
    str_element++;
    if (is_negative) {
        mx_printchar('-');
    }
    mx_printstr(str_element);
}
