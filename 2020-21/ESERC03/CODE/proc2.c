#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	pid_t pid;

	pid=fork();

	if(pid==0){
		//child
		printf("\nChild pid %d\n",(int)getpid());	
	
	}else{
		//parent
		printf("\nParent pid %d\n",(int)getpid());

	}


}
