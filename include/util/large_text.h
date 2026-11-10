#ifndef MY_LARGE_TEXT_RENDERING_H
#define MY_LARGE_TEXT_RENDERING_H

#define LARGE_LETTER_SIZE 5

typedef char letter_t[LARGE_LETTER_SIZE][LARGE_LETTER_SIZE];

enum LETTERS {
    LETTER_A = 0,
    LETTER_B = 1,
    // ...
    LETTER_SPACE = 26,
    LETTER_EXCLAIMMARK,
    LETTER_HYPHEN,
    LETTER_UNKNOWN,
    LETTER_LAST = LETTER_UNKNOWN
};

extern const letter_t letters[];

int letter_index(char letter);

void print_letter(int letter);

void print_letter_row(int letter, int row);

void print_large_text(const char* text);

void print_large_text_max_width(const char* text, int width);

// set bound_width same as max_width
#define LL_FULL -1
void print_large_text_centered_bound(const char* text, int max_width, int bound_width);

#endif