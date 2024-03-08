#ifndef LOGIC_H
#define LOGIC_H

#include "board.h"
#include <stdbool.h>

#define CONNECT 4

int run_game ();
bool is_draw(Field board[HEIGHT][WIDTH]);
bool column_is_full (Field board[HEIGHT][WIDTH], int column);
void place_token(Field board[HEIGHT][WIDTH], Field* player, int column);
Field check_winner (Field board[HEIGHT][WIDTH]);
Field check_rows_winner (Field board[HEIGHT][WIDTH]);
Field check_columns_winner (Field board[HEIGHT][WIDTH]);
Field check_diagonals_winner (Field board[HEIGHT][WIDTH]);

#endif