#include <stdio.h>
#include <stdlib.h>

#include "monty_hall.h"
#include "print.h"

/**
 * @brief Initializes doors for the next game.
 *
 * Initializes all doors as closed and picks one at random to be used as the
 * winning door.
 *
 * @param doors An array of doors to be initialized.
 * @param winning_door A pointer to the door that will win the game.
 * @return int Returns 0 always.
 */
int game_start(door_t* doors, const door_t* winning_door[]) {
    int i;

    // garantee that all doors are closed by default
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

/**
 * @brief Reveals one of the doors as having a goat.
 *
 * Takes in an array of doors, decides which door is neither the winning, nor
 * the player picked door and reveals that it holds a goat behind it.
 *
 * @param doors An array of doors to search through.
 * @param winning_door A pointer to the winning door.
 * @param player_door A pointer to the door picked by the player.
 * @return int Returns 0 if it was able to discard a door, -1 otherwise.
 */
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

/**
 * @brief Plays the Monty Hall game
 *
 * This is where the game is actually played.
 *
 * It first initializes 3 closed doors and picks one to be the winner.
 *
 * The player then chooses a door. The door that is not chosen and is not the
 * winning door gets immediately discarded.
 *
 * The player gets a chance to change it's mind before revealing if it's door
 * is the winner.
 *
 * The winning door is never passed to the player_* functions, thus
 * representing this information as being hidden from the player, just as in real life.
 *
 * The result of the game is saved in the result structure for later analysis and statistics.
 *
 * @param result A structure holding information about the game that was just played.
 * @return 0 if all is well, -1 otherwise.
 */
int play_game(game_result_t* result) {
    const door_t* winning_door = NULL;
    const door_t* player_door = NULL;
    door_t doors[DEFAULT_NUMBER_OF_DOORS];
    int error;

    verbose_print("Game show starting...\n");

    error = game_start(doors, &winning_door);
    if (error) {
        verbose_print("An error occured during initilization - Error: %d\n", error);
        return -1;
    }

    verbose_print("Pick a door\n");

    player_door = player_pick_door(doors);

    error = open_discarded_door(doors, winning_door, player_door);
    if (error < 0) {
        verbose_print("An error occured while discarding a door - Error: %d\n", error);
        return -1;
    }

    verbose_print("Do you change your choice?\n");
    if (player_change_door()) {
        verbose_print("YES!!\n");
        player_door = player_pick_remaining_door(doors, player_door);
        if (player_door == NULL) {
            verbose_print("An error occured while changing doors\n");
            return -1;
        }
        result->decision = CHANGE_DOOR;
    } else {
        verbose_print("No\n");
        result->decision = KEEP_DOOR;
    }

    if (player_door == winning_door) {
        verbose_print("We have a winner!!\n");
        result->player_win = 1;
    } else {
        verbose_print("You lose - Better luck next time!!\n");
        result->player_win = 0;
    }

    print_endgame(doors, winning_door);

    return 0;
}
