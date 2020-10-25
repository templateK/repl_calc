#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "libparse.h"
#include "libstack3.h"
#include "libarray.h"

int main() {
    char input1[] = "a = 1 + 2";
    char *result = parse_lhs(input1);
    assert(strcmp(result, "a") == 0);

    char input2[] = "123 = 1";
    result = parse_lhs(input2);
    assert(result == NULL);

    char input3[] = "a = b + c";
    result = parse_rhs(input3);
    assert(strcmp(result, " b + c") == 0);

    char input4[] = {'\0'};
    result = parse_rhs(input4);
    assert(result == NULL);

    char *test_input = "(A + B)";
    assert(is_open_paren(  test_input + 0));
    assert(is_symbol(      test_input + 1));
    assert(is_space(       test_input + 2));
    assert(is_operator(    test_input + 3));
    assert(is_space(       test_input + 4));
    assert(is_symbol(      test_input + 5));
    assert(is_close_paren( test_input + 6));


    assert(precedence(test_input + 3) ==2);
    Stack3 stack = create_stack3();
    char a = 'A';
    char op = '+';
    char b = 'B';
    push3(&stack, &a);
    push3(&stack, &op);
    push3(&stack, &b);
    assert(stack.top == 2);
    Array array = create_array();
    append_all(&array, &stack);

    assert(*(char *)array_get(&array,0) == 'B');
    assert(*(char *)array_get(&array,1) == '+');
    assert(*(char *)array_get(&array,2) == 'A');


    Stack3 paren_stack = create_stack3();
    char *paren_test_input = "(A + B";
    for(int i = 0; i < strlen(paren_test_input); i++) {
        push3(&paren_stack, paren_test_input + i);
    }
    Array paren_array = create_array();
    pop_until_open_paren(&paren_stack, &paren_array);
    assert(is_empty3(&paren_stack));
    assert(*(char *)array_get(&paren_array,0) == 'B');
    assert(*(char *)array_get(&paren_array,1) == ' ');
    assert(*(char *)array_get(&paren_array,2) == '+');
    assert(*(char *)array_get(&paren_array,3) == ' ');
    assert(*(char *)array_get(&paren_array,4) == 'A');

    Stack3 precedence_stack = create_stack3();
    char *precedence_test_input = "AB-/*";
    char input_operator = '+';
    for(int i = 0; i < strlen(precedence_test_input); i++) {
        push3(&precedence_stack, precedence_test_input + i);
    }
    int pre_stack_top = precedence_stack.top;
    assert(pre_stack_top == strlen(precedence_test_input) - 1);
    Array precedence_array = create_array();
    char anchor_operator = precedence_test_input[2];
    char anchor_operator1 = precedence_test_input[3];
    char anchor_operator2 = precedence_test_input[4];

    assert(precedence(&input_operator) > precedence(&anchor_operator));
    assert(precedence(&input_operator) < precedence(&anchor_operator1));
    assert(precedence(&input_operator) < precedence(&anchor_operator2));

    pop_high_precedence_operators(&input_operator, &precedence_stack, &precedence_array);
    assert(precedence_stack.top == pre_stack_top - 1);
    assert(precedence_array.end == 1);
    assert(*(char *)array_get(&precedence_array,0) == '*');
    assert(*(char *)array_get(&precedence_array,1) == '/');
    assert(*(char *)peek3(&precedence_stack) == '+');

    char *input5 = "ABC";
    Array postfix_array = infix2postfix(input5);
    assert(postfix_array.end == 2);
    assert(*(char *)array_get(&postfix_array, 0) ==  'A');
    assert(*(char *)array_get(&postfix_array, 1) ==  'B');
    assert(*(char *)array_get(&postfix_array, 2) ==  'C');

    char *input6 = "A + B";
    Array postfix_array2 = infix2postfix(input6);
    assert(postfix_array2.end == 2);
    assert(*(char *)array_get(&postfix_array2, 0) ==  'A');
    assert(*(char *)array_get(&postfix_array2, 1) ==  'B');
    assert(*(char *)array_get(&postfix_array2, 2) ==  '+');
    printf("SUCCESS");

    return 0;
}
