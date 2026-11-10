#include "util/terminal.h"

int putchar(int);

terminal_t terminal;

#ifdef _WIN32
    #include <windows.h>

    void get_terminal_size(int* width, int* height)
    {
        static HANDLE h = NULL;
        CONSOLE_SCREEN_BUFFER_INFO csbi;
        
        if (!h)
            h = GetStdHandle(STD_OUTPUT_HANDLE);

        if (GetConsoleScreenBufferInfo(h, &csbi)) {
            if (width)
                *width  = csbi.srWindow.Right - csbi.srWindow.Left + 1;

            if (height)
                *height = csbi.srWindow.Bottom - csbi.srWindow.Top + 1;
        }
    }

#else 
    #include <sys/ioctl.h>
    #include <unistd.h>

    void get_terminal_size(int *width, int *height)
    {
        struct winsize ws;

        if (ioctl(STDOUT_FILENO, TIOCGWINSZ, &ws) == -1) {
            *width = 0;
            *height = 0;
            return;
        }

        if (width) *width = ws.ws_col;
        if (height) *height = ws.ws_row;
    }

#endif

void update_terminal_size() {
    get_terminal_size(&terminal.width, &terminal.height);
}
