int main( void )
{
		int f = fattoriale( 5 );
}

int fattoriale( int n )
{
	if( n < 1 )
		return 1;
	else
		return n * fattoriale(n-1);
}