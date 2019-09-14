/**
 * @mainpage Brute Force Monty Hall Problem Solver
 *
 * @section intro_sec Introduction
 *
 * This is a simple program that solves the Monty Hall problem by using brute
 * force. Please remember to use a large enough number (preferably >100.000) if
 * you want to see real results.
 */

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <string.h>
#include <getopt.h>
#include <stdint.h>

#include "monty_hall.h"
#include "print.h"

const static int DEFAULT_NUMBER_OF_GAMES_TO_PLAY = 1000000;

/**
 * @brief Prints help to console.
 *
 * Prints text to the console, specifying the proper way to run the program.
 */
void print_help() {
    printf("Usage: game [options]\n");
    printf("Options:\n");
    printf("  -h            Display help\n");
    printf("  -v            Display each game played\n");
    printf("  -c <num>      Play the game num times\n");
    printf("  -m {keep|change|random}\n");
    printf("                Specify the game mode to play\n");
}

/**
 * @brief The main entry point.
 *
 * This is where the magic starts.
 *
 * @param argc A integer holding the amount of arguments passed to the program.
 * @param argv An array of strings passed to the program as arguments.
 * @return int Returns 0 if all is well.
 */
int main(int argc, char* argv[]) {
    int32_t i, c;
    uint32_t games_to_play;
    uint32_t games_player_changed_door = 0, games_player_changed_door_won = 0,
             games_player_kept_door = 0, games_player_kept_door_won = 0;

    srand(time(NULL)); // Feed the random number generator.

    // Initialize global variables.
    verbose = 0;
    game_mode = RANDOM;
    games_to_play = DEFAULT_NUMBER_OF_GAMES_TO_PLAY;

    // Get the program options.
    while ((c = getopt(argc, argv, "vc:m:h")) != -1) {
        switch (c) {
        case 'v':
            verbose = -1;
            break;
        case 'c':
            games_to_play = atoi(optarg);
            if (games_to_play == 0) {
                printf("Invalid argument %s for -c\n", optarg);
                print_help();
                return -1;
            }
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

    // Now actually play the game.
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

    // Print out the results.
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
