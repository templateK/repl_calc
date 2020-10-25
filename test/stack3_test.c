#include <stdio.h>
#include <assert.h>
#include <string.h>
#include "libstack3.h"

int main() {
    Stack3 sp = create_stack3();
    int a = 100;
    int b = 200;
    int c = 300;
    assert(sp.top == -1);
    push3(&sp, &a);
    assert(sp.top == 0);
    push3(&sp, &b);
    assert(sp.top == 1);
    push3(&sp, &c);
    assert(sp.top == 2);

    assert(sp.top == 2);
    assert(*(int *)peek3(&sp) == 300);
    assert(*(int *)pop3(&sp)  == 300);
    assert(sp.top == 1);
    assert(*(int *)peek3(&sp) == 200);
    assert(*(int *)pop3(&sp)  == 200);
    assert(sp.top == 0);
    assert(*(int *)peek3(&sp) == 100);
    assert(*(int *)pop3(&sp)  == 100);
    assert(sp.top == -1);
    assert(pop3(&sp)          == NULL);
    assert(is_empty3(&sp));


    char *str1 = "message 1";
    char *str2 = "message 2";
    char *str3 = "message 3";
    push3(&sp, str1);
    push3(&sp, str2);
    push3(&sp, str3);
    assert(strcmp(pop3(&sp), "message 3") == 0);
    assert(strcmp(pop3(&sp), "message 2") == 0);
    assert(strcmp(pop3(&sp), "message 1") == 0);

    printf("SUCCESS");

    return 0;
}
