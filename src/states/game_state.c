#include "states/game_state.h"
#include "game.h"

#include <stddef.h>

void game_change_state(game_t* game, const game_state_t* new_state)
{
    if (!game || !new_state) return;

    if (game->state != NULL && game->state->exit != NULL) {
        game->state->exit(game);
    }

    game->state = new_state;

    if (game->state != NULL && game->state->enter != NULL) {
        game->state->enter(game);
    }
}
