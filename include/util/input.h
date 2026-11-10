#ifndef DAtC_INPUT_H
#define DAtC_INPUT_H

enum {
    INPUT_NONE = 0,
    INPUT_ARROW_UP = 1,
    INPUT_ARROW_LEFT,
    INPUT_ARROW_DOWN,
    INPUT_ARROW_RIGHT
};

#define EXTENDED_KEY_PREFIX 224
#define ARROW_UP 72
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_DOWN 80

/**
 * @brief Get input. Nonblocking
 * 
 * @return one input like key or arrows, `0` if none
 */
int get_input();

#endif