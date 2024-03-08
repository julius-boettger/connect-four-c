#include "include/logic.h"
#include "include/input.h"
#include "include/output.h"

#include <stdio.h>

// return game exit status code
int run_game () {
    // init game
    Field winner = NO_PLAYER;
    Field current_player = PLAYER2;
    Field board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = NO_PLAYER;
        }
    }

    // game loop
    while (true) {
        // clear console (seems to work on linux and windows 10...?)
        printf("\e[1;1H\e[2J");

        print_board(board);
        // check board
        winner = check_winner(board);
        if (winner != NO_PLAYER) {
            print_winner(winner);
            break;
        }
        if (is_draw(board)) {
            printf("It's a draw!\n");
            break;
        }
        // switch player
        current_player = current_player == PLAYER1 ? PLAYER2 : PLAYER1;
        // print input prompt
        print_prompt(board, &current_player);
        // prompt input and make move
        int column = prompt_valid_column(board, 1, WIDTH);
        place_token(board, &current_player, column);
    }

    return 0;
}

// assumes column exists, counts from 0 and has a free space
void place_token (Field board[HEIGHT][WIDTH], Field* player, int column) {
    // rows: bottom to top
    for (int i = HEIGHT-1; i >= 0; i--) {
        if (board[i][column] == NO_PLAYER) {
            board[i][column] = *player;
            return;
        }
    }
}

bool is_draw (Field board[HEIGHT][WIDTH]) {
    // columns: left to right
    for (int j = 0; j < WIDTH; j++) {
        if (!column_is_full(board, j)) {
            return false;
        }
    }
    return true;
}

// column counts from 0
bool column_is_full (Field board[HEIGHT][WIDTH], int column) {
    return board[0][column] != NO_PLAYER;
}

// return NO_PLAYER if there is no winner
Field check_winner (Field board[HEIGHT][WIDTH]) {
    const Field diagonal_winner = check_diagonals_winner(board);
    if (diagonal_winner != NO_PLAYER) {
        return diagonal_winner;
    }
    const Field row_winner = check_rows_winner(board);
    if (row_winner != NO_PLAYER) {
        return row_winner;
    }
    const Field column_winner = check_columns_winner(board);
    if (column_winner != NO_PLAYER) {
        return column_winner;
    }
    return NO_PLAYER;
}

// return NO_PLAYER if there is no winner
Field check_rows_winner (Field board[HEIGHT][WIDTH]) {
    // rows: bottom to top
    for (int i = HEIGHT-1; i >= 0; i--) {
        // start with one for first field
        int fields_in_a_row = 1;
        // columns: left to right
        for (int j = 1; j < WIDTH; j++) {
            if (board[i][j] == NO_PLAYER || board[i][j-1] != board[i][j]) {
                fields_in_a_row = 1;
                continue;
            } 
            if (++fields_in_a_row == CONNECT) {
                return board[i][j];
            }
        }
    }
    return NO_PLAYER;
}

// return NO_PLAYER if there is no winner
Field check_columns_winner (Field board[HEIGHT][WIDTH]) {
    // columns: left to right
    for (int j = 0; j < WIDTH; j++) {
        // start with one for first field
        int fields_in_a_row = 1;
        // rows: bottom to top
        for (int i = HEIGHT-1; i >= 0; i--) {
            if (board[i][j] == NO_PLAYER || board[i+1][j] != board[i][j]) {
                fields_in_a_row = 1;
                continue;
            } 
            if (++fields_in_a_row == CONNECT) {
                return board[i][j];
            }
        }
    }
    return NO_PLAYER;
}

// return NO_PLAYER if there is no winner
Field check_diagonals_winner (Field board[HEIGHT][WIDTH]) {
    //// diagonals from bottom left to top right
    // columns: left to right
    for (int j = 0; j < WIDTH-(CONNECT-1); j++) {
        // rows: bottom to top
        for (int i = HEIGHT-1; i >= HEIGHT-(CONNECT-1); i--) {
            // start with one for first field
            int fields_in_a_row = 1;
            // bottom left to top right
            for (int k = 1; i-k >= 0 && j+k < WIDTH; k++) {
                if (board[i-k][j+k] == NO_PLAYER || board[i-k+1][j+k-1] != board[i-k][j+k]) {
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
    for (int j = WIDTH-1; j >= CONNECT-1; j--) {
        // rows: bottom to top
        for (int i = HEIGHT-1; i >= HEIGHT-(CONNECT-1); i--) {
            // start with one for first field
            int fields_in_a_row = 1;
            // bottom right to top left
            for (int k = 1; i-k >= 0 && j-k >= 0; k++) {
                if (board[i-k][j-k] == NO_PLAYER || board[i-k+1][j-k+1] != board[i-k][j-k]) {
                    fields_in_a_row = 1;
                    continue;
                }
                if (++fields_in_a_row == CONNECT) {
                    return board[i-k][j-k];
                }
            }
        }
    }

    return NO_PLAYER;
}