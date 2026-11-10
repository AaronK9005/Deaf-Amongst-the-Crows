#ifndef MY_STRING_H
#define MY_STRING_H

#include <stdbool.h>

#define STR_ARGS(str) (str)->size, (str)->data
#define STR_PLACEHOLDER "%.*s"
#define S_PH STR_PLACEHOLDER
#define STR_PRINT(str) printf(STR_PLACEHOLDER, STR_ARGS(str))
#define STR_PRINTLN(str) printf(STR_PLACEHOLDER "\n", STR_ARGS(str))

/**
 * @brief Size-based string.
 *
 * @warning The string is NOT null-terminated.
 * @warning Must be freed using `string_free()`.
 *
 * @param data Always a valid pointer to the string data.
 * @param size Current size of the string.
 * @param cap Current capacity of the allocated buffer.
 *
 * @return NULL indicates an error occurred. Unless otherwise noted, the source
 *         string has not been modified.
 */
typedef struct {
    char* data;
    unsigned size;
    unsigned cap;
} string;

/**
 * @brief Creates a new string from the given text.
 *
 * @param text Null-terminated source string.
 * @return A @c new `string*`, or NULL on failure.
 */
string* string_new(const char* text);

/**
 * @brief Creates an empty string buffer with the given capacity.
 *
 * @param capacity Requested buffer capacity.
 * @return A @c new `string*`, or NULL on failure.
 */
string* string_buffer(unsigned capacity);

/**
 * @brief Destroys the given string.
 *
 * @param str String to @c destroy.
 */
void string_free(string* str);

/**
 * @brief Sets text of a string
 * 
 * @param str String to modify
 * @param text Source text to set
 * @return The @c modified `string*`, or `NULL` of failure
 */
string* string_set(string* str, const char* text);

/**
 * @brief Creates a deep copy of the given string.
 *
 * @param src String to copy.
 * @return A @c new `string*`, or NULL on failure.
 */
string* string_duplicate(const string* src);

/**
 * @brief Joins two strings together.
 * 
 * First checks, if `s1` has enough capacity to contain both strings. If not, checks `s2`.
 * If both are too small, allocates new data for `s1` and destroys `s2`.
 * 
 * @note On failure (NULL return), neither source string is modified.
 * @note On success, one source string will be destroyed.
 * 
 * @param s1 First string.
 * @param s2 Second string to join.
 * @return One surviving source string, ( @c modified ), or NULL on failure.
 */
string* string_join(string* s1, string* s2);

/**
 * @brief Appends a null-terminated string.
 *
 * @param str String to modify.
 * @param text Null-terminated string to append.
 * @return The @c modified `str`, or NULL on failure.
 */
string* string_append(string* str, const char* text);

string* string_append_char(string* str, char c);

// string* string_push_back(string* str, char c);

// char string_pop_back(string* str);

// char string_front(string* str);

// char string_back(string* str);

/**
 * @brief Converts the string to lowercase.
 *
 * @param str String to modify.
 * @return The @c modified `str`.
 */
string* string_lower(string* str);

/**
 * @brief Converts the string to uppercase.
 *
 * @param str String to modify.
 * @return The @c modified `str`.
 */
string* string_upper(string* str);

/**
 * @brief Creates a new string as a slice of the given string.
 *
 * @param str Source string.
 * @param start Starting index.
 * @param len Length of the new string, or `-1` to include the rest of the string.
 * @return A @c new `string*`, or NULL on failure.
 */
string* string_substr(const string* str, unsigned start, int len);

/**
 * @brief Removes whitespace from both ends of the string.
 *
 * @param str String to modify.
 * @return The @c modified `str`.
 */
string* string_strip(string* str);

bool string_starts_with(string* str, string* prefix);

#endif