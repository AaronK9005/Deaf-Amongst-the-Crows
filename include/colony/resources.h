#ifndef DAtC_RESOURCES_H
#define DAtC_RESOURCES_H

/**
 * @brief Basic struct for holding resources
 * 
 * @param food int
 * @param water int
 * @param shelter int
 * @param wood int
 */
typedef struct resources_t {
    int food;
    int water;
    int shelter;
    int wood;
} resources_t;

#endif