#include "include/input.h"

#include <stdio.h>

// return int in given range (borders inclusive).
// returns -1 on error.
int prompt_int (int min, int max) {
    int num;
    if (scanf("%d", &num) == 0) {
        printf("That's not a number! Try again: ");
        // wait for new line
        while (fgetc(stdin) != '\n');
        return prompt_int(min, max);
    }
    if (num < min || num > max) {
        printf("Your number is out of range (%d to %d), try again: ", min, max);
        return prompt_int(min, max);
    }
    return num;
}