#ifndef DAtC_WORLD_H
#define DAtC_WORLD_H

#include "world/date.h"

typedef struct world_t {
    date_t date;
    // map_t map;
    // forecast_t forecast;
} world_t;

void world_increment_day(world_t* world);

#endif