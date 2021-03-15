#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int  myFuncA(int i){
//      printf("in A: %d\n",i);
      return i*3;
}

typedef int (*FooPtr)(int);

int  falloPiuVolte(FooPtr ff){
	int i;
	int tot = 0;
	for (i=0;i<10; i++){
		tot+=ff(i);	
	}
	return tot;
}

int main(){
  
    int k = falloPiuVolte(myFuncA);
    printf("%d\n",k);
    return 0;
}
