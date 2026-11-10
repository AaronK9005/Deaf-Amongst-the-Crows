#include <stdio.h>
#include <stdlib.h>
#include <time.h>
// #include <errno.h>

#include "util/ansi_wrappers.h"
#include "core.h"
#include "game.h"

#include "states/game_state.h"
#include "states/title_state.h"

#include "util/terminal.h"
#include "ui/terminalui.h"

int main(int argc, char** argv)
{
    game_t game = { 0 };

    game_init(&game, argc, argv);

    game_run(&game);

    game_cleanup(&game);

    return 0;
}

/*
int parse_args(int argc, char** argv, arg_bus_t* arg_bus) {
    if (argc <= 0 || !argv || !arg_bus) return EOF;
    if (argc == 1) return 0;

    char buffer[256] = { 0 };
    int parsed_args = 0;

    for (int i = 1; i < argc; i++) {
        if (argv[i][0] != '-') continue;

        snprintf(buffer, sizeof(buffer), "%s", argv[i]);

        switch (buffer[1]) {
            case 's': {
                const char* arg = argv[i + 1];
                
                errno = 0;
                char* end;
                long long seed = strtoll(arg, &end, 10);

                if (errno = ERANGE) {
                    // overflow
                }

                if (end == arg) {
                    // nothing read
                }

                arg_bus->seed = seed;

                parsed_args++;
                i++;
                break;
            }
        }
    }

    return parsed_args;
}
*/

