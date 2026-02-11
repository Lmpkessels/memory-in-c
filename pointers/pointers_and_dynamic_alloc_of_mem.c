#include <stdio.h>
// Standard lib is used to implement the standard library in this usecase (
// for malloc()).
#include <stdlib.h>

// Using malloc to allocate 10 integers, then assigning the value of 2 to all
// those integers.
//
// The number of elements is known at compile time in this function.
int allocate_10_int(void) {
    int *integer_pointer, k;

    integer_pointer = (int *)malloc(10 * sizeof(int));

    for (k = 0; k < 10; k++) {
        integer_pointer[k] = 2;

        printf("k = %d\n", integer_pointer[k]);
    }
}

// Using memory allocation for a continous block of memory, the size of the 
// block is not known at runtime.
int allocate_int(void) {
    // ncols nrows can be evaluated or read in at run time.
    int ncols = 5;
    int nrows = 10;

    int colm, row;

    // Pointer to pointer.
    int **colmptr;
    int **rowptr;

    // Allocate memory and store the size of (colm & nrows) times the size of
    // int.
    //
    // Here double pointing happens first, first point to colm, then point to
    // int.
    colmptr = malloc(colm * sizeof(int *));
    rowptr = malloc(nrows * sizeof(int *));

    // Handling error,
    // When there's no value in column or row pointer put an error and exit.
    if (colmptr == NULL) {
        puts("\nFailure to allocate room for column pointer. \n");
        exit(0);
    } else if (rowptr == NULL) {
        puts("\nFailure to allocate room for row pointer. \n");
        exit(0);
    }

    // Display memory layout for columns. 
    printf("\n\n\ncolumn:\nIndex     Pointer(hex)    Pointer(dec)    Diff.(dec)");
    for (colm = 0; colm < ncols; colm++) {
        colmptr[colm] = malloc(ncols * sizeof(int));
        if (colmptr == NULL) {
            printf("\nFailure to allocate room for column pointer. \n");
            exit(0);
        }
        
        printf(
            "\n%d        %p      %lu", 
            colm, (void *)colmptr[colm], (unsigned long)(colm > 0)
        );
        
        printf("        %d", (int)(colmptr[colm] - colmptr[colm - 1]));
    }
    
    printf("\n");
    
    // Display memory layout for rows.
    printf("\n\n\nrow:\nIndex     Pointer(hex)    Pointer(dec)    Diff.(dec)");
    for (row = 0; row < nrows; row++) { 
        rowptr[row] = malloc(ncols * sizeof(int));            
        if (rowptr == NULL) {
            printf("\nFailure to allocate room for row pointer. \n");
            exit(0);
        }

        printf(
            "\n%d        %p      %lu", 
            row, (void *)rowptr[row], (unsigned long)(row > 0)
        );

        printf("        %d", (int)(rowptr[row] - rowptr[row - 1]));
    }

    printf("\n");
    return 0;
}

int main() {
    allocate_10_int();
    allocate_int();
}