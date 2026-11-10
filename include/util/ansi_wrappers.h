#ifndef ANSI_WRAPPERS_H
#define ANSI_WRAPPERS_H

void ansi_up(int n);
void ansi_down(int n);
void ansi_right(int n);
void ansi_left(int n);

void ansi_save_pos();
void ansi_use_pos();

void ansi_goto_home();
void ansi_goto(int x, int y);
void ansi_goto_rel(int dx, int dy);

int ansi_mvputchar(int x, int y, char c);
int ansi_mvprintf(int x, int y, const char* fmt, ...);

void ansi_clear_screen();
void ansi_clear_line();
void ansi_clear_begl();
void ansi_clear_endl();
void ansi_clear_begs();
void ansi_clear_ends();

void ansi_hide_cursor();
void ansi_show_cursor();

void ansi_reset();

void ansi_bold();
void ansi_faint();
void ansi_italic();
void ansi_underline();
void ansi_blink_slow();
void ansi_blink_fast();
void ansi_reverse();
void ansi_hidden();
void ansi_strikethrough();

void ansi_reset_bold();
void ansi_reset_bold_faint();
void ansi_reset_italic();
void ansi_reset_underline();
void ansi_reset_blink();
void ansi_reset_reverse();
void ansi_reset_hidden();
void ansi_reset_strikethrough();

enum {
    COLOR_BLACK = 30,
    COLOR_RED,
    COLOR_GREEN,
    COLOR_YELLOW,
    COLOR_BLUE,
    COLOR_MAGENTA,
    COLOR_CYAN,
    COLOR_WHITE = 37,
    COLOR_DEFAULT = 39,

    COLOR_BG_BLACK = 40,
    COLOR_BG_RED,
    COLOR_BG_GREEN,
    COLOR_BG_YELLOW,
    COLOR_BG_BLUE,
    COLOR_BG_MAGENTA,
    COLOR_BG_CYAN,
    COLOR_BG_WHITE = 47,
    COLOR_BG_DEFAULT = 49,

    COLOR_BRIGHT_BLACK = 90,
    COLOR_BRIGHT_RED,
    COLOR_BRIGHT_GREEN,
    COLOR_BRIGHT_YELLOW,
    COLOR_BRIGHT_BLUE,
    COLOR_BRIGHT_MAGENTA,
    COLOR_BRIGHT_CYAN,
    COLOR_BRIGHT_WHITE = 97,

    COLOR_BG_BRIGHT_BLACK = 100,
    COLOR_BG_BRIGHT_RED,
    COLOR_BG_BRIGHT_GREEN,
    COLOR_BG_BRIGHT_YELLOW,
    COLOR_BG_BRIGHT_BLUE,
    COLOR_BG_BRIGHT_MAGENTA,
    COLOR_BG_BRIGHT_CYAN,
    COLOR_BG_BRIGHT_WHITE = 107,
};

void ansi_set_fg(int color);
void ansi_set_bg(int color);
void ansi_set_color(int color);
void ansi_set_color_unchecked(int color);

void ansi_black();
void ansi_red();
void ansi_green();
void ansi_yellow();
void ansi_blue();
void ansi_magenta();
void ansi_cyan();
void ansi_white();
void ansi_default();

void ansi_bright_black();
void ansi_bright_red();
void ansi_bright_green();
void ansi_bright_yellow();
void ansi_bright_blue();
void ansi_bright_magenta();
void ansi_bright_cyan();
void ansi_bright_white();

void ansi_bg_black();
void ansi_bg_red();
void ansi_bg_green();
void ansi_bg_yellow();
void ansi_bg_blue();
void ansi_bg_magenta();
void ansi_bg_cyan();
void ansi_bg_white();
void ansi_bg_default();

void ansi_bg_bright_black();
void ansi_bg_bright_red();
void ansi_bg_bright_green();
void ansi_bg_bright_yellow();
void ansi_bg_bright_blue();
void ansi_bg_bright_magenta();
void ansi_bg_bright_cyan();
void ansi_bg_bright_white();

void ansi_256color_fg(int color);
void ansi_256color_bg(int color);

#endif