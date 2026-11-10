#include "states/game_state.h"
#include "states/title_state.h"
#include "states/main_menu_state.h"

#include <time.h> // delta-time
#include <stdbool.h>

#include "game.h"
#include "util/ansi_wrappers.h"
#include "util/large_text.h"
#include "util/terminal.h"

// temporary
// #include <stdio.h> // printf
// #include <stdlib.h> // exit

static double previous_time, current_time;
static double timer = 3.0, accumulator = 0.0;
static const char* game_title = "deaf amongst the crows";

static double get_time()
{
    struct timespec ts;
    clock_gettime(CLOCK_MONOTONIC, &ts);
    
    return ts.tv_sec + ts.tv_nsec / 1e9;
}

void title_state_set_timer(double time_sec) {
    timer = time_sec;
}

void title_state_enter (game_t* game)
{
    ansi_reset();
    ansi_clear_screen();
    ansi_goto_home();
    ansi_hide_cursor();

    accumulator = 0.0;
    previous_time = get_time();
}

void title_state_update (game_t* game)
{
    current_time = get_time();
    double dt = current_time - previous_time;
    previous_time = current_time;

    accumulator += dt;

    if (accumulator >= timer) {
        game_change_state(game, main_menu_state);
        // ansi_reset();
        // printf("ACCUMULATOR: title_state::timer reached\n");
        // fflush(stdout);
        // exit(EXIT_SUCCESS);
    }
}

void title_state_render (game_t* game)
{
    const int grayscale_start = 232;
    const int grayscale_end = 255;

    int color255 = grayscale_start + (double)(grayscale_end - grayscale_start) * (accumulator / timer);

    ansi_256color_fg(color255);
    ansi_goto_home();
    print_large_text_centered_bound(game_title, terminal.width, LL_FULL);
}

void title_state_exit (game_t* game)
{
    // ansi_show_cursor();
    // ansi_reset();
}

const game_state_t _title_state = {
    .enter = title_state_enter,
    .update = title_state_update,
    .render = title_state_render,
    .exit = title_state_exit,
};

const game_state_t* title_state = &_title_state;