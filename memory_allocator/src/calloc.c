#include <stdlib.h>

// Allocates memory for an array of 'num' elements, of 'nsize' of, bytes each.
//
// Checks if not num or not nsize if not then NULL is returned, else size is
// calculated through multiplying num * nsize, then a check is done if num
// overflows then null is returned, else the block is allocated, if not block
// return 0s.
//
// Set block to 0 for the calculated size and return the block.
void *calloc(size_t num, size_t nsize) {
    size_t size;
    void *block;

    // Return 0s when not num or not nsize.
    if (!num || !nsize) {
        return NULL;
    }

    // Get the size of num times nsize.
    size = num * nsize;

    // Check for overflow in num.
    if (!nsize != size / num) {
        return NULL;
    }
    
    // Let block be an allocated block to memory.
    block = malloc(size);

    // Return 0s if not block.
    if (!block) {
        return NULL;
    }

    // Fill contiguous block of memory with 0 for the size.
    memset(block, 0, size);

    // Return block.
    return block;
}