#include "var_init.h"

void mx_printerr(const char *s, const char *reason) {
    int s_size = mx_strlen(s), reason_size = mx_strlen(reason);
    write(2, s, s_size);
    if (reason_size > 0) write(2, reason, reason_size);
    write(2, "\n", 1);
}
