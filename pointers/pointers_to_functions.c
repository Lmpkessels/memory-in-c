#include <stdio.h>
#include <string.h>

#define MAX_BUF 256 // Buffer of max 256 bits.

// Array with a capacity of 5 arrays with 20 indices.
char arr2d[5][20] = {
    "Peter Franken",
    "Jason Stathem",
    "Dennis M Ritchie",
    "John Jones",
    "John D Rockefeller"
};

// data-type int goes from int to void such that there can be worked with any
// data.
//
// data-type size_t goes to int such that the range is declared at runtime.
void bubble(void *p, int width, int N);

// Use void for data type independency.
int compare(void *m, void *n);

int main(void) {
    int i;
    putchar("\n");

    for (i = 0; i < 10; i++) {
        printf("%s\n", arr2d[i]);
    }

    // The size type is given 'long'.
    bubble(arr2d, 20, 10);
    putchar("\n");
    putchar("\n");

    for (i = 0; i < 10; i++) {
        printf("%s\n", arr2d[i]);
    }

    return 0;
}

// Bubble sort, takes as argument an array and the number of elements (N) 
// within that array.
//
// Then indexes through the array and compares neighbours the greatest will
// move to the right.
void bubble(void *p, int width, int N) {
    int i, j, k;
    // Buf width is a buffer of '256 bytes'.
    unsigned char buf[MAX_BUF];
    // Point to the array.
    unsigned char *bp = p;

    // N goes from 10 down to 0 till its equal (controll how much the array
    // is unsorted).
    for (i = N-1; i >= 0; i--) {
        // j is 1 and moves up till its equal to i (to sort the array through
        // comparing neighbours).
        for (j = 1; j <= i; j++) {
            // Compare neighbours and move the greater on to the right.
            // Instead of indexing now pointer arithmetic is used, so first point
            // to index 0, then 1, move up till done.
            // Dereference to access the addresses in memory.
            if (compare((void *)(bp + width*(j-1)), (void *)(bp + j*width))) {
                // t = p[j-1];
                // Copy from from the source buffer into the destination buffer 
                // with the greater neighbour on the right.
                memcpy(buf, bp + width*(j-1), width);
                // p[j-1] = p[j];
                memcpy(bp + width*(j-1), bp + j*width, width);
                // p[j] = t;
                memcpy(bp + j*width, buf, width);
            }
        }
    }
}

// Compare and return the greater index in the array.
int compare(void *m, void *n) {
    // Create two pointers pointing to 'm' and 'n'.
    char *m1 = m;
    char *n1 = n;
    // Compare m1 and n1 and return the greatest.
    return (strcmp(m1, n1));
}