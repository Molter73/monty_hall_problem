#include "player.h"

/// A variable describing what will be the player strategy for the games it plays.
game_mode_t game_mode;

/**
 * @brief Picks a door at random.
 *
 * A door is picked from the array passed as a parameter and it's address is
 * returned.
 *
 * @param doors An array of doors to pick from.
 * @return const door_t* A pointer to the chosen door.
 */
const door_t* player_pick_door(const door_t* doors) {
    int p = PICK();

    if (p < 3333) {
        return &doors[0];
    } else if (p < 6666) {
        return &doors[1];
    }
    return &doors[2];
}

/**
 * @brief Picks a door that is neither picked, nor open (not closed)
 *
 * In a scenario with just 3 doors, this function returns the door that is left
 * after one of the doors is openned.
 *
 * @param doors An array of doors to choose from.
 * @param previous_pick A pointer to the previously selected door.
 * @return const door_t* A pointer to the newly selected door.
 */
const door_t* player_pick_remaining_door(const door_t* doors, const door_t* previous_pick) {
    int i;

    for (i = 0; i < DEFAULT_NUMBER_OF_DOORS; i++) {
        if (doors[i] == CLOSED && &doors[i] != previous_pick)
            return &doors[i];
    }
    return NULL;
}

/**
 * @brief Decides whether the player should change doors.
 *
 * The decision is based on the value of the game_mode variable.
 *      - CHANGE: will always change the door chosen.
 *      - KEEP: will always keep the door chosen.
 *      - RANDOM: will change doors on a 50-50 chance.
 *
 * @return int 0 if the door chosen is kept, 1 otherwise.
 */
int player_change_door() {
    switch (game_mode) {
    case CHANGE:
        return 1;
    case KEEP:
        return 0;
    case RANDOM:
    default:
        if (PICK() < 5000) {
            return 0;
        }
        return 1;
    }
}
