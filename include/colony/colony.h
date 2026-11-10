#ifndef DAtC_COLONY_H
#define DAtC_COLONY_H

#include <stdbool.h>
#include "colony/resources.h"
#include "colony/population.h"

/**
 * @brief 
 * 
 * @param resources
 * @param population
 * 
 */
typedef union colony_t {
    struct {
        resources_t resources;
        population_t population;
    };
    struct {
        resources_t res;
        population_t pop;
    };
} colony_t;

int colony_init(colony_t* colony);

int colony_finish(colony_t* colony);

bool colony_is_alive(colony_t* colony);

void colony_consume_resources(colony_t* colony);

void colony_add_citizen(colony_t* colony, citizen_t* citizen);

void colony_work(colony_t* colony);

void colony_print(colony_t* colony, int day);

#endif