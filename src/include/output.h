#ifndef OUTPUT_H
#define OUTPUT_H

#include "board.h"

//// ansi color codes
#define ANSI_RESET   "\x1B[0m"
// yellow
#define ANSI_PLAYER1 "\x1B[33m"
// red
#define ANSI_PLAYER2 "\x1B[31m"

// unicode circle doesn't work on windows,
// so don't use it there
#ifdef _WIN32
    #define FIELD_CHAR "o"
#else
    #define FIELD_CHAR "\u25CF"
#endif

void print_prompt (Field board[HEIGHT][WIDTH], Field* current_player);
void print_winner (Field winner);
void print_board (Field board[HEIGHT][WIDTH]);
char* field_to_string (Field* field);

#endif