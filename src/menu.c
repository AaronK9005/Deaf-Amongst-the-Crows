#include "menus/menu.h"

#include <stdio.h>
#include "util/ansi_wrappers.h"
#include "core.h"

#include <conio.h>
#include <ctype.h>

void menu_print(const menu_t* menu) {
    if (!menu) return;

    char buffer[64] = { 0 };

    printf("%s\n", menu->name);

    for (int i = 0; i < menu->o_count; i++) {
        if (i == menu->current) {
            if (menu->selected_color != 0) {
                ansi_set_color_unchecked(menu->selected_color);
            }
            else {
                ansi_bg_blue();
            }
        }
        if (menu->options[i].special_option) {
            snprintf(buffer, sizeof(buffer), "%s", menu->options[i].special_option);
        }
        else {
            snprintf(buffer, sizeof(buffer), "%d", i + 1);
        }

        printf("\t%s) %s\n", buffer, menu->options[i].label);
        if (i == menu->current) {
            ansi_reset();
        }
    }
}

int menu_scroll(menu_t* menu, int n) {
    if (!menu || n == 0) return EOF;

    menu->current = (menu->current + n + menu->o_count) % menu->o_count;
    // if (menu->current < 0) menu->current += menu->o_count;

    return menu->current;
}

#define ARROW_PREFIX 224
#define ARROW_UP 72
#define ARROW_LEFT 75
#define ARROW_RIGHT 77
#define ARROW_DOWN 80

/**
 * @brief runs given menu
 * 
 * @param menu 
 * @param game 
 * @return index of selected option, `-1` on fail
 */
int menu_run(menu_t* menu, game_t* game) {
    if (!menu || !game) return -1;

    ansi_save_pos();

    ansi_clear_screen();
    ansi_goto_home();
    ansi_hide_cursor();

    menu_print(menu);

    int c = 0;
    bool should_end = false;
    bool render = true;

    while (!should_end)
    {
        c = tolower(_getch());

        switch(c) {
            case '\r':
                if (
                    menu->current < 0 ||
                    menu->current >= menu->o_count
                ) break;

                ansi_use_pos();
                return menu->current;
            when 'q':
                should_end = true;
                return -10;
            when 'w':
                render = true;
                menu_scroll(menu, -1);
            when 's':
                render = true;
                menu_scroll(menu, 1);
            when ARROW_PREFIX:
                if (!_kbhit()) break;

                switch (_getch())
                {
                case ARROW_UP:      render = true; menu_scroll(menu, -1); break;
                case ARROW_LEFT:    break;
                case ARROW_DOWN:    render = true; menu_scroll(menu, 1); break;
                case ARROW_RIGHT:   break;
                }
                break;
        }

        int opt_index;

        for (int i = 0; i < menu->o_count; i++) {
            if (!menu->options[i].special_option) continue;

            if (c == towlower(menu->options[i].special_option[0])) {
                opt_index = i;
                // render = true;
                break;
            }
        }

        if (opt_index != menu->current) {
            menu->current = opt_index;
            render = true;
        }

        if (render) {
            render = false;
            // ansi_clear_screen();
            ansi_goto_home();
            menu_print(menu);
        }
    }

    ansi_use_pos();
    return 0;
}

#define RES_FOOD 0
#define RES_WATER 1
#define RES_CITIZEN 2
#define RES_QUIT 3

// int test_action_menu(colony_t* colony) {
//     option_t opts[] = {
//         { "f", "food" },
//         { "w", "water" },
//         { "c", "new citizen" }
//     };

//     menu_t menu = MENU_CREATE("What should colony obtain today?", opts);
//     menu_t* m = &menu;

//     ansi_clear_screen();
//     ansi_goto_home();
//     ansi_hide_cursor();

//     menu_print(m);
//     ansi_save_pos();
//     char c = 0;
//     bool should_end = false;
//     bool render = true;

//     while (!should_end)
//     {

//         switch ((c = towlower(_getch())))
//         {
//         case 'q':   return RES_QUIT; // end program
//         when 'w':   menu_scroll(m, -1); 
//                     render = true;
//         when 's':   menu_scroll(m, 1);
//                     render = true;
//         when '\r':  should_end = true;
//                     ansi_use_pos();
//                     return m->current;
//         }

//         if (render) {
//             render = false;
//             ansi_clear_screen();
//             ansi_goto_home();
//             menu_print(m);
//         }
//     }
    
// }



