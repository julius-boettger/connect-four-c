#include "include/input.h"

#include <stdio.h>

// return column counting from 0.
// returns -1 on error.
int prompt_column () {
    int num;
    if (scanf("%d", &num) == 0) {
        printf("That's not a number! Try again: ", num);
        // wait for new line
        while (fgetc(stdin) != '\n');
        return prompt_column();
    } 
    return num - 1;
}