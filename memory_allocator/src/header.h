#include <stddef.h>
#include <bits/pthreadtypes.h>

#ifndef HEADER_H
#define HEADER_H

typedef char ALIGN[16]; // To align the allocator with 16 bytes.

union header {
    struct header_t {
        size_t size; // Size of block.
        unsigned is_free; // To see if block is free.
        struct header_t *next; // To keep track of the block.
    } s; // Is used to get access to structure.
    ALIGN stub;
};

typedef union header header_t;
header_t *head, *tail;
pthread_mutex_t global_malloc_lock;

#endif