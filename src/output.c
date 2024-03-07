#include "include/output.h"
#include <stdio.h>

void print_board (Field board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            print_field(&board[i][j]);
            printf(" ");
        }
        printf("\n");
    }
}

void print_field (Field* field) {
    // ansi color codes
    #define RESET  "\x1B[0m"
    #define RED    "\x1B[31m"
    #define YELLOW "\x1B[33m"
    // unicode circle
    #define CIRCLE "\u25CF"

    switch (*field) {
        case NO_PLAYER:
            printf(CIRCLE);
            break;
        case PLAYER1:
            printf("%s%s%s", YELLOW, CIRCLE, RESET);
            break;
        case PLAYER2:
            printf("%s%s%s", RED, CIRCLE, RESET);
            break;
        default:
            printf(" ");
            break;
    }
}