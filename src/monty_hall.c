#include <stdio.h>
#include <stdlib.h>

#include "monty_hall.h"

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

game_result_t play_game() {
    const door_t* winning_door = NULL;
    const door_t* player_door = NULL;
    door_t doors[DEFAULT_NUMBER_OF_DOORS];
    game_result_t result;
    int error;

    printf("Game show starting...\n");

    error = game_start(doors, &winning_door);
    if (error) {
        printf("An error occured during initilization - Error: %d\n", error);
        exit(-1);
    }

    printf("Pick a door\n");

    player_door = player_pick_door(doors);

    error = open_discarded_door(doors, winning_door, player_door);
    if (error < 0) {
        printf("An error occured while discarding a door - Error: %d\n", error);
        exit(-1);
    }

    printf("Do you change your choice?\n");
    if (player_change_door()) {
        printf("YES!!\n");
        player_door = player_pick_remaining_door(doors, player_door);
        if (player_door == NULL) {
            printf("An error occured while changing doors\n");
            exit(-1);
        }
        result.decision = CHANGE_DOOR;
    } else {
        printf("No\n");
        result.decision = KEEP_DOOR;
    }

    if (player_door == winning_door) {
        printf("We have a winner!!\n");
        result.player_win = 1;
    } else {
        printf("You lose - Better luck next time!!\n");
        result.player_win = 0;
    }

    print_endgame(doors, winning_door);

    return result;
}
