#include <stdio.h>
#include <assert.h>
#include "libstack.h"

int main() {
    Stack s = create_stack();
    assert(s.top == -1);

    push(&s, 'a');
    assert(peek(&s) == 'a');

    push(&s, 'b');
    push(&s, 'c');
    assert(peek(&s) == 'c');

    assert(pop(&s) == 'c');
    assert(peek(&s) == 'b');

    assert(pop(&s) == 'b');
    assert(pop(&s) == 'a');
    assert(is_empty(&s));
    assert(pop(&s) == -1);

    printf("SUCCESS");

    return 0;
}
