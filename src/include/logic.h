#ifndef LOGIC_H
#define LOGIC_H

#include "board.h"

#define CONNECT 4

int run_game ();
Field check_winner (Field board[HEIGHT][WIDTH]);
Field check_rows_winner (Field board[HEIGHT][WIDTH]);
Field check_columns_winner (Field board[HEIGHT][WIDTH]);
Field check_diagonals_winner (Field board[HEIGHT][WIDTH]);

#endif