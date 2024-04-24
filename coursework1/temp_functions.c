#include "temp_functions.h"


int data_array_sensor(FILE *fp, struct sensor data[]) {
    struct sensor d_sensor = {0, 0, 0, 0, 0, 0};
//    struct sensor data[SIZE];
    char c[SIZE];
    int data_count = 0;
    int number_string = 1;
    int d;

    while ((d = fscanf(fp, "%d;%d;%d;%d;%d;%d",
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
            printf("error data, number string = %d\n", number_string);
        }

        number_string++;
    }
    print_data_array_sensor(data, data_count);

    return data_count;
}

static void print_data_array_sensor(struct sensor data[], int data_count) {
    for (int i = 0; i < data_count; i++) {
        printf("%d;%d;%d;%d;%d;%d;\n",
               data[i].year,
               data[i].month,
               data[i].day,
               data[i].hour,
               data[i].minute,
               data[i].temp);
    }
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
    int max = 0;
    for (int i = 0; i < data_size; i++) {
        if (data[i].temp > max) {
            max = data[i].temp;
        }
    }
    printf("max_temp = %d\n", max);
    return max;
}

int min_temp_year(struct sensor data[], int data_size) {
    int min = 99;
    for(int i = 0; i < data_size; i++) {
        if(data[i].temp < min) {
            min = data[i].temp;
        }
    }
    printf("min_temp = %d\n", min);
    return min;
}

int med_temp_year(struct sensor data[], int data_size) {
    int med_temp;
    int tmp = 0;

    for(int i = 0; i < data_size; i++) {
        tmp += data[i].temp;
    }
    med_temp = tmp / data_size;
    printf("med_temp = %d", med_temp);
    return med_temp;
}




















