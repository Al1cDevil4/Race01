#include "matrix.h"

int main(int args, char **argv) {
    args--;
    argv++;

    t_var left, operation, right, result;

    mx_var_error_check(args, argv);

    mx_var_init(argv, &left, &operation, &right, &result);

    mx_print_matrix(&left, &operation, &right, &result);
}
