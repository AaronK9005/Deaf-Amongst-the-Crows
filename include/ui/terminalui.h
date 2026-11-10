#ifndef MY_TERMINAL_UI_H
#define MY_TERMINAL_UI_H

// newline
void endl();
void nendl(int n);

// carriage return
void begl();

void ui_print_full_line(int _char);

void ui_print_command_line();

void ui_print_box(int inside_height);

void ui_print_centered(const char* text);

#endif