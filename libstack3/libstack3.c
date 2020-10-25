#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "libstack3.h"

Stack3 create_stack3(size_t elem_size) {
    Stack3 sp = {.top = -1};
    return sp;
}

bool push3(Stack3 *stack, void *data) {
    if (is_full3(stack)) {
        return false;
    }
    stack->arr[++stack->top] = data;
    return true;
}

void *pop3(Stack3 *stack) {
    if (is_empty3(stack)) {
        return NULL;
    }
    void *data = stack->arr[stack->top];
    stack->top -= 1;
    return data;
}

bool is_full3(const Stack3 *stack) {
    return stack->top == BUF_SIZE;
}

bool is_empty3(const Stack3 *stack) {
    return stack->top == -1;
}

void *peek3(const Stack3 *stack) {
    if (is_empty3(stack)) {
        return NULL;
    }
    return stack->arr[stack->top];
}

void display_stack3(const Stack3 *stack) {
    int size = stack->top + 1;
    for(int i = 0; i < size; i++) {
        printf("%c", *(char *)stack->arr[i]);
    }
}
