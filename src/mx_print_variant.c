#include "output.h"

void mx_print_variant(LL l, LL op, LL r, LL rez) {
    mx_printll(l);
    mx_printchar(' ');
    switch (op) {
        case ADD:
            mx_printchar('+');
            break;
        case SUB:
            mx_printchar('-');
            break;
        case MULT:
            mx_printchar('*');
            break;
        case DIV:
            mx_printchar('/');
            break;
    }
    mx_printchar(' ');
    mx_printll(r);
    mx_printchar(' ');
    mx_printchar('=');
    mx_printchar(' ');
    mx_printll(rez);
    mx_printchar('\n');
}
