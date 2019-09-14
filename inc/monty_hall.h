#ifndef __MONTY_HALL_INCLUDED_H
#define __MONTY_HALL_INCLUDED_H

#include "door.h"
#include "player.h"

typedef struct __game_result_s {
    player_decision_t decision;
    int player_win;
} game_result_t;

game_result_t play_game();

#endif // __MONTY_HALL_INCLUDED_H
