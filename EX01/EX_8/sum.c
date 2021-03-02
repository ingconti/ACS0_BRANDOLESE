#include <stdio.h>
#include <stdlib.h>

int main( int argc, char* argv[] )
{
    int n, m;
    if( argc != 3 )
    {
        printf("ERROR: %s <num1> <num2>\n",argv[0]);
        return -1;
    }
    // 0 e' il nome delle exe!
    n = atoi( argv[1] );
    m = atoi( argv[2] );

    printf("%d\n", n + m);

    return 0;
}
