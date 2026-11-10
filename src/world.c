#include "world/world.h"

void world_increment_day(world_t* world) {
    if (!world) return;

    world->date.day++;
    world->date.weekday = (world->date.weekday + 1) % WDAY_COUNT;
}