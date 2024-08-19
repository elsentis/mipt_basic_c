#include "temp_api.h"



uint32_t file_to_string_count(FILE* f)
{
    
    uint32_t count = 0;

    fseek(f, 0L, SEEK_SET);

    for (char ch = 0; ((ch = getc(f)) > 0); )
    {
        if (ch == '\n')
        {
            count++;
        }
    }

    fseek(f, -1L, SEEK_CUR);

    if ((getc(f)) != '\n')
    {
        count++;
    }


    fseek(f, 0L, SEEK_SET);

    return count;
}

float monthly_average_temperature(struct sensor** arr, int month_number, int array_size)
{
    float temperature_summ = 0;
    float day_count = 0;

    for (int i = 0; i < array_size; i++)
    {
        if (arr[i]->month != month_number)
        {
            continue;
        }

        temperature_summ += arr[i]->temperature;
        day_count++;
    }

    return temperature_summ / day_count;
}

// считывает строки из файла с данными в массив структур sensor
// возвращает количество успешно записанных структур sensor
int file_to_arr_of_sensors(FILE* f, struct sensor* arr, int number_of_strings_in_file)
{
    int i = 0;
    int end_of_file_flag = 0;
    for (; (i < number_of_strings_in_file) && string_in_file_to_sensor_struct(f, arr); i++);

    return i; 
}


// считывает строку из файла в структуру sensor 
// если конец файла возвращает 0
int string_in_file_to_sensor_struct(FILE * f, struct sensor* sens)
{
    int sensor_element = 0;
    char ch = 0;

    sens->year = 0;
    sens->month = 0;
    sens->day = 0;
    sens->hour = 0;
    sens->minute = 0;
    sens->temperature = 0;

    for (; ((ch = getc(f)) != '\n') && (ch > 0);)
    {
        if (is_number(ch))
        {
            switch (sensor_element)
            {
            case 0:
                sens->year = sens->year * 10 + (ch - '0');
                break;
            case 1:
                sens->month = sens->month * 10 + (ch - '0');
                break;
            case 2:
                sens->day = sens->day * 10 + (ch - '0');
                break;
            case 3:
                sens->hour = sens->hour * 10 + (ch - '0');
                break;
            case 4:
                sens->minute = sens->minute * 10 + (ch - '0');
                break;
            case 5:
                sens->temperature = sens->temperature * 10 + (ch - '0');
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
        
    }

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

