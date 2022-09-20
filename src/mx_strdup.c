#include "var_init.h"

static char *mx_strnew(const int size) {
    if (size < 0) return NULL;

    char *new_string = malloc(sizeof(char) * (size + 1));

    if (!new_string) return NULL;
    for (int i = 0; i < size; i++) {
        new_string[i] = '\0';
    }
    new_string[size] = '\0';
    return new_string;
}

static char *mx_strcpy(char *dst, const char *src) {
    while (*src) {
        *dst = *src;
        dst++;
        src++;
    }
    *dst = '\0';
    return dst;
}

char *mx_strdup(const char *str) {
    int lenth = mx_strlen(str);
    char *string_copy = mx_strnew(lenth);

    if (!string_copy) return NULL;

    mx_strcpy(string_copy, str);
    return string_copy;
}
