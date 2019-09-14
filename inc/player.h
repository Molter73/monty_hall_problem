#ifndef __PLAYER_INCLUDED_H
#define __PLAYER_INCLUDED_H

#include "door.h"

typedef enum __player_decision_s { KEEP_DOOR, CHANGE_DOOR } player_decision_t;

const door_t* player_pick_door(const door_t* doors);
const door_t* player_pick_remaining_door(const door_t* doors, const door_t*);

int player_change_door();

#endif // __PLAYER_INCLUDED_H