#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include "libarray.h"

Array create_array() {
    Array sp = {.end = -1};
    return sp;
}

bool array_push(Array *array, void *data) {
    if (array_is_full(array)) {
        return false;
    }
    array->end++;
    array->arr[array->end] = data;
    return true;
}

bool array_set(Array *array, int idx, void *data) {
    if ( idx < 0 || idx > array->end) {
        return false;
    }
    array->arr[idx] = data;
    return true;
}

bool array_is_full(const Array *array) {
    return array->end == BUF_SIZE;
}

bool array_is_empty(const Array *array) {
    return array->end == -1;
}

void *array_get(const Array *array, int idx) {
    if ( idx < 0 || idx > array->end) {
        return NULL;
    }
    return array->arr[idx];
}
