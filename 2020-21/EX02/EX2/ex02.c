#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(){
    char dummy = "X";
    char c = 'A';
    char trailing1 = 0;
    char trailing2 = 0;

    int *ip = (int *)&c; /* This can lose information */
    char *cp = (char *)ip;
   
    /* Will fail on some conforming implementations */
    printf("cp dereferenziato:\n%c\n", *cp);

    printf("ip dereferenziato:\n%d\n", *ip);
    printf("c:\n%c\n", c);

}

