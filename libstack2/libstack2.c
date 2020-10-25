#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "libstack2.h"

Stack2* create_stack2(size_t elem_size) {
    Stack2 *sp = (Stack2 *)malloc(sizeof(Stack2));
    sp->top = NULL;
    return sp;
}

void push2(Stack2 *stack, void *data) {
    Elem *elem = (Elem *)malloc(sizeof(Elem));
    /* void *content = malloc(stack->size); */
    elem->data = data;
    elem->below = stack->top;
    stack->top = elem;
}

void *pop2(Stack2 *stack) {
    /* free(stack->top->data); */
    if (is_empty2(stack)) {
        return NULL;
    }
    Elem *old_top = stack->top;
    void *data = stack->top->data;
    stack->top = stack->top->below;
    free(old_top);
    return data;
}

void *peek2(Stack2 *stack) {
    if (is_empty2(stack)) {
        return NULL;
    }
    return stack->top->data;
}

bool is_empty2(Stack2 *stack) {
    return stack->top == NULL;
}

void free_stack2(Stack2 *stack) {
    while(!is_empty2(stack)) {
        pop2(stack);
    }
    stack = NULL;
}

void print_stack2_char(Stack2 *stack) {
    Elem *cur = stack->top;
    while(cur) {
        printf("data: %c", *(char *)cur->data);
        cur = cur->below;
    }
    printf("\n");
}

void print_stack2_int(Stack2 *stack) {
    Elem *cur = stack->top;
    while(cur) {
        printf("data: %d", *(int *)cur->data);
        cur = cur->below;
    }
    printf("\n");
}
