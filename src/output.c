#include "include/output.h"
#include <stdio.h>

static void print_field (Field* field) {
    printf("%d", *field);
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