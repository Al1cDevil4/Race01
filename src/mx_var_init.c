#include "custom_evolving.h"
#include "var_init.h"

void standart_evolve(long long *num, t_var *link) {
    link++;
    (*num)++;
}

static bool is_first_case(const char *arg) {
    if (*arg == '-') arg++;
    while (*arg) {
        if (*arg != '?') return false;
        arg++;
    }
    return true;
}

static void borders_case1(const char *arg, t_var *ans) {
    bool is_negative = false;

    if (arg[0] == '-') {
        is_negative = true;
        arg++;
    }

    int digit_size = mx_strlen(arg);
    long long min = 1, max = 1;

    while (digit_size-- > 0) {
        max *= 10;
    }
    max--;
    if (min == 1) min--;

    if (is_negative) {
        min = -max;
        max = -1;
    }

    ans->max = max;
    ans->min = min;
    ans->evol = standart_evolve;
}

static void set_operation(t_var *operation, char c) {
    if (c == '?') {
        operation->min = 0;
        operation->max = 3;
    }
    else if (c == '+') {
        operation->min = 0;
        operation->max = 0;
    }
    else if (c == '-') {
        operation->min = 1;
        operation->max = 1;
    }
    else if (c == '*') {
        operation->min = 2;
        operation->max = 2;
    }
    else if (c == '/') {
        operation->min = 3;
        operation->max = 3;
    }
}

void mx_var_init(
    char **argv, t_var *lft, t_var *oper, t_var *riht, t_var *res) {
    t_var *vars[4] = {lft, oper, riht, res};
    long long values[4] = {0};
    bool is_var[4] = {false};

    for (int i = 0; i < 4; i++) {
        values[i] = mx_atoi(argv[i]);
        if (values[i] == 0) {
            is_var[i] = mx_is_variable(argv[i]);
            continue;
        }
        is_var[i] = false;
    }

    for (int i = 0; i < 4; i++) {
        if (i == 1) continue;
        if (is_var[i]) {
            if (is_first_case(argv[i])) {
                borders_case1(argv[i], vars[i]);
            }
            else {
                borders_case2(argv[i], vars[i]);
            }
        }
        else {
            vars[i]->min = values[i];
            vars[i]->max = values[i];
            vars[i]->evol = standart_evolve;
        }
    }
    set_operation(oper, argv[1][0]);
}
