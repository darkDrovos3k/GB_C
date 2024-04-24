#include <stdio.h>
#include <stdlib.h>
#include "temp_functions.h"

#define SIZE 20

#define T_FILE "/Users/drovos3k/CLionProjects/GB/C/coursework1/temperature_small.csv"


int main(void) {
    int data_size = 0;
    struct sensor data[SIZE];

    FILE *fp = fopen(T_FILE, "r");

    if (fp == NULL) {
        printf("Ошибка открытия файла %s", T_FILE);
        exit(1);
    }

    data_size = data_array_sensor(fp, data);
    max_temp_year(data, data_size);
    min_temp_year(data, data_size);
    med_temp_year(data, data_size);

}