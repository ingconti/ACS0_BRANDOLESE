/*Il processo padre accetta sulla linea di comando un argomento numerico intero N che deve essere minore di 16, altrimenti il programma termina.
 Il processo padre crea quindi N processi figli
 Ogni processo figlio genera un numero casuale da 1 a 10 e, se tale numero è
 maggiore di 5, invia un segnale al processo padre, quindi termina sempre con stato di
 uscita pari a 0.
 Il processo padre conta il numero di segnali ricevuti e lo stampa a video*/


#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include <signal.h>
#include <semaphore.h>

// to test against concorrency, use  a fixed value
// we will add a very high number of procvesses to stress "cont++"


#define TEST_MULTIPLE_ACCESS 1


#ifdef TEST_MULTIPLE_ACCESS
int DEFAULT_N = 5000;
#else
int DEFAULT_N = 5;

#endif


sem_t semaforo;
int cont=0;

void signal_handler(int signal) {
    sem_wait(&semaforo);
    cont++;
    sem_post(&semaforo);
}


int myrand(){
#ifdef TEST_MULTIPLE_ACCESS
    return 100;
#else
    int r = arc4random() % 10 + 1;
    return  r;
#endif
    
}


int main(int argc, char ** argv) {
    // read cmd line, but with fall back to default.
    // (it will fault if no param added)
    int N = DEFAULT_N;
    if (argc>1)
        N = atoi(argv[1]);
    
    pid_t parent_pid = getpid();
    pid_t pid, pid_to_wait[N], pid_ritornato;
    int status;
    
    signal(SIGUSR1, &signal_handler);
    
    semaforo = sem_init(&semaforo,0,1);
    for (int i = 0; i < N; i++) {
        pid = fork();
        
        if (pid == 0) {
            //child
            //printf("child pid %d\n", (int)getpid());
            
            int g = myrand();
            printf("valore casuale %d\n", g);
            if (g > 5) {
                kill(parent_pid, SIGUSR1);
            }
            exit(0);
        }
        else {
            //parent
            pid_to_wait[i] = pid;
            
        }
        
    }
    for (int j = 0; j < N; j++) {
        pid_ritornato = wait(&status);
        // printf("parent - tornato il figlio con pid %d, exit status: %d\n", pid_ritornato, WEXITSTATUS(status));
    }
    
    printf(" segnali: %d\nbatti invio x uscire.", cont);
    char s[10];
    scanf("%s", s);
    
    return 0;
}

