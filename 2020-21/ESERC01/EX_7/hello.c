//
//  main.c
//  EX_7
//
//  Created by ing.conti on 01/03/21.
//

#include <stdio.h>

int main(int argc, const char * argv[]) {
    
    printf("found %d arguments\n", argc);

    int i;
    for (i=0; i<argc; i++){
        printf("%s\n", argv[0]);
    }
    
    return 0;

}
