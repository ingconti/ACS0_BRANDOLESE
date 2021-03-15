#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

#include <unistd.h>


void alarm_handler( int sig )
{
  printf( "Allarme ricevuto, sono passati 10 secondi\n" );
  exit( 1 );
}


int main( int argc, char** argv )
{
  // Registro l'handler
  if( signal( SIGALRM, alarm_handler ) == SIG_ERR ) {
    printf( "Errore nel registrare l'handler per SIGALARM\n" );
    exit( 1 );
  } 

  printf( "Ho impostato l'allarme, scatterà tra 10 secondi\n" );
  alarm( 10 ); 
 
  while(1);

  return 0;
}

