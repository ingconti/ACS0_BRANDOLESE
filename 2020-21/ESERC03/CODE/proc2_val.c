#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>

int main(int argc, char** argv){
	int  a=1;
	pid_t pid;

	pid=fork();

	if(pid==0){
		//child
        a++;
		printf("\nChild pid %d\n",(int)getpid());
		printf("\nChild b deref %d\n",a);
			
	}else{
		//parent
		a=100;
		printf("\nParent pid %d\n",(int)getpid());
		printf("\nParent a %d\n",a);

	}


}
