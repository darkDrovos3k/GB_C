#include "temp_functions.h"


int data_array_sensor(FILE *fp, struct sensor data[]) {
    struct sensor d_sensor = {0, 0, 0, 0, 0, 0};
    char c[SIZE];
    int data_count = 0;
    int number_string = 1;
    int d;

    while ((d = fscanf(fp, "%d;%hd;%hd;%hd;%hd;%hd",
                       &d_sensor.year,
                       &d_sensor.month,
                       &d_sensor.day,
                       &d_sensor.hour,
                       &d_sensor.minute,
                       &d_sensor.temp)) > 0) {

        if (error_scanf(d_sensor, d)) {
            data[data_count].year = d_sensor.year;
            data[data_count].month = d_sensor.month;
            data[data_count].day = d_sensor.day;
            data[data_count].hour = d_sensor.hour;
            data[data_count].minute = d_sensor.minute;
            data[data_count].temp = d_sensor.temp;
            data_count++;
        } else {
            fscanf(fp, "%[^\n]", c);
            printf("Ошибка ввода данных в строке = %d\n", number_string);
            printf("=================================\n");
        }
        number_string++;
    }
    return data_count;
}

static int error_scanf(struct sensor d_sensor, int d) {
    if ((d < 6) ||
        (d_sensor.year < 1972 || d_sensor.year > 9999) ||
        (d_sensor.month < 1 || d_sensor.month > 12) ||
        (d_sensor.day < 1 || d_sensor.day > 31) ||
        (d_sensor.hour < 0 || d_sensor.hour > 23) ||
        (d_sensor.minute < 0 || d_sensor.minute > 59) ||
        (d_sensor.temp < -99 || d_sensor.temp > 99)) {
        return 0;
    }
    return 1;
}

int max_temp_year(struct sensor data[], int data_size) {
    int max = -99;

    for (int i = 0; i < data_size; i++) {
        if (data[i].temp > max) {
            max = data[i].temp;
        }
    }

    printf("Максимальная температура за год = %d\n", max);
    return max;
}

int min_temp_year(struct sensor data[], int data_size) {
    int min = 99;

    for (int i = 0; i < data_size; i++) {
        if (data[i].temp < min) {
            min = data[i].temp;
        }
    }

    printf("Минимальная температура за год = %d\n", min);
    return min;
}

int med_temp_year(struct sensor data[], int data_size) {
    int med_temp;
    int tmp = 0;

    for (int i = 0; i < data_size; i++) {
        tmp += data[i].temp;
    }

    med_temp = tmp / data_size;
    printf("Средняя температура за год = %d\n", med_temp);
    return med_temp;
}

int max_temp_month(struct sensor data[], int data_size, int month) {
    int max_temp = -99;

    for (int i = 0; i < data_size; i++) {
        if (data[i].month == month && data[i].temp > max_temp) {
            max_temp = data[i].temp;
        }
    }

    printf("Максимальная температура за месяц = %d\n", max_temp);
    return max_temp;
}

int min_temp_month(struct sensor data[], int data_size, int month) {
    int min_temp = 99;

    for (int i = 0; i < data_size; i++) {
        if (data[i].month == month && data[i].temp < min_temp) {
            min_temp = data[i].temp;
        }
    }

    printf("Минимальная температура за месяц = %d\n", min_temp);
    return min_temp;
}

int med_temp_month(struct sensor data[], int data_size, int month) {
    int med_temp;
    int temp_count = 0;
    int tmp = 0;

    for (int i = 0; i < data_size; i++) {
        if (data[i].month == month) {
            tmp += data[i].temp;
            temp_count++;
        }
    }

    med_temp = tmp / temp_count;
    printf("Средняя температура за месяц = %d\n", med_temp);
    return med_temp;
}

int file_size_str(FILE *fp) {
    int size_str = 0;

    while (!feof(fp)) {
        fscanf(fp, "%*[^\n]%*c");
        size_str++;
    }

    fseek(fp, SEEK_SET, 0);
    return size_str;
}


















