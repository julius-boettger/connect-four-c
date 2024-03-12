#ifndef LOGIC_H
#define LOGIC_H

#include "board.h"
#include <stdbool.h>

#define CONNECT 4

int run_game ();
bool column_is_full (Field board[HEIGHT][WIDTH], int column);

#endif