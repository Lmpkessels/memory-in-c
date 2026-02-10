#include <stdio.h>

#define ROWS 5
#define COLS 10

// 2D Array.
int characters_and_numbers[ROWS][COLS] = {
    {'0', '1', '2', '3', '4', '5', '6', '7', '8', '9'},
    {'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j'},
    {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J'},
    {'9', '8', '7', '6', '5', '4', '3', '2', '1', '0'},
    {'J', 'I', 'H', 'G', 'F', 'E', 'D', 'C', 'B', 'A'}
};

// Address arithmetic derefencing, represented as:
// *(*(ptr_to_characters_and_number + i) + j);
int (*ptr_to_characters_and_numbers)[COLS];

// Getting indises out of a 2D array using address arithmetic dereferencing.
// 
// 2 loops are used to access each element in the array, then dereference 
// to access each nested array in memory, then dereference to access each indice
// in memory.
int main(void) {
    int row, col;
    ptr_to_characters_and_numbers = characters_and_numbers;

    printf("\n\n");
    for (row = 0; row < 5; row++) {
        for (col = 0; col < 10; col++) {
            printf(
                "[%d][%d] = %c\n"
                , row, col, *(*(ptr_to_characters_and_numbers + row) + col)
            );
        }
    }
}