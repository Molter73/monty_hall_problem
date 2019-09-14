#include "player.h"

const door_t* player_pick_door(const door_t* doors) {
    int p = PICK();

    if (p < 3333) {
        return &doors[0];
    } else if (p < 6666) {
        return &doors[1];
    }
    return &doors[2];
}

const door_t* player_pick_remaining_door(const door_t* doors, const door_t* previous_pick) {
    int i;

    for (i = 0; i < DEFAULT_NUMBER_OF_DOORS; i++) {
        if (doors[i] == CLOSED && &doors[i] != previous_pick)
            return &doors[i];
    }
    return NULL;
}

int player_change_door() {
    int choice = PICK();

    if (choice < 5000) {
        return 0;
    }
    return 1;
}
