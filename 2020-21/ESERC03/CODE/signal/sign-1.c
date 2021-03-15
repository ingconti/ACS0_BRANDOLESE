#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <sys/types.h>
#include <sys/wait.h>

typedef void(*sighandler_t) (int);

void signal_handler(int sig){
	if(sig==SIGUSR1){
		printf("\nHandling SIGUSR1\n");
		exit(0);
	}

}

void signal_handler2(int sig){
	if(sig==SIGUSR2){
		printf("\nHandling SIGUSR2\n");
		exit(0);
	}
}

int main(int argc, char** argv){
	sighandler_t previous;
	
	printf("\nAttendo un tuo segnale, scegli tu se inviare SIGUSR1 o SIGUSR2\n");

	//Registro l'handler per SIGUSR1
	previous= signal(SIGUSR1, signal_handler);
	if(previous==SIG_ERR)
		printf("\nErrore nel registrare il signal handler per SIGUSR1\n");

	//Registro l'handler per SIGUSR2
	previous= signal(SIGUSR2, signal_handler2);
	if(previous==SIG_ERR)
		printf("\nError Errore nel registrare il signal handler per SIGUSR2\n");

	
	while(1);
	return 0;


}
