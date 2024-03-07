#include "include/output.h"
#include <stdio.h>

// winner can be NO_PLAYER (meaning no one has won yet)
void print_status (Field winner) {
    if (winner == NO_PLAYER) {
        printf("No one has won yet...\n");
        return;
    }
    printf("Player %d (", winner);
    print_field(&winner);
    printf(") has won!\n");
}

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
    switch (*field) {
        case NO_PLAYER:
            printf(FIELD_CHAR);
            break;
        case PLAYER1:
            printf("%s%s%s", ANSI_PLAYER1, FIELD_CHAR, ANSI_RESET);
            break;
        case PLAYER2:
            printf("%s%s%s", ANSI_PLAYER2, FIELD_CHAR, ANSI_RESET);
            break;
        default:
            printf(" ");
            break;
    }
}