#include "var_init.h"

bool mx_is_variable(char *arg) {
    bool have_question = false;

    if (*arg == '-' ) {
        arg++;
    }
    while (*arg) {
        if (!mx_isdigit(*arg)) {
            if (*arg == '?') {
                have_question = true;
            }
            else
                return false;
        }
        arg++;
    }

    return have_question;
}
