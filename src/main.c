#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdint.h>

#include "monty_hall.h"
#include "print.h"

const static int DEFAULT_NUMBER_OF_GAMES_TO_PLAY = 1000000;

void print_help() {
    printf("Usage: game [options]\n");
    printf("Options:\n");
    printf("  -h            Display help\n");
    printf("  -v            Display each game played\n");
    printf("  -c <num>      Play the game num times\n");
    printf("  -m {keep|change|random}\n");
    printf("                Specify the game mode to play\n");
}

int main(int argc, char* argv[]) {
    int32_t i, c;
    uint32_t games_to_play;
    uint32_t games_player_changed_door = 0, games_player_changed_door_won = 0,
             games_player_kept_door = 0, games_player_kept_door_won = 0;

    srand(time(NULL));

    verbose = 0;
    game_mode = RANDOM;
    games_to_play = DEFAULT_NUMBER_OF_GAMES_TO_PLAY;

    while ((c = getopt(argc, argv, "vc:m:h")) != -1) {
        switch (c) {
        case 'v':
            verbose = -1;
            break;
        case 'c':
            games_to_play = atoi(optarg);
            break;
        case 'm':
            if (!strcmp(optarg, "keep")) {
                game_mode = KEEP;
            } else if (!strcmp(optarg, "change")) {
                game_mode = CHANGE;
            } else if (!strcmp(optarg, "random")) {
                break;
            } else {
                printf("Invalid argument %s for -m\n", optarg);
                print_help();
                return -1;
            }
            break;
        case 'h':
            print_help();
            return 0;
        case '?':
            print_help();
            return -1;
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
    if (game_mode == RANDOM || game_mode == CHANGE) {
        printf("Games player changed door: %d - won: %d - perc: %f%%\n",
               games_player_changed_door, games_player_changed_door_won,
               ((double)games_player_changed_door_won / ((double)games_player_changed_door)) * 100);
    }
    if (game_mode == RANDOM || game_mode == KEEP) {
        printf("Games player kept door: %d - won: %d - perc: %f%%\n",
               games_player_kept_door, games_player_kept_door_won,
               ((double)games_player_kept_door_won / (double)games_player_kept_door) * 100);
    }
    return 0;
}
