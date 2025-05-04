#include <stdio.h>
#include <stdlib.h> //for exit() func
#include <unistd.h>// for getopt() func
#include <inttypes.h>
#include <string.h>

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

struct input_data
{
    FILE* in;
    uint16_t number_of_strings_in_file;
    uint8_t month;
    uint16_t processed_sensors_number;
    struct sensor** array_of_sensors;
};


void parsing_cmd (int argc, char **argv, struct input_data* in);
void print_help();
uint32_t file_to_string_count(FILE* f);
void file_to_array_of_sensors(struct input_data* in);
int string_in_file_to_sensor_struct(FILE* f, struct sensor** sens);
int check_correct_sensor(struct sensor** s);
float average_month_temperature(int month_number, int year_number, struct sensor** arr, int arr_size);
int16_t maximum_month_temperature(int month_number, int year_number, struct sensor** arr, int arr_size);
int16_t minimum_month_temperature(int month_number, int year_number, struct sensor** arr, int arr_size);
int is_number(char ch);
float average_year_temperature(struct sensor** s, int n);
int16_t maximum_year_temperature(struct sensor** s, int n);
int16_t minimum_year_temperature(struct sensor** s, int n);
