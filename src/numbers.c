#include "util/numbers.h"
#include <stdlib.h>

int r_int(int max) {
    return rand() % max;
}

int r_irange(int min, int max) {
    if (max > min) {
        int temp = min;
        min = max;
        max = temp;
    }

    return (rand() % (max - min + 1)) + min;
}

/**
 * @brief Returns a per-thousand chance (0 - 999)
 * 
 * @return 0 - 999
 */
int r_chance() {
    return rand() % 1000;
}

int r_min(int x, int y) {
    return x < y ? x : y;
}

int r_max(int x, int y) {
    return x > y ? x : y;
}

