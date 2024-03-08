#ifndef INPUT_H
#define INPUT_H

#include "board.h"

int prompt_int(int min, int max);
int prompt_valid_column (Field board[HEIGHT][WIDTH], int min, int max);

#endif