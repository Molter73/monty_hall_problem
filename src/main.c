#include <stdio.h>
#include <time.h>

#include "monty_hall.h"

const static int DEFAULT_NUMBER_OF_GAMES_TO_PLAY = 10;

int main(int argc, char const* argv[]) {
    int i;
    int games_player_changed_door = 0, games_player_changed_door_won = 0,
        games_player_kept_door = 0, games_player_kept_door_won = 0;

    srand(time(NULL));

    for (i = 0; i < DEFAULT_NUMBER_OF_GAMES_TO_PLAY; i++) {
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

    printf("Games player: %d\n", i);
    printf("Games player changed door: %d - won: %d\n",
           games_player_changed_door, games_player_changed_door_won);
    printf("Games player kept door: %d - won: %d\n", games_player_kept_door,
           games_player_kept_door_won);

    return 0;
}
