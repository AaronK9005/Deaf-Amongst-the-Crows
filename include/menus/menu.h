#ifndef DAtC_INTERACTIVE_MENU_H
#define DAtC_INTERACTIVE_MENU_H

typedef struct game_t game_t;

#define MENU_CREATE(name, options) { name, sizeof(options) / sizeof(options[0]), 0, options }

typedef struct option_t {
    const char* special_option;
    const char* label;
    int opt_len, label_len;
} option_t;

#define FLAG_CENTERED 0x01
#define FLAG_HIDE_SPECIAL_OPTS 0x02

typedef struct menu_t {
    const char* name;
    int o_count;
    int current;
    option_t* options;
    int selected_color;
    unsigned flags;
} menu_t;

int menu_run(menu_t* menu, game_t* game);

void menu_print(const menu_t* menu);

int menu_scroll(menu_t* menu, int n);

#endif