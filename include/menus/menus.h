#ifndef DAtC_MENUS_H
#define DAtC_MENUS_H

typedef struct menu_t menu_t;

enum {
    MENU_NONE = -1,
    MENU_TITLE,
    MENU_MAIN,
    MENU_ACTIONS,
    MENU_CITIZENS,
    MENU_EXPEDITIONS,
    MENU_RESOURCES,
    MENU_DIARY,
    MENU_COUNT
};

extern const menu_t menus[MENU_COUNT];

_Bool menus_init();

_Bool menus_free();

#endif