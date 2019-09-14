#ifndef __MONTY_HALL_INCLUDED_H
#define __MONTY_HALL_INCLUDED_H

#include "door.h"

int game_start(door_t* doors, const door_t** winning_door);
int open_discarded_door(door_t* doors, const door_t* winning_door, const door_t* player_door);

#endif // __MONTY_HALL_INCLUDED_H
