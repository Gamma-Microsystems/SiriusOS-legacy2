#include "../include/string.h"

int strcmp_partial(const char *s1, const char *s2, size_t n) {
    for (size_t i = 0; i < n; ++i) {
        if (s1[i] != s2[i])
            return (unsigned char)s1[i] - (unsigned char)s2[i];
        if (s1[i] == '\0')  // Reached the end of either string
            return 0;
    }
    return 0; // Strings are equal up to n characters
}