#include "states/game_state.h"
#include "states/exit_state.h"
#include "game.h"

// #include <stdio.h>
int printf(const char*, ...);

void exit_state_enter(game_t* game)
{
    (void)game;
}


void exit_state_update(game_t* game)
{
    game->running = false;
}


void exit_state_render(game_t* game)
{
    (void)game;
}


void exit_state_exit(game_t* game)
{
    int total = game->run_stop - game->run_start;

    int hours = total / 3600;
    int minutes = (total % 3600) / 60;
    int seconds = total % 60;

    printf("GAME ENDED: playtime: %02d:%02d:%02d\n", hours, minutes, seconds);
}


const game_state_t _exit_state = {
    .enter = exit_state_enter,
    .update = exit_state_update,
    .render = exit_state_render,
    .exit = exit_state_exit
};


const game_state_t* exit_state = &_exit_state;


