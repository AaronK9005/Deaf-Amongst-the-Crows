#include "util/my_string.h"

#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define CAP_ALIGNMENT 16

size_t align_capacity(size_t size) {
    if (size != 0 && size % CAP_ALIGNMENT == 0) 
        return size;
    else
        return CAP_ALIGNMENT * (size / CAP_ALIGNMENT + 1);
}


string* string_new(const char* text) {
    string* str = malloc(sizeof(string));
    if (!str) return NULL;

    size_t size = strlen(text);
    size_t cap = align_capacity(size);

    char* data = malloc(cap);
    if (!data) {
        free(str);
        return NULL;
    }
    memcpy(data, text, size);

    str->data = data;
    str->size = (unsigned)size;
    str->cap = (unsigned)cap;

    return str;
}

string* string_buffer(unsigned capacity) {
    string* buff = malloc(sizeof(string));
    if (!buff) return NULL;

    size_t cap = align_capacity((size_t)capacity);

    char* data = malloc(cap);
    if (!data) {
        free(buff);
        return NULL;
    }

    buff->data = data;
    buff->size = 0;
    buff->cap = (unsigned)cap;

    return buff;
}

void string_free(string* str) {
    if (str) {
        if (str->data) {
            free(str->data);
            str->data = NULL;
        }
        free(str);
    }
}

string* string_set(string* str, const char* text) {
    if (!str) return NULL;

    size_t size = text ? strlen(text) : 0;

    if (!str->data || size > str->cap) {
        size_t cap = align_capacity(size);
        char* data = malloc(cap);
        if (!data) return NULL;

        free(str->data);

        str->data = data;
        str->cap = cap;
    }

    if (text) memcpy(str->data, text, size);
    str->size = size;

    return str;
}

string* string_duplicate(const string* src) {
    if (!src) return NULL;

    string* new = string_buffer(src->cap);
    if (!new) return NULL;

    memcpy(new->data, src->data, src->size);
    new->size = src->size;

    return new;
}

string* string_join(string* s1, string* s2) {
    if (!s1 && !s2) return NULL;
    if (!s1) return s2;
    if (!s2) return s1;
    if (s1 == s2) return NULL;

    unsigned size = s1->size + s2->size;

    if (s1->cap >= size) {
        memcpy(s1->data + s1->size, s2->data, s2->size);
        s1->size = size;
        string_free(s2);
        return s1;
    }
    else
    if (s2->cap >= size) {
        memmove(s2->data + s1->size, s2->data, s2->size);
        memcpy(s2->data, s1->data, s1->size);
        s2->size = size;
        string_free(s1);
        return s2;
    }

    size_t cap = align_capacity((size_t)size);
    char *data = realloc(s1->data, cap);
    if (!data) return NULL; //! maybe needs better handeling?
    
    memcpy(data + s1->size, s2->data, s2->size);

    string_free(s2);

    s1->data = data;
    s1->size = size;
    s1->cap = cap;

    return s1;
}

string* string_append(string* str, const char* text) {
    if (!str) return NULL;
    if (!text) return str;

    size_t text_size = strlen(text);
    unsigned size = str->size + (unsigned)text_size;

    if (str->cap < size) {
        size_t cap = align_capacity(size);
        char *data = realloc(str->data, cap);
        if (!data) return NULL;

        str->data = data;
        str->cap = cap;
    }

    memcpy(str->data + str->size, text, text_size);
    str->size = size;

    return str;
}

string* string_append_char(string* str, char c) {
    if (!str) return NULL;

    if (str->size >= str->cap) {
        size_t cap = align_capacity(str->size + 1);
        char* data = realloc(str->data, cap);
        if (!data) return NULL;

        str->data = data;
        str->cap = (unsigned)cap;
    }

    str->data[str->size++] = c;

    return str;
}

string* string_lower(string* str) {
    if (!str) return NULL;

    for (unsigned i = 0; i < str->size; i++) {
        str->data[i] = tolower(str->data[i]);
    }

    return str;
}

string* string_upper(string* str) {
    if (!str) return NULL;

    for (unsigned i = 0; i < str->size; i++) {
        str->data[i] = toupper(str->data[i]);
    }

    return str;
}

string* string_substr(const string* str, unsigned start, int len) {
    if (!str || start >= str->size) return NULL;
    
    if (len == -1) len = (int)str->size - (int)start;

    string* sub = string_buffer((unsigned)len);
    if (!sub) return NULL;
    
    for (int i = 0; i < len; i++) {
        sub->data[i] = str->data[start + i];
    }
    sub->size = (unsigned)len;

    return sub;
}

string* string_strip(string* str) {
    if (!str) return NULL;
    if (str->size == 0) return str;

    unsigned front = 0;
    unsigned back = str->size - 1;
    unsigned whitespace = 0;

    while (front < back && isspace(str->data[front])) {
        front++;
        whitespace++;
    }
    while (back > front && isspace(str->data[back])) {
        back--;
        whitespace++;
    }
    
    if (whitespace != 0) {
        unsigned size = str->size - whitespace;
        memmove(str->data, str->data + front, size);
        str->size = size;
    }

    return str;
}

bool string_starts_with(string* str, string* prefix) {
    if (!str || !prefix) return false;

    
}
