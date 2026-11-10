cmake_minimum_required(VERSION 3.10.0)
project(DeafAmongsttheCrows_VS VERSION 0.1.0 LANGUAGES C)

add_executable(game
    src/main.c
    src/my_string.c
    src/colony.c
    src/world.c
    src/game.c
    src/numbers.c
    src/ansi_wrappers.c
    src/menu.c
    src/large_text.c
    src/states/title_state.c
    src/states/game_state.c
    src/terminal.c
    src/states/main_menu_state.c
    src/states/exit_state.c
    src/input.c
    src/terminalui.c
    src/states/load_game_state.c
    src/states/playing_state.c
)

target_include_directories(game PRIVATE include)