#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <getopt.h>

#include "monty_hall.h"
#include "print.h"

const static int DEFAULT_NUMBER_OF_GAMES_TO_PLAY = 1000000;

int main(int argc, char* argv[]) {
    int i, c;
    int games_to_play = DEFAULT_NUMBER_OF_GAMES_TO_PLAY;
    int games_player_changed_door = 0, games_player_changed_door_won = 0,
        games_player_kept_door = 0, games_player_kept_door_won = 0;

    srand(time(NULL));

    verbose = 0;

    while ((c = getopt(argc, argv, "vc:")) != -1) {
        switch (c) {
        case 'v':
            verbose = -1;
            break;
        case 'c':
            games_to_play = atoi(optarg);
            break;
        default:
            break;
        }
    }

    for (i = 0; i < games_to_play; i++) {
        game_result_t result = play_game();

        if (result.decision == KEEP_DOOR) {
            games_player_kept_door++;

            if (result.player_win)
                games_player_kept_door_won++;
        } else {
            games_player_changed_door++;

            if (result.player_win)
                games_player_changed_door_won++;
        }
    }

    printf("Games played: %d\n", i);
    printf("Games player changed door: %d - won: %d\n",
           games_player_changed_door, games_player_changed_door_won);
    printf("Games player kept door: %d - won: %d\n", games_player_kept_door,
           games_player_kept_door_won);

    return 0;
}
