all: sensor

sensor: main.o temp_functions.o
	gcc -o sensor main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

clean:
	rm *.o
	rm sensor