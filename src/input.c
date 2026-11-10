#include "util/input.h"

#include <conio.h>

int get_input() {
    if (!_kbhit()) return INPUT_NONE;

    int c = _getch();

    if ((c == EXTENDED_KEY_PREFIX || c == 0)  && _kbhit()) {
        switch (_getch())
        {
        case ARROW_UP: return INPUT_ARROW_UP;
        case ARROW_LEFT: return INPUT_ARROW_LEFT;
        case ARROW_DOWN: return INPUT_ARROW_DOWN;
        case ARROW_RIGHT: return INPUT_ARROW_RIGHT;
        
        default:
            break;
    }
    }
}