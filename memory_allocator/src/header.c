#include <stdio.h>

// A header is needed for every newly allocated memory block such that it 
// can be found to free it.
// 
// Two things must be stored 1) size of block 2) whether its free or not.
//
// The header will be added to every newly allocated memory block.
//
// To calculate the total size: total_size = heade_t + size, then, 
// sbrk(total_size) is called.
//
// The memory space returned by 'sbrk()' is used to fit in 1) the header
// block 2) the memory block.
typedef char ALIGN[16]; // To align the allocator with 16 bytes.

union header {
    struct header_t {
        size_t size; // Size of block.
        unsigned is_free; // To see if block is free.
        struct header_t *next; // To keep track of the block.
    } s;
    ALIGN stub;
};

typedef union header header_t;

// Head and tail pointer to keep track of the list.
header_t *head, *tail;

// Before every action aquire the lock, when done release the lock.
pthread_mutex_t global_malloc_lock;