#include <stdio.h>
#include <string.h>
#include <ctype.h>


void somefunc() {
    printf("called somefunc\n");
}

char *parse_lhs(char *str) {
    char *result = strtok(str, " =");
    if (result && isalpha(result[0])) {
        return result;
    }
    return NULL;
}

char *parse_rhs(char *str) {
    char *result = strchr(str, '=');
    if (result) {
        return ++result;
    }
    return NULL;
}
