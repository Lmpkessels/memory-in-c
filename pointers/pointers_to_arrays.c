//NOTES:
// - The type of a pointer variable must match the first type of an array.
// - Typedef, assignes a new name to a specified data type (e.g. typedef
// usigned char byte, then byte[], would be a array of unsigned characters).

#include <stdio.h>

// When pointing to a typedefined variable, the name must be used to create
// the pointer as in: Array *p1d.
typedef unsigned int Array[10];

// Pointer to address of Array.
Array *p1d;

Array r2d[5] = {
    {1, 2, 3, 4, 5, 6, 7, 8, 9, 10},
    {0, 1, 2, 3, 4, 5, 6, 7, 8, 9},
    {10, 9, 8, 7, 6, 5, 4, 3, 2, 1},
    {9, 8, 7, 6, 5, 4, 3, 2, 1, 0},
    {1, 1, 2, 2, 3, 3, 4, 4, 5, 5}
};

// Pointing to a defined type array, printing the size of, and the element
// indices.
int main(void) {
    int column, row;
    p1d = &r2d[0];

    printf("%ld\n", sizeof(*r2d));
    printf("%ld\n", sizeof(*p1d));

    for (column = 0; column < 5; column++) {
        for (row = 0; row < 10; row++) {
            // Accessing addresses and displaying it in shell.
            printf("[%d][%d] = %d\n", column, row, *(*(r2d + column) + row));
            printf("[%d][%d] = %d\n", column, row, *(*(p1d + column) + row));
        }
    }
}