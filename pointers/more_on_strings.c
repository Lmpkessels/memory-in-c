#include <stdio.h>

char dest[] = "Hello";
char source[] = "Hello, World!";

// Instead of slicing, accessing the address manually is done here,
// (*(source + i) access the address in memory.)
//
// This is called pointer notation, and it's used instead of array notation.
char *my_strcpy(char dest[], char source[]) {
    int i = 0;

    while (*(source + i) != '\0') {
        *(dest + i) = *(source + i);
        i++;
    }

    for (i = 0; i < *(dest + i); i++) {
        printf("%d\n", *(dest + i));
    }

    *(dest + i) = '\0';
    return dest;
}

int main() {
    my_strcpy(dest, source);
}