#ifndef SAME_H
#define SAME_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

enum e_operations { ADD, SUB, MULT, DIV };

typedef struct s_var {
    long long min;
    long long max;

    void (*evol)(long long *, struct s_var *);

    bool is_nig;
    int digit_size;
    bool is_var[22];
    long long bits[22];
    long long evol_bit[22];
    long long min_bits[22];

    bool is_max;

} t_var;

#endif
