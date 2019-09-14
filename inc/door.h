#ifndef __DOOR_INCLUDED_H
#define __DOOR_INCLUDED_H

#include <stdlib.h>

#define PICK() ((int)(10000 * (rand() / (RAND_MAX + 1.0))))

#define DEFAULT_NUMBER_OF_DOORS ((int)3)

typedef enum __door_e { GOAT, CAR, CLOSED } door_t;

void print_doors(door_t* doors);
void print_endgame(door_t* doors, const door_t* winning_door);

#endif // __DOOR_INCLUDED_H
