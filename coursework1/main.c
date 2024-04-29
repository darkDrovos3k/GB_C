#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "temp_functions.h"


int main(int argc, char *argv[]) {
    FILE *fp;
    struct sensor *data;
    int res;
    int data_size;
    unsigned short month = 0;
    unsigned int year = 0;
    unsigned int size_str;

    while ((res = getopt(argc, argv, "hf:m:y")) != -1) {
        switch (res) {
            case 'h':
                printf("Программа sensor_report выводит среднюю, минимальную и максимальную температура за год/месяц\n");
                printf("    -h справка\n");
                printf("    -f <файл>\n");
                printf("    -m <номер месяца> вся статистика за месяц\n");
                printf("    -y вся статистика за год\n");
                break;
            case 'f':
                fp = fopen(optarg, "r");
                if (fp == NULL) {
                    printf("Ошибка открытия файла %s\n", optarg);
                    exit(1);
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
                year = 1;
                break;
        }
    }

    if (fp) {
        if (month || year) {
            size_str = file_size_str(fp);
            if ((data = malloc(size_str * sizeof(struct sensor))) != NULL) {
                data_size = data_array_sensor(fp, data);

                if (month) {
                    max_temp_month(data, data_size, month);
                    med_temp_month(data, data_size, month);
                    min_temp_month(data, data_size, month);
                }

                if (year) {
                    max_temp_year(data, data_size);
                    med_temp_year(data, data_size);
                    min_temp_year(data, data_size);
                }

                free(data);
                fclose(fp);
            }
        }
    }
    return 0;
}