#include <stdio.h>

#include "door.h"
#include "print.h"

const static char* door_frame = "+--------";
const static char* door_representation = "|%8.8s";

const static char* door_strings[] = {"GOAT", "CAR", "CLOSED"};

void print_frame() {
    int i;
    for (i = 0; i < DEFAULT_NUMBER_OF_DOORS; i++) {
        verbose_print(door_frame);
    }
    verbose_print("+\n");
}

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
