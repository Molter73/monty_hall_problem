#include <stdio.h>
#include <stdlib.h>

#include "door.h"
#include "monty_hall.h"
#include "player.h"

int main(int argc, char const* argv[]) {
    const door_t* winning_door = NULL;
    const door_t* player_door = NULL;
    door_t doors[DEFAULT_NUMBER_OF_DOORS];
    int error;

    printf("Game show starting...\n");

    error = game_start(doors, &winning_door);
    if (error) {
        printf("An error occured during initilization - Error: %d\n", error);
        exit(-1);
    }

    printf("Pick a door\n");

    player_door = pick_door(doors);

    error = open_discarded_door(doors, winning_door, player_door);
    if (error < 0) {
        printf("An error occured while discarding a door - Error: %d\n", error);
        exit(-1);
    }

    printf("Do you change your choice?\n");
    if (change_door()) {
        printf("YES!!\n");
        player_door = pick_remaining_door(doors, player_door);
        if (player_door == NULL) {
            printf("An error occured while changing doors\n");
            exit(-1);
        }
    } else {
        printf("No\n");
    }

    if (player_door == winning_door) {
        printf("We have a winner!!\n");
    } else {
        printf("You lose - Better luck next time!!\n");
    }

    print_endgame(doors, winning_door);
    return 0;
}
