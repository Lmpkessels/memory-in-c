#include <stdio.h>
#include "malloc.h"

// If memory is full return error message, else return the address.
int main() {
    size_t data = 100;
    int *ptr = malloc(data);

    if (ptr == NULL) {
        printf("Memory allocation failed\n");
    } else {
        printf("Memory allocation succeeded at address: %p\n", ptr);
    }

    return 0;
}