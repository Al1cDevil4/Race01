#include "var_init.h"

static void trim_str(char **str) {
    char *str_element = *str;
    while (mx_isspace(*str_element)) {
        str_element++;
        (*str)++;
    }
    while (*str_element) {
        str_element++;
    }
    str_element--;
    while (str_element != *str && mx_isspace(*str_element)) {
        *str_element = '\0';
        str_element--;
    }
}

void mx_trim_input(char **argv) {
    for (int i = 0; i < 4; i++, argv++) {
        trim_str(argv);
    }
}
