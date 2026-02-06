#include <stdio.h>

// Creating reusable variable through pointers.
// Also taking a look at how a string in C is a array of characters.
//
// This is how a string is represented in C, its a array of characters.
int an_actual_string_in_c(void) {
    char word[40];
    char cap_h='H', e='e', o='o', comm=',', space=' ', 
    capp_w='W', r='r', l='l', d='d', excl='!', null='\0';
    
    char *pcap_h=&cap_h, *pe=&e, *po=&o, *pcomm=&comm, 
    *pspace=&space, *pcapp_w=&capp_w, *pr=&r, *pl=&l, 
    *pd=&d, *pexcl=&excl, *pnull=&null;

    // Assigning each ivalue to a character.
    word[0] = *pcap_h;
    word[1] = *pe;
    word[2] = *pl;
    word[3] = *pl;
    word[4] = *po;
    word[5] = *pcomm;
    word[6] = *pspace;
    word[7] = *pcapp_w;
    word[8] = *po;
    word[9] = *pr;
    word[10] = *pl;
    word[11] = *pd;
    word[12] = *pexcl;
    word[13] = *pnull;

    printf("%s", word);
    
    return 0;
}

// Assigned string of 80 bytes
char stringA[80] = "A random string thats used for exploration purposes"; 
char stringB[80]; // String of 80 bytes

// Copy one string to all variables using pointers.
int copy_string(void) {
    char *pointerA; // Pointer
    char *pointerB; // Pointer

    puts(stringA); // Display string A 
    pointerA = stringA; // Let pointer A point to address of string A
    puts(pointerA); // Display pointer A (string A which is pointed to)
    pointerB = stringB; // Let pointer B point to address of string B
    putchar('\n'); // Put character new line

    // Loop for as long as pointer A is not a byte of all 0s
    while (*pointerA != '\0') {
        /* Access memory of pointer A and B, and store pointer A in pointer
           B (pointer A and pointer B are incremented by one to move up by one
           character per itteration).*/
        *pointerB++ = *pointerA++;
    }

    *pointerB = '\0'; // Let pointer B be a byte of all 0s (null character).
    puts(stringB); // Display string B
    return 0;
}

// Copy a string using both parameters destination and source.
//
// Const ensures that the contents pointed to will not be modified by the
// source pointer.
char *string_copy(char *destination, const char *source) {
    // Point to the address of destination.
    char *p = destination;

    while (*source != '\0') {
        // Dereference and copy the value of source into p so destination.
        //
        // Incrementing is done such that the entire string is coppied because
        // each character has an address of itself.
        *p++ = *source++;
    }

    // Let p be a null character.
    *p = '\0';

    // Return destination.
    return destination;
}

int main() {
    copy_string();
    printf("%s\n", string_copy(stringB, stringA));
}