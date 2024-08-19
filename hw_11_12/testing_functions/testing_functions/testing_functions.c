#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <inttypes.h>
#include <stdlib.h>

struct sensor
{
    uint16_t year;
    uint8_t month;
    uint8_t day;
    uint8_t hour;
    uint8_t minute;
    int8_t temperature;
};

int is_number(char ch);

int main(void)
{
    FILE* in;

    if ((in = fopen("temperature_big.csv", "r")) == NULL)
    {
        printf("Can't open file %s\n", "temperature_big");
        exit(EXIT_FAILURE);
    }

    //определение количества строк в исходном файле 
    //uint32_t number_of_sensors_in_file = file_to_string_count(in);

    //выделение памяти под необходимое количество ссылок на структуру (массив ссылок)
    //struct sensor** array_of_pointers = malloc(number_of_sensors_in_file * sizeof(struct sensor*));


    //выделение памяти под необходимое количество структур (массив структур, доступ к ним
    //через массив ссылок)
    //for (int i = 0; i < number_of_sensors_in_file; i++)
    //{
    //    array_of_pointers[i] = malloc(sizeof(struct sensor));
    //}


    int sensor_element = 0;
    char ch = 0;

    struct sensor test_sensor;

    test_sensor.year = 0;
    test_sensor.month = 0;
    test_sensor.day = 0;
    test_sensor.hour = 0;
    test_sensor.minute = 0;
    test_sensor.temperature = 0;

    for (; ((ch = getc(in)) != '\n') && (ch > 0);)
    {
        if (is_number(ch))
        {
            switch (sensor_element)
            {
            case 0:
                test_sensor.year = test_sensor.year * 10 + (ch - '0');
                break;
            case 1:
                test_sensor.month = test_sensor.month * 10 + (ch - '0');
                break;
            case 2:
                test_sensor.day = test_sensor.day * 10 + (ch - '0');
                break;
            case 3:
                test_sensor.hour = test_sensor.hour * 10 + (ch - '0');
                break;
            case 4:
                test_sensor.minute = test_sensor.minute * 10 + (ch - '0');
                break;
            case 5:
                test_sensor.temperature = test_sensor.temperature * 10 + (ch - '0');
                break;
            }
        }
        else if (ch == ';')
        {
            sensor_element++;
        }
        else if (ch == ' ')
        {
            continue;
        }
        else
        {
            return -1;
        }

    }

    printf("year = %d\n", test_sensor.year);
    printf("month = %d\n", test_sensor.month);
    printf("day = %d\n", test_sensor.day);
    printf("hour = %d\n", test_sensor.hour);
    printf("minute = %d\n", test_sensor.minute);
    printf("temperature = %d\n", test_sensor.temperature);

    if (ch < 0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}


int is_number(char ch)
{
    if ((ch <= '9') && (ch >= '0'))
    {
        return 1;
    }
    else
    {
        return 0;
    }
}