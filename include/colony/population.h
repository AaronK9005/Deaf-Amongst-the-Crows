#ifndef DAtC_POPULATION_H
#define DAtC_POPULATION_H

typedef struct citizen_t citizen_t;

/**
 * @brief struct for storing citizens
 * 
 * @param citizens ptr to dynamic array
 * @param count current number of citizens
 * @param cap current capacity of allocated array
 * 
 */
typedef struct population_t {
    citizen_t* citizens;
    int count;
    int cap;
} population_t;

#endif