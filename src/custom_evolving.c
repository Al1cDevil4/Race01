#include "custom_evolving.h"

static long long *find_var(bool *is_var,
                           long long *bits,
                           int size,
                           int *index) {
    while (size-- > 0) {
        if (*is_var) return bits;
        is_var++;
        (*index)++;
        bits++;
    }
    return NULL;
}

static void evolve_bit(t_var *link) {
    int index = 0;
    long long *target =
        find_var(link->is_var, link->bits, link->digit_size, &index);

    while (target) {
        if (*target / link->evol_bit[index] != 9) {
            *target += link->evol_bit[index];
            return;
        }
        else {
            *target = link->min_bits[index];
            index++;
            target++;
            target = find_var(&(link->is_var[index]),
                              target,
                              link->digit_size - index,
                              &index);
        }
    }
    link->is_max = true;
}

static long long put_num_together(long long *bits, int size) {
    long long ans = 0;

    while (size-- > 0) {
        ans += *bits;
        bits++;
    }
    return ans;
}

void custom_evolve(long long *num, t_var *link) {
    if (link->is_max) {
        *num = link->max + 1;
        link->is_max = false;
        return;
    }

    evolve_bit(link);

    if (link->is_max) {
        *num = link->max + 1;
        link->is_max = false;
        return;
    }

    *num = put_num_together(link->bits, link->digit_size);
    if (link->is_nig) *num *= -1;
}

static void fill_bits_with_zeros(t_var *ans) {
    long long *bits_el = ans->bits;
    long long *min_el = ans->min_bits;
    long long *evol_el = ans->evol_bit;
    long long ten_pow = 1;
    int size_copy = ans->digit_size;
    long long min_copy = ans->min;

    while (size_copy-- > 0) {
        *bits_el = ten_pow * (min_copy % 10);
        *min_el = *bits_el;
        *evol_el = ten_pow;
        min_el++;
        evol_el++;
        bits_el++;
        ten_pow *= 10;
        min_copy /= 10;
    }
}

void borders_case2(const char *arg, t_var *ans) {
    if (arg[0] == '-') {
        ans->is_nig = true;
        arg++;
    }
    else {
        ans->is_nig = false;
    }

    int digit_size = mx_strlen(arg);
    ans->digit_size = digit_size;
    bool *is_el = ans->is_var + digit_size - 1;

    long long min = 0, max = 0;

    while (digit_size-- > 0) {
        max *= 10;
        min *= 10;
        if (*arg != '?') {
            max += *arg - '0';
            min += *arg - '0';
            *is_el = false;
        }
        else {
            max += 9;
            min += 0;
            *is_el = true;
        }
        arg++;
        is_el--;
    }

    ans->max = max;
    ans->min = min;

    fill_bits_with_zeros(ans);

    ans->evol = custom_evolve;
    ans->is_max = false;

    if (ans->is_nig) ans->min *= -1;
}
