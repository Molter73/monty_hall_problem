#ifndef __PLAYER_INCLUDED_H
#define __PLAYER_INCLUDED_H

#include "door.h"

typedef enum __player_decision_s { KEEP_DOOR, CHANGE_DOOR } player_decision_t;

typedef enum __game_mode_s { RANDOM, KEEP, CHANGE } game_mode_t;

const door_t* player_pick_door(const door_t* doors);
const door_t* player_pick_remaining_door(const door_t* doors, const door_t*);

int player_change_door();

extern game_mode_t game_mode;

#endif // __PLAYER_INCLUDED_H