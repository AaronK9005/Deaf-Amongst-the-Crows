#include "game.h"
#include "colony/colony.h"
#include "world/world.h"
#include "util/terminal.h"

#include "states/game_state.h"
#include "states/title_state.h"
#include "states/main_menu_state.h"

#include "util/ansi_wrappers.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include <unistd.h>
#include "menus/menu.h"

#pragma region flags

typedef struct _flags {
    bool skip_title; // -n
} flags_t;

const flags_t DEFAULT_FLAGS = {
    .skip_title = false
};

void parse_clargs(int argc, char** argv, flags_t* f) {
    int opt;

    while ((opt = getopt(argc, argv, "n")) != -1)
    {
        switch (opt) {
            case 'n': // no title
                f->skip_title = true;
                break;
            default:
                printf("Usage: %s [-n no-title]\n", argv[0]);
                break;
        }
    }
    
}

#pragma endregion

void game_init(game_t* game, int argc, char** argv)
{
    atexit(ansi_reset);
    atexit(ansi_show_cursor);
    atexit(ansi_clear_screen);

    if (!game) return;

    update_terminal_size();

    flags_t flags = DEFAULT_FLAGS;

    parse_clargs(argc, argv, &flags);
    srand(time(NULL));
    
    game->running = true;

    if (flags.skip_title) {
        game_change_state(game, main_menu_state);
    }
    else {   
        game_change_state(game, title_state);
    }
}

void game_run(game_t* game)
{
    if (!game) return;

    time_t run_start = time(NULL);
    game->run_start = run_start;

    while (game->running)
    {
        time_t loop_start = time(NULL);

        if (game->state->update != NULL) {
            game->state->update(game);
        }

        // update_terminal_size();

        if (game->state->render != NULL) {
            game->state->render(game);
        }

        time_t loop_end = time(NULL);

        time_t loop_time = loop_end - loop_start;
        game->run_start += loop_time;
        game->last_loop_time = loop_time;
    }

    game->run_stop = time(NULL);
}

void game_cleanup(game_t* game) {
    if (!game) return;

    if (game->state->exit != NULL) {
        game->state->exit(game);
    }
}
