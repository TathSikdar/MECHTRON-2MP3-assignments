#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
#include <string.h>
#include <stdlib.h>

int simpleParse(const char *exp);



int main() {
    char exp1[] = "1 + 1";
    char exp2[] = "3 + 7 - 4 * 1";
    char exp3[] = "9 * 13 / 2 + 18 * 110 - 812 % 97 + 3";
    
    //printf("%s = %d\n", exp1, simpleParse(exp1));
    //printf("%s = %d\n", exp2, simpleParse(exp2));
    //printf("%s = %d\n", exp3, simpleParse(exp3));
}