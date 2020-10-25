#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <assert.h>
#include "libparse.h"


char *parse_lhs(char *str) {
    char *result = strtok(str, " =");
    if (result && isalpha(result[0])) {
        return result;
    }
    return NULL;
}

char *parse_rhs(char *str) {
    char *result = strchr(str, '=');
    if (result) {
        return ++result;
    }
    return NULL;
}


int precedence(char *operator) {
    int result = 0;
    switch (*operator) {
        case '*': result = 4; break;
        case '/': result = 3; break;
        case '+': result = 2; break;
        case '-': result = 1; break;
        default: result = 0;
    };
    return result;
}

bool is_symbol(char *token) {
    return *token >= 'A' && *token <= 'Z';
}

bool is_operator(char *token) {
    char *operator_chars = "*/+-";
    for(int i=0; i < strlen(operator_chars); i++) {
        if (operator_chars[i] == *token) {
            return true;
        }
    }
    return false;
}

bool is_space(char *token) {
    return *token == ' ';
}

bool is_open_paren(char *token) {
    return *token == '(';
}

bool is_close_paren(char *token) {
    return *token == ')';
}

void append_all(Array *array, Stack3 *stack) {
    int pre_array_size = array->end + 1;
    int pre_stack_size = stack->top + 1;
    for(int i = 0; i < pre_stack_size; i++) {
        array_push(array, pop3(stack));
    }
    int post_array_size =  array->end + 1;
    int post_stack_size =  stack->top + 1;
    assert(post_stack_size == 0);
    assert(pre_stack_size + pre_array_size == post_array_size);
}

void pop_until_open_paren(Stack3 *sp, Array *arr) {
    while ( !is_empty3(sp) ) {
        if ( is_open_paren(peek3(sp)) ) {
            pop3(sp);
            break;
        }
        array_push(arr, pop3(sp));
    }
}

void pop_high_precedence_operators(char *operator, Stack3 *sp, Array *arr) {
    if ( is_empty3(sp) ) {
        push3(sp, operator);
    } else {
        int current_precedence = precedence(operator);
        int stack_precedence = precedence(peek3(sp));
        while ( !is_empty3(sp) ) {
            if (current_precedence >= stack_precedence) {
                break;
            }
            stack_precedence = precedence(peek3(sp));
            array_push(arr, pop3(sp));
        }
        push3(sp, operator);
    }
}

Array infix2postfix(const char *input)  {
    Stack3 stack = create_stack3();
    Array  array = create_array();
    for(int i=0; i < strlen(input); i++) {
        void *c = (void *)(input + i);
        if ( is_open_paren(c)) {
            push3(&stack, c);
        } else if ( is_close_paren(c) ) {
            pop_until_open_paren(&stack, &array);
        } else if ( is_operator(c) ) {
            pop_high_precedence_operators(c, &stack, &array);
        } else if ( is_symbol(c) ) {
            array_push(&array, c);
        }
    }
    append_all(&array, &stack);
    return array;
}

