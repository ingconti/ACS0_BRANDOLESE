#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	pid_t pid, pid_to_wait[10],pid_ritornato;
	int status;
	int i;

	printf("Parent pid %d\n",(int)getpid());
	for(i=0;i<10;i++){
	pid=fork();

		if(pid==0){
			//child
			printf("Child pid %d\n",(int)getpid());	
			exit(i);
		}else{
			//parent
			pid_to_wait[i]=pid;
		}
	}

	//esegue nel padre in quanto i figli hanno effettuato la exit	
	printf("\nParent - Ho dieci figli, attenderò prima il figlio n°4 con waitpid, poi tutti gli altri con wait\n");
	pid_ritornato= waitpid( pid_to_wait[4], &status, 0 );
	printf( "\nParent - Effettuata waitpid sul quarto figlio\nIl suo pid è %d,l'exit status %d\n", pid_ritornato, WEXITSTATUS( status ) );

	//attendo tutti gli altri
	// Waits for all other children
	printf( "Parent - Attendo gli altri\n" );
	for( i= 0; i< 9; i++ ) {
	pid_ritornato = wait( &status );
	printf( "Parent - Tornato il figlio con pid %d, exit status: %d\n",pid_ritornato, WEXITSTATUS( status ));
	}




}
