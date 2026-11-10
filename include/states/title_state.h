#ifndef DAtC_TITLE_STATE_H
#define DAtC_TITLE_STATE_H

typedef struct game_state_t game_state_t;

extern const game_state_t* title_state;

void title_state_set_timer(double time_sec);

#endif