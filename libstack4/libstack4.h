#ifndef __STACK4_H__
#define __STACK4_H__

#include <stdlib.h>
#include <stdbool.h>
#include <stddef.h>

#define BUF_SIZE 256

#define AS_STRUCT(STRUCT, FIELD, ELEM)                          \
    ((STRUCT *)((uint8_t *)(ELEM) - offsetof(STRUCT, FIELD)))

typedef struct Elem {
    struct Elem *below;
} Elem;

typedef struct InsideOutStack {
    Elem *top;
} InsideOutStack;

InsideOutStack create_insideout_stack();
bool push_insideout_stack(InsideOutStack *stack, Elem *elem);
Elem *pop_insideout_stack(InsideOutStack *stack);
Elem *peek_insideout_stack(const InsideOutStack *stack);
bool is_empty_insideout_stack(const InsideOutStack *stack);
/* void display_stack4(const Stack4 *stack); */

#endif
