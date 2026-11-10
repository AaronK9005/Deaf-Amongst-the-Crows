#ifndef DAtC_GAMESTATE_H
#define DAtC_GAMESTATE_H

typedef struct game_t game_t;

typedef struct game_state_t {
    void (*enter)(game_t* game);
    void (*update)(game_t* game);
    void (*render)(game_t* game);
    void (*exit)(game_t* game);
} game_state_t;

void game_change_state(game_t* game, const game_state_t* new_state);

#endif