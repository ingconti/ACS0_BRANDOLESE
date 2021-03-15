#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	pid_t pid;
	char*  arg[]={"./programma", "ciao", "ciao",NULL};

	pid=fork();

	if(pid==0){
		//child
		printf("\nChild pid %d\n",(int)getpid());
		execvp("./programma",arg);	
	
	}else{
		//parent
		printf("\nParent pid %d\n",(int)getpid());
	}

}
