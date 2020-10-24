#include <stdbool.h>

#define BUF_SIZE 256

typedef struct Stack {
    int data[BUF_SIZE];
    int top;
} Stack;

Stack create_stack();
void push(Stack *stack, int c);
int pop(Stack *stack);
int peek(Stack *stack);
bool is_empty(Stack *stack);
