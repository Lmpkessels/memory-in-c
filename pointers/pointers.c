#include <stdio.h>

// Working with pointers, accessing an address and displaying multiple addresses. 
int main() {
    int x, y, z, *ptr;

    x = 1;
    y = 2;
    z = y;

    ptr = &z;

    // Dereferencing the pointer allows us to access the value stored in the
    // address.
    printf("%.0d\n", *ptr);

    // (void *) allows us to get the address of the pointer.
    printf("%p\n", (void *)&x);

    printf("The value 'x' is %.0d is 1 and stored at %p\n", x, (void *)&x);
    printf("The value 'y' is %.0d is 2 and stored at %p\n", y, (void *)&y);
    printf("The value 'z' is %.0d is 2 and stored at %p\n", z, (void *)&z);
    printf(
        "The value of 'ptr' is %.0d because 2 is the value of 'y' and 'y' is"\
        "'z', and is stored at %p\n", *ptr, (void *)&ptr
    );
}