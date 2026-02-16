#include <stdlib.h>
#include "header.h"
#include "malloc.h"
#include "free.h"

// Reallocate memory through copying the block.
void *realloc(void *block, size_t size) {
    header_t *header;
    void *ret;

    // If not block or not size then return then return the size
    // allocated to a block of memory.
    if (!block || !size) {
        return malloc(size);
    }
    
    // Move one header sized step back in memory to access header.
    header = (header_t*)block - 1;

    // Check if the block fits in the current block, through checking
    // the size in the header.
    if (header->s.size >= size) {
        return block;
    }

    // Allocate the size to a block of memory and assign it to ret.
    ret = malloc(size);

    if (ret) {
        // Reallocate memory to a new bigger block, and free the old
        // memory block.
        memcpy(ret, block, header->s.size);
        free(block);
    }

    return ret;
}