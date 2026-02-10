#include <stdio.h>
#include <string.h>


// Employe structure with for members.
struct employe {
    char firstname[20];
    char lastname[20];
    int age;
};

// Dereference to access addresses of given pointer to display,
// name, firstname, and age.
void show_name(struct employe *p) {
    printf("\n%s ", p->firstname);
    printf("%s ", p->lastname);
    printf("%d \n", p->age);
}

struct employe first_employe;
int main(void) {

    // Create pointer to structure employe.
    struct employe *p;
    // Point the pointer to first employe.
    p = &first_employe;

    // Assign values to members of the struct.
    strcpy(first_employe.firstname, "Peter");
    strcpy(first_employe.lastname, "Jansens");
    first_employe.age = 18;   
    
    // Call show name function to display assigned values of first_employe.
    show_name(p);
    
    return 0;
}