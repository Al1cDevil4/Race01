#ifndef OUTPUT_H
#define OUTPUT_H

#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "same_structures.h"

#define LL long long

int mx_strlen(const char *s);
void mx_printchar(char c);
void mx_printll(LL n);
void mx_printstr(const char *s);

void mx_print_matrix(t_var *, t_var *, t_var *, t_var *);
void mx_print_variant(LL l, LL op, LL r, LL rez);

#endif
