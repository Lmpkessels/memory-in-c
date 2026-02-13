#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

// If there's enough memory return the block; else return NULL.
void *malloc(size_t data) {
    void *block;

    block = sbrk(data); // Ask OS for block of size data.
    

    if (block == (void*) -1) { // If OS cannot allocate memory signal
        return NULL;           // a allocation failure.
    }
    
    return block; // If OS can allocate memory return valid memory block.
}