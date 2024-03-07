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

void print_prompt (Field* current_player);
void print_winner (Field winner);
void print_board (Field board[HEIGHT][WIDTH]);
char* field_to_string (Field* field);

#endif