#include "include/logic.h"
#include "include/board.h"
#include "include/output.h"

int run_game () {
    Field board[HEIGHT][WIDTH];
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            board[i][j] = EMPTY;
        }
    }

    board[5][0] = PLAYER1;
    board[5][1] = PLAYER2;

    print_board(board);

    return 0;
}