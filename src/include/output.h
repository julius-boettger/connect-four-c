#ifndef OUTPUT_H
#define OUTPUT_H

#include "board.h"

//// ansi color codes
#define ANSI_RESET   "\x1B[0m"
// yellow
#define ANSI_PLAYER1 "\x1B[33m"
// red
#define ANSI_PLAYER2 "\x1B[31m"

// unicode circle
#define FIELD_CHAR "\u25CF"

void print_status (Field winner);
void print_board (Field board[HEIGHT][WIDTH]);
void print_field (Field* field);

#endif