#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"

#define T_FILE "/Users/drovos3k/CLionProjects/GB/C/coursework1/temperature_small.csv"


int main(int argc, char *argv[]) {
    FILE *fp;
    struct sensor *data;
    int res;
    int data_size;
    int month = 0;
    unsigned int size_str;

    while ((res = getopt(argc, argv, "hf:m:y")) != -1) {
        switch (res) {
            case 'h':
                printf("Программа sensor выводит среднюю, минимальную и максимальную температура за год/месяц\n");
                printf("    -h справка\n");
                printf("    -m <номер месяца> вся статистика за месяц\n");
                printf("    -y вся статистика за год\n");
                break;
            case 'f':
                fp = fopen(T_FILE, "r");
                if (fp == NULL) {
                    printf("Ошибка открытия файла %s\n", T_FILE);
                    exit(1);
                }
                size_str = file_size_str(fp);
                if ((data = malloc(size_str * sizeof(struct sensor))) != NULL) {
                    data_size = data_array_sensor(fp, data);
                }
                break;
            case 'm':
                if (atoi(optarg) >= 1 && atoi(optarg) <= 12) {
                    month = atoi(optarg);
                } else {
                    printf("Не верно указан месяц\n");
                }
                break;
            case 'y':
                max_temp_year(data, data_size);
                med_temp_year(data, data_size);
                min_temp_year(data, data_size);
                break;
        }
    }

    if (month) {
        max_temp_month(data, data_size, month);
        med_temp_month(data, data_size, month);
        min_temp_month(data, data_size, month);
    }

    free(data);
    fclose(fp);
    return 0;
}