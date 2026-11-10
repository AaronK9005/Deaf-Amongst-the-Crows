#ifndef DAtC_GAME_H
#define DAtC_GAME_H

// #include <signal.h>

#include <stdbool.h>
#include <time.h>

#include "world/world.h"
#include "colony/colony.h"

typedef struct game_state_t game_state_t;

typedef struct game_t {
    const game_state_t* state;
    world_t world;
    colony_t colony;
    struct {
        time_t run_start;
        time_t run_stop;
        time_t last_loop_time;
    };
    bool running;
} game_t;

void game_init(game_t* game, int argc, char** argv);
void game_run(game_t* game);
void game_cleanup(game_t* game);

// game_change_state in states/game_state.h

#endif