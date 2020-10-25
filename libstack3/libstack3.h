#ifndef __STACK3_H__
#define __STACK3_H__

#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 256

typedef struct Stack3 {
    void *arr[BUF_SIZE];
    int top;
} Stack3;

Stack3 create_stack3();
bool push3(Stack3 *stack, void *data);
void *pop3(Stack3 *stack);
void *peek3(const Stack3 *stack);
bool is_empty3(const Stack3 *stack);
bool is_full3(const Stack3 *stack);

#endif
