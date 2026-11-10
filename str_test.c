#include <stdio.h>
#include <stdlib.h>

#include "my_string.h"

int main(int argc, char** argv)
{
    string* s1 = string_new("Hello");
    string* s2 = string_new("world");

    string *s = string_join(string_append_char(s1, ' '), s2);
    printf(S_PH "\n", STR_PRINT(s));
    
    string_free(s);

    return 0;
}
