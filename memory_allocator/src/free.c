#include "header.h"

// Free, checks if a block of data is at the end of the heap, if it is then
// it is freed an released in the OS, else if it's not at the end of the heap
// it's given a tag 'free'.
void free(void *block) {
    header_t *header, *tmp;
    void *programbreak;

    if (!block) {
        return; // When not matching block emediately return back.
    }

    pthread_mutex_lock(&global_malloc_lock);
    header = (header_t*)block + 1;
    
    // Stop the current process.
    programbreak = sbrk(0); 
    
    // When the current process is terminated, set head and tail to NULL if
    // head is tail.
    //
    // If head is not tail tmp is head, and while tmp, if tmp pointing to 
    // s.next is tail, tmp pointing to s.next becomes 0, then tail is tmp
    // when tail is tmp the end of the block is there.
    //
    // tmp = tmp pointing to s.next so it does not go back into if again.
    if ((char*)block + header->s.size == programbreak) {
        if (head == tail) {
            head = tail = NULL; // Make head and tail zero.
        } else {
            tmp = head;
            while (tmp) {
                if (tmp->s.next == tail) {
                    tmp->s.next = NULL; // Make next zero.
                    tail = tmp;
                }
                tmp = tmp->s.next;
            }
        }

        // Give a negative number which is the amount of data that's freed
        // from memory.
        sbrk(0 - sizeof(header_t) - header->s.size);
        
        // Unlock the thread.
        pthread_mutex_unlock(&global_malloc_lock);
        return;
    }

    // When none of the above questions are true let the header field, is_free
    // be one since it is not freed.
    header->s.is_free = 1;

    // Unlock the thread.
    pthread_mutex_unlock(&global_malloc_lock);
}