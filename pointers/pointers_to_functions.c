#include <stdio.h>

int arr[10] = {0, 1, 4, 2, 3, 7, 9, 8, 10, 11};

void bubble(int *p, int N);

// Use void for data type independency.
int compare(void *m, void *n);

int main(void) {
    int i;
    putchar("\n");

    for (i = 0; i < 10; i++) {
        printf("%d\n", arr[i]);
    }

    bubble(arr, 10);
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
void bubble(int *p, int N) {
    int i, j, t;

    // N goes from 10 down to 0 till its equal (controll how much the array
    // is unsorted).
    for (i = N-1; i >= 0; i--) {
        // j is 1 and moves up till its equal to i (to sort the array through
        // comparing neighbours).
        for (j = 1; j <= i; j++) {
            // Compare neighbours and move the greater on to the right.
            if (compare((void *)&p[j-1], (void *)&p[j])) {
                t = p[j-1];
                p[j-1] = p[j];
                p[j] = t;
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