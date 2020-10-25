#ifndef __STACK2_H__
#define __STACK2_H__

#include <stdlib.h>
#include <stdbool.h>

typedef struct Elem {
    void *data;
    struct Elem *below;
} Elem;

typedef struct Stack2 {
    Elem *top;
    size_t size;
} Stack2;

Stack2 *create_stack2();
void free_stack2(Stack2 *stack);
void push2(Stack2 *stack, void *data);
void *pop2(Stack2 *stack);
void *peek2(Stack2 *stack);
bool is_empty2(Stack2 *stack);
void print_stack2_int(Stack2 *stack);

#endif
