#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	int  a=1;
	int* b=&a;	
	pid_t pid;

	pid=fork();

	if(pid==0){
		//child
		printf("\nChild pid %d\n",(int)getpid());
		printf("\nChild b deref %d\n",(*b));	
			
	}else{
		//parent
		a=4;
		printf("\nParent pid %d\n",(int)getpid());
		printf("\nParent b deref %d\n",(*b));

	}


}
