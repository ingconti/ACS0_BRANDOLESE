#include <stdlib.h>
#include <stdio.h>


typedef struct Point{
	char color; // 'R' p.es.
	double x;
	double y;
}Point;

Point Origin(){
	Point p = {0,0};
	return p;
}



int main(){

	Point p = Origin();
	int dim = sizeof(p);
	double x = p.x;
	Point * pp = &p;
	double y = pp->y;
        printf("dimensione: %ld\n", dim);
	printf("dimensione di pp: %ld\n", sizeof(pp));

}

