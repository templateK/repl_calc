#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "libstack4.h"

typedef struct Foo {
    int val;
    Elem elem;
} Foo;

int main() {
    InsideOutStack sp = create_insideout_stack();
    Foo a = {.val = 100};
    Foo b = {.val = 200};
    Foo c = {.val = 300};
    assert(sp.top == NULL);
    push_insideout_stack(&sp, &a.elem);
    assert(sp.top == &a.elem);
    push_insideout_stack(&sp, &b.elem);
    assert(sp.top == &b.elem);
    push_insideout_stack(&sp, &c.elem);
    assert(sp.top == &c.elem);

    Elem *e = peek_insideout_stack(&sp);
    assert(AS_STRUCT(Foo, elem, e)->val == 300);
    e = pop_insideout_stack(&sp);
    assert(AS_STRUCT(Foo, elem, e)->val == 300);
    e = peek_insideout_stack(&sp);
    assert(AS_STRUCT(Foo, elem, e)->val == 200);
    e = pop_insideout_stack(&sp);
    assert(AS_STRUCT(Foo, elem, e)->val == 200);
    e = peek_insideout_stack(&sp);
    assert(AS_STRUCT(Foo, elem, e)->val == 100);
    e = pop_insideout_stack(&sp);
    assert(AS_STRUCT(Foo, elem, e)->val == 100);
    assert(is_empty_insideout_stack(&sp));
    assert(pop_insideout_stack(&sp) == NULL);
    assert(peek_insideout_stack(&sp) == NULL);

    printf("SUCCESS");

    return 0;
}
