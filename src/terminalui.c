#include "ui/terminalui.h"
#include "util/terminal.h"

#include <stdio.h>
#include <string.h>
#include "util/ansi_wrappers.h"

void endl() { putchar('\n'); }
void nendl(int n) { for (int i = 0; i < n; i++) putchar('\n'); }
void begl() { putchar('\r'); }

void ui_print_full_line(int _char)
{
    for (int i = 0; i < terminal.width; i++) {
        putchar(_char);
    }
}

void draw_line(int start, int middle, int end)
{
    putchar(start);
    for (int i = 0; i < terminal.width - 2; i++) {
        putchar(middle);
    }
    putchar(end);

    putchar('\n');
}

void draw_empty_line(int start, int end)
{
    putchar(start);
    ansi_right(terminal.width - 2);
    putchar(end);

    putchar('\n');
}

void ui_print_command_line()
{
    begl();
    draw_line(BORDER_TL, BORDER_H, BORDER_TR);
    draw_empty_line(BORDER_V, BORDER_V);
    draw_line(BORDER_BL, BORDER_H, BORDER_BR);
}

void ui_print_box(int inside_height)
{
    begl();
    draw_line(BORDER_TL, BORDER_H, BORDER_TR);
    for (int i = 0; i < inside_height; i++) {
        draw_empty_line(BORDER_V, BORDER_BL);
    }
    draw_line(BORDER_BL, BORDER_H, BORDER_BR);
}

void ui_print_centered(const char* text)
{
    if (!text) {
        endl();
        return;
    }

    int len = strlen(text);
    const int offset = (terminal.width - len) / 2;
    
    begl();
    ansi_right(offset);
    printf("%s\n", text);
}

