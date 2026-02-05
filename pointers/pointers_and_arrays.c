#include <stdio.h>

// Incrementing the index position of the pointer, which gives a jump of 2 in
// memory, so from 1 to 3 3, 3 to 5 5, and so on.
int main(void) {
    int i, *ptr;

    int arr[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    ptr = &arr[0];

    for (i = 0; i < 8; i++) {
        // Dereference and increment.
        printf("ptr + %d = %d\n",i, *ptr++);
        // First increment then dereference.
        printf("ptr + %d = %d\n",i, *(++ptr));
    }

    return 0;
}