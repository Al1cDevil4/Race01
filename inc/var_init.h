#ifndef VAR_INIT
#define VAR_INIT

#include "same_structures.h"
#include "custom_evolving.h"

enum e_errors { USAGE, OPERAND, OPERATION, RESULT };

#define ERR_USAGE (errors[USAGE])
#define ERR_OPERAND (errors[OPERAND])
#define ERR_OPERATION (errors[OPERATION])
#define ERR_RESULT (errors[RESULT])

int mx_strlen(const char *s);

void mx_printerr(const char *s, const char *reason);

bool mx_isdigit(int c);
bool mx_isspace(char c);

char *mx_strdup(const char *str);

int mx_strncmp(const char *s1, const char *s2, int n);

long long mx_atoi(const char *str);

bool mx_is_variable(char *arg);
void mx_trim_input(char **argv);
void mx_var_error_check(int args, char **argv);
void mx_var_init(char **argv,
                 t_var *left,
                 t_var *operation,
                 t_var *right,
                 t_var *result);

#endif
