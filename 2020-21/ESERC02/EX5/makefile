mylibmake: ex05.c sum.c sub.c sum.h sub.h
	gcc -Wall -c  sub.c sum.c 
	ar -qc libmylib.a *.o
	gcc -Wall ex05.c -L. -lmylib -o ex05

clean:
	 rm *.o
	 rm *.a
	 

