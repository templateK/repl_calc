#ifndef __LIBPARSE_H__
#define __LIBPARSE_H__

#include "libstack3.h"
#include "libarray.h"

char *parse_lhs(char *str);
char *parse_rhs(char *str);
int precedence(char *operator);
bool is_symbol(char *token);
bool is_operator(char *token);
bool is_space(char *token);
bool is_open_paren(char *token);
bool is_close_paren(char *token);
void append_all(Array *array, Stack3 *stack);
void pop_until_open_paren(Stack3 *sp, Array *arr);
void pop_high_precedence_operators(char *operator, Stack3 *sp, Array *arr);
Array infix2postfix(const char *input);

#endif
