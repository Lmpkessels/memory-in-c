#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "header.h"

// If there's enough memory return the block; else return NULL.
void *malloc(size_t size) {
    size_t total_size;
    void *block;
    header_t *header;

    if (!size) {
        return 0;
    }

    // Lock malloc, and get a free block.
    pthread_mutex_lock(&global_malloc_lock);
    header = get_free_block(size);

    // Check if free block, if free block, is free is 0, mutex is unlocked,
    // and the byte of the next block is returned.
    if (header) {
        header->s.is_free = 0;
        pthread_mutex_unlock(&global_malloc_lock);
        return (void*)(header + 1);
    }

    // Create total size.
    // Get first character of the block.
    // Check if memory can be allocated in OS, if not unlock malloc, and
    // return NULL.
    total_size = sizeof(header) + size;
    block = sbrk(total_size);
    if (block == (void*) -1) {
        pthread_mutex_unlock(&global_malloc_lock);
        return NULL;
    }

    // Set the header block back to default.
    header = block;
    header->s.size = size;
    header->s.is_free = 0;
    header->s.next = NULL;

    // Head is header when is not head.
    if (!head) {
        head = header;
    }

    // Next tail is header when tail.
    if (tail) {
        tail->s.next = tail;
    }

    // Tail is the last header of the linked list.
    tail = header;

    // When done with the process unlock malloc, and return the header.
    return (void*)(header + 1);
}

// Get a free block where data can be stored.
header_t *get_free_block(size_t size) {
    header_t *curr = head;

    while (curr) {
        // Return curr when curr is free and greater or equal then the size.
        if (curr->s.is_free && curr->s.size >= size) {
            return curr;
        }
        // Point to next head when is not free and not greater or equal then
        // size.
        curr = curr->s.next;
    }

    return NULL;
}