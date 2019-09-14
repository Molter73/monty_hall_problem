#ifndef __MONTY_HALL_INCLUDED_H
#define __MONTY_HALL_INCLUDED_H

#include "door.h"
#include "player.h"

/// A structure holding information used for statistics.
typedef struct __game_result_s {
    player_decision_t decision; ///< Informs wheter the player changed it's pick.
    int player_win;             ///< 0 if the player lost.
} game_result_t;

int play_game(game_result_t* result);

#endif // __MONTY_HALL_INCLUDED_H
