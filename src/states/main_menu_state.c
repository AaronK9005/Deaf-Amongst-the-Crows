#include "states/game_state.h"
#include "states/main_menu_state.h"
#include "states/load_game_state.h"
#include "states/exit_state.h"
#include "game.h"
#include "util/ansi_wrappers.h"

#include <stdbool.h>
#include <string.h>
#include <ctype.h>
#include "core.h"
#include "util/terminal.h"
#include "ui/terminalui.h"
#include "util/large_text.h"
#include "util/input.h"

#pragma region options

enum OPTIONS {
    NEW_GAME = 0,
    LOAD_GAME,
    SETTINGS,
    QUIT,
    opt_len
};

static const char* const labels[opt_len] = {
    [NEW_GAME] = "New game",
    [SETTINGS] = "Settings",
    [QUIT] = "Quit",
    [LOAD_GAME] = "Saved games"
};

static char const keybinds[opt_len] = {
    [NEW_GAME] = 'n',
    [SETTINGS] = 't',
    [QUIT] = 'q',
    [LOAD_GAME] = 'l'
};

#pragma endregion

#pragma region index

static int current_index = 0;
static int old_index = 0;
static bool render = false;

static int selected_color = COLOR_BLUE;

#define UP (-1)
#define DOWN 1
static void index_scroll(int n) {
    // old_index = current_index;
    // current_index = (current_index + opt_len + n) % opt_len;
    // if (old_index != current_index) render = true;
    old_index = current_index;
    
    current_index += n;
    if (current_index < 0) current_index = 0;
    else if (current_index >= opt_len) current_index = opt_len - 1;

    if (old_index != current_index) render = true;
}

#pragma endregion

#pragma region other funcs

static void draw() {
    const char* title = "MAIN MENU";

    nendl(2);

    // ui_print_centered(title);
    // endl();

    print_large_text_centered_bound(title, terminal.width, LL_FULL);
    nendl(2);
    ansi_save_pos();

    for (int i = 0; i < opt_len; i++) {
        if (i == current_index) ansi_set_color_unchecked(selected_color);
        ui_print_centered(labels[i]);
        if (i == current_index) ansi_reset();
    }
}

#pragma endregion

void main_menu_state_enter(game_t* game)
{
    (void)game;
    ansi_clear_screen();
    ansi_goto_home();
    ansi_hide_cursor();

    draw();
}

void main_menu_state_update(game_t* game)
{
    int input = get_input();

    switch (input) {
        case INPUT_NONE: break;
        case INPUT_ARROW_UP:
        case 'w':
        case 'W':
            index_scroll(UP);
        when INPUT_ARROW_DOWN:
        case 's':
        case 'S':
            index_scroll(DOWN);
        when '\r':
        case '\n':
            if (current_index == NEW_GAME) {

            }
            else if (current_index == SETTINGS) {

            }
            else if (current_index == QUIT) {
                game_change_state(game, exit_state);
            }
            else if (current_index == LOAD_GAME) {
                game_change_state(game, load_game_state);
            }
            else {

            }
            break;
        default:
            for (int i = 0; i < opt_len; i++) {
                if (tolower(input) == keybinds[i]) {
                    const int offset = i - current_index;
                    index_scroll(offset);
                    break;
                }
            }
            break;
    }
}

void main_menu_state_render(game_t* game)
{
    (void)game;
    ansi_goto_home();
    if (!render) {
        return;
    }

    render = false;

    ansi_use_pos();
    ansi_down(old_index);
    ui_print_centered(labels[old_index]);

    ansi_use_pos();
    ansi_down(current_index);
    ansi_set_color(selected_color);
    ui_print_centered(labels[current_index]);
    ansi_reset();
}

void main_menu_state_exit(game_t* game)
{
    (void)game;
}

const game_state_t _main_menu_state = {
    .enter = main_menu_state_enter,
    .update = main_menu_state_update,
    .render = main_menu_state_render,
    .exit = main_menu_state_exit
};

const game_state_t* main_menu_state = &_main_menu_state;

