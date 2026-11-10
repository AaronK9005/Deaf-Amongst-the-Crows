#ifndef DAtC_CITIZEN_H
#define DAtC_CITIZEN_H

/**
 * @brief basic citizen struct
 * 
 * @param role
 * @param health
 * @param morale
 * @param productivity
 * @param schedule
 * @param flags
 * 
 */
typedef struct citizen_t {
    const char* name;
    int role;
    int health;
    int morale;
    int productivity;
    unsigned schedule;
    unsigned flags;
} citizen_t;

#endif