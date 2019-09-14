#include <stdio.h>

#include "door.h"
#include "print.h"

const static char* door_frame = "+--------";
const static char* door_representation = "|%8.8s";

const static char* door_strings[] = {"GOAT", "CAR", "CLOSED"};

/**
 * @brief Prints a frame for doors
 *
 * Prints the top and bottom frames of doors when using the verbose mode.
 */
void print_frame() {
    int i;
    for (i = 0; i < DEFAULT_NUMBER_OF_DOORS; i++) {
        verbose_print(door_frame);
    }
    verbose_print("+\n");
}

/**
 * @brief Prints doors to console.
 *
 * Prints a representation of the doors on the console.
 *
 * @param doors An array of doors to be printed out into the console.
 */
void print_doors(door_t* doors) {
    int i;
    // Print the frame
    print_frame();

    for (i = 0; i < DEFAULT_NUMBER_OF_DOORS; i++) {
        verbose_print(door_representation, door_strings[doors[i]]);
    }
    verbose_print("|\n");

    print_frame();

    verbose_print("\n");
}

/**
 * @brief Prints with all doors open.
 *
 * Prints a representation of all open doors to the console.
 *
 * @param doors An array of doors to be printed.
 * @param winning_door A pointer to the winning door.
 */
void print_endgame(door_t* doors, const door_t* winning_door) {
    int i;
    for (i = 0; i < DEFAULT_NUMBER_OF_DOORS; i++) {
        if (&doors[i] == winning_door) {
            doors[i] = CAR;
        } else {
            doors[i] = GOAT;
        }
    }
    print_doors(doors);
}
