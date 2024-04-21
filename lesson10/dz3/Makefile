all: dz3

dz3: dz3.o dz3_func.o
	gcc -o dz3 dz3.o dz3_func.o

dz3.o: dz3.c dz3.h
	gcc -c -o dz3.o dz3.c

dz3_func.o: dz3.c
	gcc -c -o dz3_func.o dz3_func.c

clean:
	rm *.o
	rm dz3