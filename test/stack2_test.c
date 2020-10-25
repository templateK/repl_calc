#include <stdio.h>
#include <assert.h>
#include "libstack2.h"

int main() {
    Stack2 *sp = create_stack2(sizeof(char));
    int a = 100;
    int b = 200;
    int c = 300;
    push2(sp, &a);
    push2(sp, &b);
    push2(sp, &c);

    assert(*(int *)peek2(sp) == 300);
    assert(*(int *)pop2(sp)  == 300);
    assert(*(int *)peek2(sp) == 200);
    assert(*(int *)pop2(sp)  == 200);
    assert(*(int *)peek2(sp) == 100);
    assert(*(int *)pop2(sp)  == 100);
    assert(pop2(sp)          == NULL);
    assert(is_empty2(sp));

    free_stack2(sp);

    printf("SUCCESS");

    return 0;
}
