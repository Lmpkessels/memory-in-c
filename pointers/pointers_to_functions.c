#include <stdio.h>
#include <string.h>

int arr[10] = {0, 1, 4, 2, 3, 7, 9, 8, 10, 11};

// data-type int goes from int to void such that there can be worked with any
// data.
//
// A size type is add such that, its known what size there's been worked with.
void bubble(void *p, size_t width, int N);

// Use void for data type independency.
int compare(void *m, void *n);

int main(void) {
    int i;
    putchar("\n");

    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    // The size type is given 'long'.
    bubble(arr, sizeof(long), 10);
    putchar("\n");

    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    return 0;
}

// Bubble sort, takes as argument an array and the number of elements (N) 
// within that array.
//
// Then indexes through the array and compares neighbours the greatest will
// move to the right.
void bubble(void *p, size_t width, int N) {
    int i, j;
    // Buf width is a buffer of 'size_t width' in bytes equaling the size of long.
    unsigned char buf[width];
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
    // Create two pointers.
    int *m1, *n1;
    // Type cast, m1 is a pointer to m.
    m1 = (int *)m;
    // Type cast, n1 is a pointer to n.
    n1 = (int *)n;
    // Access locations in memory compare them and return greatest.
    return (*m1 > *n1);
}