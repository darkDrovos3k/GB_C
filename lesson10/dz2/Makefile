all: dz2

dz2: dz2.o dz2_func.o
	gcc -o dz2 dz2.o dz2_func.o

dz2.o: dz2.c dz2.h
	gcc -c -o dz2.o dz2.c

dz2_func.o: dz2.c
	gcc -c -o dz2_func.o dz2_func.c

clean:
	rm *.o