#include "states/game_state.h"
#include "states/load_game_state.h"
#include "states/exit_state.h"
#include "game.h"

#include "util/ansi_wrappers.h"
#include "util/terminal.h"

// temp
#include <string.h>
#include <conio.h>

void load_game_state_enter(game_t* game)
{
    (void)game;

    ansi_clear_screen();
    ansi_goto_home();
    ansi_show_cursor();

    const char* msg = "'load_game_state' not implemented. Redirecting to a new game";
    const char* msg2 = "Press any key to continue ";

    int len = strlen(msg);
    const int offset_x = (terminal.width - len) / 2;
    const int offset_y = 5;

    int len2 = strlen(msg2);
    const int offset_x_2 = (terminal.width - len2) / 2;
    const int offset_y_2 = offset_y + 1;

    ansi_mvprintf(offset_x, offset_y, msg);
    ansi_mvprintf(offset_x_2, offset_y_2, msg2);
}


void load_game_state_update(game_t* game)
{
    (void)game;
    _getch();

    game_change_state(game, exit_state);

    // game_change_state(game, )
}


void load_game_state_render(game_t* game)
{
    (void)game;
}


void load_game_state_exit(game_t* game)
{
    (void)game;
}


const game_state_t _load_game_state = {
    .enter = load_game_state_enter,
    .update = load_game_state_update,
    .render = load_game_state_render,
    .exit = load_game_state_exit
};


const game_state_t* load_game_state = &_load_game_state;


