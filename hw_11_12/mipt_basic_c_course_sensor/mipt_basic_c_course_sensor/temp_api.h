#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

#define _CRT_SECURE_NO_WARNINGS

#define STRING_LENGTH 509

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};


float monthly_average_temperature(struct sensor**, int, int);

int monthly_minimum_temperature(struct sensor*, int);

int monthly_maximum_temperature(struct sensor*, int);

float year_average_temperature(struct sensor*, int);

int year_minimum_temperature(struct sensor*, int);

int year_maximum_temperature(struct sensor*, int);

int file_to_arr_of_sensors(FILE*, struct sensor*);

uint32_t file_to_string_count(FILE* f);

int string_in_file_to_sensor_struct(FILE* f, struct sensor*);