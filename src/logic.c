#include "include/logic.h"
#include "include/output.h"

#include <stdio.h>

// return game exit status code
int run_game () {
    Field board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = EMPTY;
        }
    }

    board[5][6] = PLAYER2;
    board[4][5] = PLAYER2;
    board[3][4] = PLAYER2;
    board[2][3] = PLAYER2;

    print_board(board);
    printf("Player %d won!\n", check_winner(board));

    return 0;
}

// return -1 if there is no winner
Field check_winner (Field board[HEIGHT][WIDTH]) {
    const Field diagonal_winner = check_diagonals_winner(board);
    if (diagonal_winner != -1) {
        return diagonal_winner;
    }
    const Field row_winner = check_rows_winner(board);
    if (row_winner != -1) {
        return row_winner;
    }
    const Field column_winner = check_columns_winner(board);
    if (column_winner != -1) {
        return column_winner;
    }
    // no winner
    return -1;
}

// return -1 if there is no winner
Field check_rows_winner (Field board[HEIGHT][WIDTH]) {
    // rows: bottom to top
    for (int i = HEIGHT; i >= 0; i--) {
        // start with one for first field
        int fields_in_a_row = 1;
        // columns: left to right
        for (int j = 1; j < WIDTH; j++) {
            if (board[i][j] == EMPTY || board[i][j-1] != board[i][j]) {
                fields_in_a_row = 1;
                continue;
            } 
            if (++fields_in_a_row == CONNECT) {
                return board[i][j];
            }
        }
    }
    // no winner
    return -1;
}

// return -1 if there is no winner
Field check_columns_winner (Field board[HEIGHT][WIDTH]) {
    // columns: left to right
    for (int j = 0; j < WIDTH; j++) {
        // start with one for first field
        int fields_in_a_row = 1;
        // rows: bottom to top
        for (int i = HEIGHT-1; i >= 0; i--) {
            if (board[i][j] == EMPTY || board[i+1][j] != board[i][j]) {
                fields_in_a_row = 1;
                continue;
            } 
            if (++fields_in_a_row == CONNECT) {
                return board[i][j];
            }
        }
    }
    // no winner
    return -1;
}

// return -1 if there is no winner
Field check_diagonals_winner (Field board[HEIGHT][WIDTH]) {
    //// diagonals from bottom left to top right
    // columns: left to right
    for (int j = 0; j < WIDTH-(CONNECT-1); j++) {
        // rows: bottom to top
        for (int i = HEIGHT; i >= HEIGHT-(CONNECT-1); i--) {
            // start with one for first field
            int fields_in_a_row = 1;
            // bottom left to top right
            for (int k = 1; i-k >= 0 && j+k < WIDTH; k++) {
                if (board[i-k][j+k] == EMPTY || board[i-k+1][j+k-1] != board[i-k][j+k]) {
                    fields_in_a_row = 1;
                    continue;
                }
                if (++fields_in_a_row == CONNECT) {
                    return board[i-k][j+k];
                }
            }
        }
    }

    //// diagonals from bottom right to top left
    // columns: right to left
    for (int j = WIDTH; j >= CONNECT-1; j--) {
        // rows: bottom to top
        for (int i = HEIGHT; i >= HEIGHT-(CONNECT-1); i--) {
            // start with one for first field
            int fields_in_a_row = 1;
            // bottom right to top left
            for (int k = 1; i-k >= 0 && j-k >= 0; k++) {
                if (board[i-k][j-k] == EMPTY || board[i-k+1][j-k+1] != board[i-k][j-k]) {
                    fields_in_a_row = 1;
                    continue;
                }
                if (++fields_in_a_row == CONNECT) {
                    return board[i-k][j-k];
                }
            }
        }
    }
    
    // no winner
    return -1;
}