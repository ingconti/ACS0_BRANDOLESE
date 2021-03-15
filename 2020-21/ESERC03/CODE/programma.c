#include <stdio.h>

int main(int argc, char** argv){
	int i;

	for(i=0;i<argc;i++)
		printf("\nProgramma - print argument %d: %s\n",i,argv[i]);

}
