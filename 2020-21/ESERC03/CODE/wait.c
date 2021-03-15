#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv)
{
    pid_t pid_to_wait[10], pid, pid_ritornato;
    int status;
    int i;

    printf("Parent ID: %d\n", (int)getpid());
    for(i = 0; i < 10; i++)
    {
        pid = fork();
        if( pid == 0 ) // FIGLIO
        {
            printf("Child %d ID: %d\n",i, (int)getpid());
            exit(i);
        }
        else           // PADRE
        {
            pid_to_wait[i] = pid;
        }
    }

    printf("Parent - Aspetto il figlio 4\n");
    pid_ritornato = waitpid( pid_to_wait[3], &status, 0 );
    printf("Parent - Il pid del figlio 4 è %d, l'exit status è %d\n", pid_ritornato, WEXITSTATUS( status ) );

    // Attendere tutti gli altri figli
    for(i = 0; i < 9; i ++)
    {
        pid_ritornato = wait( &status );
        printf("Parent - Il pid è %d, l'exit status è %d\n", pid_ritornato, WEXITSTATUS( status ) );
    }

    return 0;
}
