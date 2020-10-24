#include "libstack.h"

Stack create_stack() {
    Stack stack = {.top = -1};
    return stack;
}

void push(Stack *stack, int c) {
    stack->top += 1;
    stack->data[stack->top] = c;
}

int pop(Stack *stack) {
    if (is_empty(stack)) {
        return -1;
    }
    int c = stack->data[stack->top];
    stack->data[stack->top] = '\0';
    stack->top -= 1;
    return c;
}

int peek(Stack *stack) {
    return stack->data[stack->top];
}

bool is_empty(Stack *stack) {
    return stack->top == -1;
}
