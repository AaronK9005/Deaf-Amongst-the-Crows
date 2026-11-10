#include "states/game_state.h"
#include "states/playing_state.h"
#include "game.h"

#include "util/ansi_wrappers.h"

static game_state_t* gameplay_state;

enum OPTIONS {
    CITIZENS,
    EXPEDITIONS,
    REPORTS,
    DIARY,
    OPT_COUNT
};

void playing_state_enter(game_t* game)
{
    ansi_clear_screen();
    ansi_goto_home();
    ansi_hide_cursor();

    colony_print(&game->colony, game->world.date.day);
}


void playing_state_update(game_t* game)
{
    (void)game;
}


void playing_state_render(game_t* game)
{
    (void)game;
}


void playing_state_exit(game_t* game)
{
    (void)game;
}


const game_state_t _playing_state = {
    .enter = playing_state_enter,
    .update = playing_state_update,
    .render = playing_state_render,
    .exit = playing_state_exit
};


const game_state_t* playing_state = &_playing_state;


