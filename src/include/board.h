#ifndef BOARD_H
#define BOARD_H

#define WIDTH 7
#define HEIGHT 6

typedef enum {
    // empty field or result of winner check
    NO_PLAYER,
    PLAYER1,
    PLAYER2,
} Field;

#endif