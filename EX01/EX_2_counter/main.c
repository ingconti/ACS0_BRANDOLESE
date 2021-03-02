#include <stdio.h>
#include "fatt.h"
#include "counter.h"

int main()
{
    int i;

    printf("%d\n", stato());
    for(i=0;i<5;i++)
        printf( "%d\n", incfatt() );

    for(i=0;i<3;i++)
        printf( "%d\n", decfatt() );

    return 0;
}
