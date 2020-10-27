#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "libstack4.h"

InsideOutStack create_insideout_stack() {
    InsideOutStack s = { .top = NULL };
    return s;
}

bool push_insideout_stack(InsideOutStack *stack, Elem *elem) {
    elem->below = stack-> top;
    stack->top = elem;
    return true;
}

Elem *pop_insideout_stack(InsideOutStack *stack) {
    Elem *elem = stack->top;
    if (elem) {
        stack->top = stack->top->below;
        elem->below = NULL;
    }
    return elem;
}

Elem *peek_insideout_stack(const InsideOutStack *stack) {
    return stack->top;
}

bool is_empty_insideout_stack(const InsideOutStack *stack) {
    return stack->top == NULL;
}

/* void display_stack4(const Stack4 *stack) { */
/*     // TODO: implement */
/* } */
