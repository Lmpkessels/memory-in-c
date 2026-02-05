#include <stdio.h>

// Creating reusable variable through pointers.
// Also taking a look at how a string in C is a array of characters.
int main() {
    char word[40];
    char cap_h='H', e='e', o='o', comm=',', space=' ', 
    capp_w='W', r='r', l='l', d='d', excl='!', nl='\n';
    
    char *pcap_h=&cap_h, *pe=&e, *po=&o, *pcomm=&comm, 
    *pspace=&space, *pcapp_w=&capp_w, *pr=&r, *pl=&l, 
    *pd=&d, *pexcl=&excl, *pnl=&nl;

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
    word[13] = *pnl;

    printf("%s", word);
}