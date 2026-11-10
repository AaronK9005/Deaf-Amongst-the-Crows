#include "colony/colony.h"

#include <stdio.h>
#include <stdlib.h>

#include "core.h"
#include "util/numbers.h"
#include "colony/citizen.h"

int colony_init(colony_t* colony) {
    if (!colony) return RET_FAIL;

    colony->resources = (resources_t){
        .food = 10,
        .water = 10,
        .shelter = 10,
        .wood = 10
    };

    const int start_cap = 16;
    const int start_pop = 2;

    citizen_t* cit_array = calloc(start_cap, sizeof(citizen_t));
    if (!cit_array) return RET_FAIL;

    colony->population = (population_t){
        .citizens = cit_array,
        .count = start_pop,
        .cap = start_cap
    };

    for (int i = 0; i < start_pop; i++) {
        // todo: add citizen
    }

    return RET_OK;
}

int colony_finish(colony_t* colony) {
    if (!colony) return RET_FAIL;

    if (colony->population.citizens) {
        free(colony->population.citizens);
        colony->population.citizens = NULL;
    }

    return RET_OK;
}

bool colony_is_alive(colony_t* colony) {
    return  colony && 
            colony->population.count > 0 &&
            colony->resources.food > 0 &&
            colony->resources.water > 0;
}

void colony_consume_resources(colony_t* colony) {
    if (!colony) return;

    int count = colony->population.count;

    colony->resources.food -= count;
    colony->resources.water -= count;
}

void colony_add_citizen(colony_t* colony, citizen_t* citizen) {
    if (!colony) return;

    if (!citizen) {
        colony->population.count++;
    }

    {
        // todo implement
    }
}

void colony_work(colony_t* colony) {
    if (!colony) return;

    for (int i = 0; i < colony->population.count; i++) {
        int chance = rand() % 100;

        if (chance < 40) {
            colony->resources.food += (rand() % 5) + 1;
        }
        else if (chance < 80) {
            colony->resources.water += (rand() % 5) + 1;
        }
        else {
            colony->population.citizens[i].productivity = min(colony->population.citizens[i].productivity + 10, 100);
        }
    }
}

void colony_print(colony_t* colony, int day) {
    if (!colony) return;

    printf("-------------------- day %d --------------------\n", day);
    printf("food: %d\n", colony->resources.food);
    printf("water: %d\n", colony->resources.water);
    printf("population: %d\n", colony->population);
}
