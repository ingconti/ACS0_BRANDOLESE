#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef void (*sighandler_t)(int);

void signal_handler( int sig ) {
  int status;
  pid_t pid;

  // Waitpid non bloccante, che attende qualunque processo (primo parametro è zero)

  pid=waitpid( 0, &status, WNOHANG );
  printf( "Sono l'handler, è arrivato il figlio pid: %d, exit status: %d. Esco\n",pid, WEXITSTATUS( status ) );
  exit(0);
}

int main( int argc, char** argv )
{
  pid_t pid;

  printf("Questo programma aspetta i figli con la waitpid non bloccante sfruttando i segnali\n");	

  printf("Registro l'handler epr SIGCHLD\n");

  if( signal( SIGCHLD, signal_handler ) == SIG_ERR ) {
    printf( "Errore nel registrare l'handler per SIGCHLD\n" );
    exit( 1 );
  } 

  
  pid = fork();
  
  if( pid == 0 ) {


    printf( "Child pid: %d\n", getpid());
    sleep(2);
    printf( "Child - exit con codice 33\n" );
    exit( 33 );

  } else {

    printf( "Parent - pid: %d, entro in while(1)\n", getpid() );
    while(1);
  }

}
