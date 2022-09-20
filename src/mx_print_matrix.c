#include "output.h"

static LL add(LL left, LL right) {
    return left + right;
}

static LL sub(LL left, LL right) {
    return left - right;
}

static LL mult(LL left, LL right) {
    return left * right;
}

static LL divide(LL left, LL right) {
    return left / right;
}

void mx_print_matrix(t_var *left, t_var *oper, t_var *riht, t_var *rz) {
    LL (*operations[])(LL, LL) = {add, sub, mult, divide};

    for (LL op = oper->min; op <= oper->max; op++) {
        for (LL l = left->min; l <= left->max; left->evol(&l, left)) {
            for (LL r = riht->min; r <= riht->max;
                 riht->evol(&r, riht)) {
                for (LL rez = rz->min; rez <= rz->max;
                     rz->evol(&rez, rz)) {
                    if (!(op == 3 && r == 0) &&
                        operations[op](l, r) == rez) {
                        mx_print_variant(l, op, r, rez);
                    }
                }
            }
        }
    }
}
