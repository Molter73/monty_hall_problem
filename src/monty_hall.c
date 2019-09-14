#include <time.h>

#include "monty_hall.h"

int game_start(door_t* doors, const door_t* winning_door[]) {
    int i;

    srand(time(NULL));

    // garantee that all doors are losing by default
    for (i = 0; i < DEFAULT_NUMBER_OF_DOORS; i++)
        doors[i] = CLOSED;

    int p = PICK();

    if (p < 3333) {
        *winning_door = &doors[0];
    } else if (p < 6666) {
        *winning_door = &doors[1];
    } else {
        *winning_door = &doors[2];
    }

    print_doors(doors);

    return 0;
}

int open_discarded_door(door_t* doors, const door_t* winning_door, const door_t* player_door) {
    int i;
    // Find a close door that is not the player pick or the winning one
    for (i = 0; i < DEFAULT_NUMBER_OF_DOORS; i++) {
        if (&doors[i] != winning_door && &doors[i] != player_door && doors[i] == CLOSED) {
            doors[i] = GOAT; // Discard the door
            print_doors(doors);
            return 0;
        }
    }
    return -1;
}
