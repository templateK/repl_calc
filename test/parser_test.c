#include <stdio.h>
#include <assert.h>
#include <stdbool.h>
#include <string.h>
#include "libparse.h"

int main() {
    char input1[] = "a = 1 + 2";
    char *result = parse_lhs(input1);
    assert(strcmp(result, "a") == 0);

    char input2[] = "123 = 1";
    result = parse_lhs(input2);
    assert(result == NULL);

    char input3[] = "a = b + c";
    result = parse_rhs(input3);
    assert(strcmp(result, " b + c") == 0);

    char input4[] = {'\0'};
    result = parse_rhs(input4);
    assert(result == NULL);

    printf("SUCCESS");


    return 0;
}
