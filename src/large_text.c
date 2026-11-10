#include "util/large_text.h"

#include <stdio.h>
#include <string.h>
#include <ctype.h>

#include "util/ansi_wrappers.h"

const letter_t letters[] = {
    { // A
        {' ',' ','#',' ',' '},
        {' ','#',' ','#',' '},
        {'#','#','#','#','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'}
        // {' ',' ',' ',' ',' '},
        // {' ','#','#','#',' '},
        // {'#',' ',' ','#',' '},
        // {'#',' ',' ','#','#'},
        // {' ','#','#',' ','#'}
    },
    { // B
        {'#','#','#','#',' '},
        {'#',' ',' ',' ','#'},
        {'#','#','#','#',' '},
        {'#',' ',' ',' ','#'},
        {'#','#','#','#',' '}
    },
    { // C
        {' ','#','#','#',' '},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ',' '},
        {'#',' ',' ',' ','#'},
        {' ','#','#','#',' '}
        // {' ',' ',' ',' ',' '},
        // {' ','#','#','#',' '},
        // {'#',' ',' ',' ',' '},
        // {'#',' ',' ',' ',' '},
        // {' ','#','#','#',' '}
    },
    { // D
        {'#','#','#','#',' '},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#','#','#','#',' '}
    },
    { // E
        {'#','#','#','#','#'},
        {'#',' ',' ',' ',' '},
        {'#','#','#','#','#'},
        {'#',' ',' ',' ',' '},
        {'#','#','#','#','#'}
        // {' ',' ',' ',' ',' '},
        // {' ','#','#',' ',' '},
        // {'#',' ',' ','#',' '},
        // {'#',' ','#',' ',' '},
        // {' ','#','#','#',' '}
    },
    { // F
        {'#','#','#','#','#'},
        {'#',' ',' ',' ',' '},
        {'#','#','#','#','#'},
        {'#',' ',' ',' ',' '},
        {'#',' ',' ',' ',' '}
    },
    { // G
        {' ','#','#','#','#'},
        {'#',' ',' ',' ',' '},
        {'#',' ','#','#','#'},
        {'#',' ',' ',' ','#'},
        {' ','#','#','#',' '}
    },
    { // H
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#','#','#','#','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'}
    },
    { // I
        {' ','#','#','#',' '},
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '},
        {' ','#','#','#',' '}
    },
    { // J
        {'#','#','#','#','#'},
        {' ',' ',' ',' ','#'},
        {' ',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {' ','#','#','#',' '}
    },
    { // K
        {'#',' ',' ',' ','#'},
        {'#',' ',' ','#',' '},
        {'#','#','#',' ',' '},
        {'#',' ',' ','#',' '},
        {'#',' ',' ',' ','#'}
    },
    { // L
        {'#',' ',' ',' ',' '},
        {'#',' ',' ',' ',' '},
        {'#',' ',' ',' ',' '},
        {'#',' ',' ',' ',' '},
        {'#','#','#','#','#'}
    },
    { // M
        {'#',' ',' ',' ','#'},
        {'#','#',' ','#','#'},
        {'#',' ','#',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'}
    },
    { // N
        {'#',' ',' ',' ','#'},
        {'#','#',' ',' ','#'},
        {'#',' ','#',' ','#'},
        {'#',' ',' ','#','#'},
        {'#',' ',' ',' ','#'}
    },
    { // O
        {' ','#','#','#',' '},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {' ','#','#','#',' '}
    },
    { // P
        {'#','#','#','#',' '},
        {'#',' ',' ',' ','#'},
        {'#','#','#','#',' '},
        {'#',' ',' ',' ',' '},
        {'#',' ',' ',' ',' '}
    },
    { // Q
        {' ','#','#','#',' '},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {' ','#','#','#',' '},
        {' ',' ',' ',' ','#'}
    },
    { // R
        {'#','#','#','#',' '},
        {'#',' ',' ',' ','#'},
        {'#','#','#','#',' '},
        {'#',' ',' ','#',' '},
        {'#',' ',' ',' ','#'}
    },
    { // S
        {' ','#','#','#','#'},
        {'#',' ',' ',' ',' '},
        {' ','#','#','#',' '},
        {' ',' ',' ',' ','#'},
        {'#','#','#','#',' '}
    },
    { // T
        {'#','#','#','#','#'},
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '}
    },
    { // U
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {' ','#','#','#',' '}
    },
    { // V
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {' ','#',' ','#',' '},
        {' ',' ','#',' ',' '}
    },
    { // W
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ',' ',' ','#'},
        {'#',' ','#',' ','#'},
        {' ','#',' ','#',' '}
    },
    { // X
        {'#',' ',' ',' ','#'},
        {' ','#',' ','#',' '},
        {' ',' ','#',' ',' '},
        {' ','#',' ','#',' '},
        {'#',' ',' ',' ','#'}
    },
    { // Y
        {'#',' ',' ',' ','#'},
        {' ','#',' ','#',' '},
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '}
    },
    { // Z
        {'#','#','#','#','#'},
        {' ',' ',' ','#',' '},
        {' ',' ','#',' ',' '},
        {' ','#',' ',' ',' '},
        {'#','#','#','#','#'}
    },
    { // space
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '}
    },
    { // exclaimaition mark
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '},
        {' ',' ','#',' ',' '},
        {' ',' ',' ',' ',' '},
        {' ',' ','#',' ',' '}
    },
    { // hyphen
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '},
        {'#','#','#','#','#'},
        {' ',' ',' ',' ',' '},
        {' ',' ',' ',' ',' '}
    },
    { // unknown
        {'#','#','#','#','#'},
        {'#',' ','#',' ','#'},
        {'#','#',' ','#','#'},
        {'#',' ','#',' ','#'},
        {'#','#','#','#','#'}
    }
};

int letter_index(char letter) {
    char c = tolower(letter);

    switch (c)
    {
    case 'a':
    case 'b':
    case 'c':
    case 'd':
    case 'e':
    case 'f':
    case 'g':
    case 'h':
    case 'i':
    case 'j':
    case 'k':
    case 'l':
    case 'm':
    case 'n':
    case 'o':
    case 'p':
    case 'q':
    case 'r':
    case 's':
    case 't':
    case 'u':
    case 'v':
    case 'w':
    case 'x':
    case 'y':
    case 'z': return c - 'a';
    case ' ': return LETTER_SPACE;
    case '!': return LETTER_EXCLAIMMARK;
    case '-': return LETTER_HYPHEN;
    default:  return LETTER_UNKNOWN;
    }
}

void print_letter(int letter) {
    if (letter < 0 || letter > LETTER_LAST) return;

    for (int i = 0; i < LARGE_LETTER_SIZE; i++) {
        for (int j = 0; j < LARGE_LETTER_SIZE; j++) {
            putchar(letters[letter][i][j]);
        }
        putchar('\n');
    }    
}

void print_letter_row(int letter, int row) {
    for (int i = 0; i < LARGE_LETTER_SIZE; i++) {
        putchar(letters[letter][row][i]);
    }
}

void print_large_text(const char* text) {
    if (!text) return;

    // for now hardcoded max value
    // todo get max terminal cols
    const int max_len = 22;

    size_t len = strlen(text);
    size_t offset = 0;

    if (text[len - 1] == '"' || text[len - 1] == '\'') {
        len--;
    }
    if (text[0] == '"' || text[0] == '\'') {
        len--;
        offset++;
    }

    while (len > 0) {
        int l;
        int max = len > max_len ? max_len : len;

        for (int row = 0; row < LARGE_LETTER_SIZE; row++) {
            for (l = 0; l < max; l++) {
                print_letter_row(letter_index(text[l + offset]), row);
                putchar(' ');
            }
            putchar('\n');
        }

        len -= l;
        offset += l;
        if (len > 0) putchar('\n');
    }
}

void print_large_text_max_width(const char* text, int width)
{
    if (!text || width <= 0) return;

    const int max_len = width / (LARGE_LETTER_SIZE + 1);

    size_t len = strlen(text);
    size_t offset = 0;

    if (text[len - 1] == '"' || text[len - 1] == '\'') {
        len--;
    }
    if (text[0] == '"' || text[0] == '\'') {
        len--;
        offset++;
    }

    while (len > 0) {
        int l;
        int max = len > max_len ? max_len : len;

        for (int row = 0; row < LARGE_LETTER_SIZE; row++) {
            for (l = 0; l < max; l++) {
                print_letter_row(letter_index(text[l + offset]), row);
                putchar(' ');
            }
            putchar('\n');
        }

        len -= l;
        offset += l;
        if (len > 0) putchar('\n');
    }
}

void print_large_text_centered_bound(const char* text, int max_width, int bound_width)
{
    if (bound_width == LL_FULL) bound_width = max_width;
    if (!text || max_width <= 0 || bound_width <= 0) return;

    const int max_len = bound_width / (LARGE_LETTER_SIZE + 1);

    size_t len = strlen(text);
    size_t offset = 0;

    if (text[len - 1] == '"' || text[len - 1] == '\'') {
        len--;
    }
    if (text[0] == '"' || text[0] == '\'') {
        len--;
        offset++;
    }

    while (len > 0) {
        int l; // letter iterator
        int max = len > max_len ? max_len : len; // max letters printed in this iteration
        int line_offset = (max_width - (max * (LARGE_LETTER_SIZE + 1))) / 2; // spaces before large text

        for (int row = 0; row < LARGE_LETTER_SIZE; row++) {
            ansi_right(line_offset);
            for (l = 0; l < max; l++) {
                print_letter_row(letter_index(text[l + offset]), row);
                putchar(' ');
            }
            putchar('\n');
        }

        len -= l;
        offset += l;
        if (len > 0) putchar('\n');
    }
}

