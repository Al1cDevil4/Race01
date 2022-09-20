#include "var_init.h"

static void free_memory_of_args(char *full_argv[4]) {
    free(full_argv[0]);
    free(full_argv[1]);
    free(full_argv[2]);
    free(full_argv[3]);
}

static int sizes_check(int *sizes) {
    if (sizes[1] != 1) return 1;
    for (int i = 0; i < 4; i++) {
        if (sizes[i] == 0) return i;
    }
    return -1;
}

static int values_check(long long *values, char **argv, int *sizes) {
    const char *max_zero = "00000000000000000000";

    char op = argv[1][0];
    if (op != '-' && op != '+' && op != '*' && op != '/' && op != '?') {
        return 1;
    }

    for (int i = 0; i < 4; i++) {
        if (i == 1) continue;
        if (values[i] == 0)
            if (!mx_is_variable(argv[i]))
                if (mx_strncmp(argv[i], max_zero, sizes[i]) != 0)
                    return i;
    }
    return -1;
}

static void activate_res(int res, char *full_argv[4]) {
    static const char *errors[] = {"",
                                   "Invalid operand: ",
                                   "Invalid operation: ",
                                   "Invalid result: "};

    switch (res) {
        case 0:
            mx_printerr(ERR_OPERAND, full_argv[0]);
            free_memory_of_args(full_argv);
            exit(0);
            break;
        case 1:
            mx_printerr(ERR_OPERATION, full_argv[1]);
            free_memory_of_args(full_argv);
            exit(0);
            break;
        case 2:
            mx_printerr(ERR_OPERAND, full_argv[2]);
            free_memory_of_args(full_argv);
            exit(0);
            break;
        case 3:
            mx_printerr(ERR_RESULT, full_argv[3]);
            free_memory_of_args(full_argv);
            exit(0);
            break;
        default:
            break;
    }
}

void mx_var_error_check(int args, char **argv) {
    if (args != 4) {
        mx_printerr(
            "usage: ./part_of_the_matrix [operand1] [operation] [operand2] [result]",
            "");
        exit(0);
    }

    char *full_argv[] = {mx_strdup(argv[0]),
                         mx_strdup(argv[1]),
                         mx_strdup(argv[2]),
                         mx_strdup(argv[3])};

    mx_trim_input(argv);

    int sizes[4];

    for (int i = 0; i < 4; i++) {
        sizes[i] = mx_strlen(argv[i]);
    }
    activate_res(sizes_check(sizes), full_argv);

    long long values[4] = {0};

    for (int i = 0; i < 4; i++) {
        values[i] = mx_atoi(argv[i]);
    }
    activate_res(values_check(values, argv, sizes), full_argv);

    free_memory_of_args(full_argv);
}
