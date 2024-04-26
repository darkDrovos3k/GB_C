all: sensor_report

sensor_report: main.o temp_functions.o
	gcc -o sensor_report main.o temp_functions.o

main.o: main.c temp_functions.h
	gcc -c -o main.o main.c

temp_functions.o: temp_functions.c
	gcc -c -o temp_functions.o temp_functions.c

clean:
	rm *.o
	rm sensor_report