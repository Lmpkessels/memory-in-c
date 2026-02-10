#include <stdio.h>

char dest[40] = "Hello";
char source[40] = "Hello, World!";

// Count length of string through indexing and incrementing.
size_t str_length(const char *s) {
    size_t len = 0;

    while (s[len] != '\0') {
        len++;
    }

    return len;
}

// Instead of slicing, accessing the address manually is done here,
// (*(source + i) access the address in memory.)
//
// This is called pointer notation, and it's used instead of array notation.
char *my_strcpy(char *dest, const char *source) {
    size_t i = 0;

    while (*(source + i) != '\0') {
        *(dest + i) = *(source + i);
        i++;
    }

    *(dest + i) = '\0'; // Terminate (mark end of string).

    for (i = 0; i < str_length(dest); i++) {
        printf("%d\n", *(dest + i));
    }

    *(dest + i) = '\0'; // Terminate (mark end of string).
    return dest;
}

int main() {
    my_strcpy(dest, source);
}