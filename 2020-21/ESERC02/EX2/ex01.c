#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef union MixedData{
    char c;
    int n;
    char s[17];
}MixedData;



typedef union MixedData{
    char c;
    int n;
    char s[17];
}MixedData;

typef struct Halves{
         unsigned short lowHalf;
         unsigned short highHalf;
}Halves;

typedef union register32 {    
    unsigned int R;
    unsigned short halves[2];
    Halves halves;
}register32;




int main(){

    MixedData md;
    printf("sizeof: %ld\n", sizeof(md));
    strcpy(md.s, "HELLO");
    md.c = 65 + 256 * 'B' ; // 'A' in ascii
    printf("%s\n", md.s);

    md.n = 66;
    printf("%s\n", md.s);

    return 0;
}

