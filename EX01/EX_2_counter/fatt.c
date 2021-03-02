#include "fatt.h"

static int fatt(int n)
{
    if( n <=1 )
        return 1;

    return n * fatt( n-1 );
}

int incfatt( void )
{
    incrementa();
    return fatt( stato() );
}

int decfatt( void )
{
    decrementa();
    return fatt( stato() );
}
