#include <stdio.h>
#include <stdlib.h> //for exit() func
#include <unistd.h>// for getopt() func

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

void print_help();
void parsing_cmd (int argc, char **argv, FILE *file, int *month);
uint32_t file_to_string_count(FILE* f);
int file_to_array_of_sensors(FILE* in, uint32_t number_of_strings_in_file, struct sensor** arr);
int file_to_array_of_sensors_aux(FILE* in, uint32_t number_of_strings_in_file, struct sensor** arr);
int string_in_file_to_sensor_struct(FILE* f, struct sensor* sens);
int check_correct_sensor(struct sensor* s);