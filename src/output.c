#include "include/output.h"
#include <stdio.h>

void print_winner (Field winner) {
    char* string = field_to_string(&winner);
    printf(
        "%s%s%s Player %d has won! %s%s%s",
        string, string, string,
        winner,
        string, string, string
    );
    printf("\n");
}

void print_board (Field board[HEIGHT][WIDTH]) {
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            printf("%s ", field_to_string(&board[i][j]));
        }
        printf("\n");
    }
}

char* field_to_string (Field* field) {
    switch (*field) {
        case NO_PLAYER:
            return FIELD_CHAR;
        case PLAYER1:
            return ANSI_PLAYER1 FIELD_CHAR ANSI_RESET;
        case PLAYER2:
            return ANSI_PLAYER2 FIELD_CHAR ANSI_RESET;
        default:
            return " ";
    }
}