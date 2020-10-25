#ifndef __ARRAY_H__
#define __ARRAY_H__

#include <stdlib.h>
#include <stdbool.h>

#define BUF_SIZE 256

typedef struct Array {
    void *arr[BUF_SIZE];
    int end;
} Array;

Array create_array();
bool array_push(Array *stack, void *data);
bool array_set(Array *array, int idx, void *data);
bool array_is_full(const Array *array);
bool array_is_empty(const Array *array);
void *array_get(const Array *array, int idx);

#endif
