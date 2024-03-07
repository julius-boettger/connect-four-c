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

    print_board(board);

    return 0;
}