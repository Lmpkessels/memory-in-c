#include <stdio.h>
#include "malloc.h"

// If memory is full return error message, else return the address.
int main() {
    size_t size = 100;
    int *ptr = malloc(size);

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
    } else {
        printf("Memory allocation succeeded at address: %p\n", ptr);
    }

    return 0;
}