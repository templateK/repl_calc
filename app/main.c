#include <stdio.h>
#include "libparse.h"
#include "libarray.h"

int main(int argc, char **argv) {
    /* char *input_fixed = "A + B"; */
    /* Array array = infix2postfix(input_fixed); */
    /* display_array(&array); */

    for (int i = 1; i < argc; i++) {
        char *input = argv[i];
        printf("input %-20s => ", input);
        Array array1 = infix2postfix(input);
        display_array(&array1);
    }
    return 0;
}

