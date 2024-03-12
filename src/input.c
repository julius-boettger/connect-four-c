#include "include/input.h"

#include "include/logic.h"
#include <stdio.h>

// return int in given range (borders inclusive).
// returns -1 on error.
static int prompt_int (int min, int max) {
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

// returns non-full column counting from 0
int prompt_valid_column (Field board[HEIGHT][WIDTH], int min, int max) {
    int column = prompt_int(min, max) - 1;
    if (column_is_full(board, column)) {
        printf("That column is already full! Try again: ");
        return prompt_valid_column(board, min, max);
    }
    return column;
}