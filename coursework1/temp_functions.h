#include <stdio.h>
#include <stdlib.h>

#define SIZE 20
#define DEBUG 1


struct sensor {
    int temp;
    unsigned int minute;
    unsigned int hour;
    unsigned int day;
    unsigned int month;
    unsigned int year;
};

int data_array_sensor(FILE *fp, struct sensor data[]);
static void print_data_array_sensor(struct sensor data[], int count);
static int error_scanf(struct sensor d_sensor, int d);
int max_temp_year(struct sensor data[], int size);
int min_temp_year(struct sensor data[], int data_size);
int med_temp_year(struct sensor data[], int data_size);
int max_temp_month(struct sensor data[], int data_size, int month);
int min_temp_month(struct sensor data[], int data_size, int month);
int med_temp_month(struct sensor data[], int data_size, int month);