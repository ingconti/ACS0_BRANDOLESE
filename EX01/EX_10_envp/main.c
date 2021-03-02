//
//  main.c
//  EX_7
//
//  Created by ing.conti on 01/03/21.
//

#include <stdio.h>
#include <stdlib.h>

int main(int argc, char *argv[], char *envp[])
{
    printf("%d\n", argc);
    
    
    char *home, *host, *path, *custom;
    
    home = getenv("HOME");
    host = getenv("HOSTNAME");
    //path = getenv ("PATH");
    custom = getenv ("VARNAME");

    
    //printf ("Your home %s on %s at: %s\n", home, host, path);
    //printf ("Your home %s on %s\n", home, host);
    printf ("Your custom  %s\n", custom);

    
    return 0;
    
}
