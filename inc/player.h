#ifndef __PLAYER_INCLUDED_H
#define __PLAYER_INCLUDED_H

#include "door.h"

const door_t* pick_door(const door_t* doors);
const door_t* pick_remaining_door(const door_t* doors, const door_t*);

int change_door();

#endif // __PLAYER_INCLUDED_H