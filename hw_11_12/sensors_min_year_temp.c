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
int string_in_file_to_sensor_struct(FILE* f, struct sensor* sens);
int check_correct_sensor(struct sensor* s);
int file_to_array_of_sensors(FILE* in, uint32_t number_of_strings_in_file, struct sensor** arr);
uint32_t file_to_string_count(FILE* f);
int16_t minimum_month_temperature(int month_number, int year_number, struct sensor** arr, int arr_size);
int8_t  minimum_year_temperature(int year_number, struct sensor** arr, int arr_size);

int main(void)
{
    FILE* in;

    if ((in = fopen("temperature_big.csv", "r")) == NULL)
    {
        printf("Can't open file %s\n", "temperature_big");
        exit(EXIT_FAILURE);
    }

    //определение количества строк в исходном файле 
    uint32_t number_of_strings_in_file = file_to_string_count(in);

    //выделение памяти под необходимое количество ссылок на структуру (массив ссылок)
    struct sensor** array_of_pointers = malloc(number_of_strings_in_file * sizeof(struct sensor*));


    //выделение памяти под необходимое количество структур (массив структур, доступ к ним
    //через массив ссылок)
    for (uint32_t i = 0; i < number_of_strings_in_file; i++)
    {
        array_of_pointers[i] = malloc(sizeof(struct sensor));
    }

    int processed_sensors_number = file_to_array_of_sensors(in, number_of_strings_in_file, array_of_pointers);

    int year_from_file = array_of_pointers[0]->year;

    printf("minimum %d year temp = ", array_of_pointers[0]->year);
    printf("%d\n", minimum_year_temperature(array_of_pointers[0]->year, array_of_pointers, processed_sensors_number));
    

    fclose(in);
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

int check_correct_sensor(struct sensor* s)
{
    if ((s->year < 1000) || (s->year > 2024))
        return 0;

    if ((s->month < 1) || (s->month > 12))
        return 0;

    if ((s->day < 1) || (s->day > 31))
        return 0;

    if ((s->hour < 0) || (s->hour > 23))
        return 0;

    if ((s->minute < 0) || (s->minute > 59))
        return 0;

    if ((s->temperature < -99) || (s->temperature > 99))
        return 0;

    return 1;
}

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

// записывает строки с показаниями датчика в специальный массив структур под показания
// ошибочные строки игнорирует 
// возвращает количество успешно записанных в массив структур строк с показаниями 
int file_to_array_of_sensors(FILE* in, uint32_t number_of_strings_in_file, struct sensor** arr)
{
    int number_of_readed_sensors = 0, string_record_flag = 1;
    FILE* file_current_string_pointer = 0;
    char ch = 0;

    for (uint32_t processed_strings = 0; (processed_strings < number_of_strings_in_file) && string_record_flag; processed_strings++)
    {
        long file_current_string_pointer = ftell(in);
        string_record_flag = string_in_file_to_sensor_struct(in, arr[number_of_readed_sensors]);

        if (string_record_flag == -1)
        {
            continue;
            //добавление processed_strings in queue
        }
        else if (string_record_flag == 0)
        {

            fseek(in, file_current_string_pointer, SEEK_SET);

            if ((ch = getc(in)) < 0)
            {
                processed_strings--;
                fseek(in, 0L, SEEK_SET);
                continue;
            }
            else
            {
                if (check_correct_sensor(arr[number_of_readed_sensors]))
                {
                    number_of_readed_sensors++;
                    continue;
                }
                else
                {
                    //добавление processed_strings in queue
                    continue;
                }

            }
        }
        else if (string_record_flag == 1)
        {
            if (!(check_correct_sensor(arr[number_of_readed_sensors])))
            {
                //добавление processed_strings in queue
                continue;
            }
            else
            {
                number_of_readed_sensors++;
            }
        }
    }

    return number_of_readed_sensors;
}

int string_in_file_to_sensor_struct(FILE* f, struct sensor* sens)
{
    sens->year = 0;
    sens->month = 0;
    sens->day = 0;
    sens->hour = 0;
    sens->minute = 0;
    sens->temperature = 0;


    int sensor_element = 0;
    char ch = 0;
    int negative_temperature_flag = 0;

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
                if (negative_temperature_flag)
                {
                    sens->temperature = sens->temperature * 10 - (ch - '0');
                }
                else
                {
                    sens->temperature = sens->temperature * 10 + (ch - '0');
                }
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
        else if ((ch == '-') && (sensor_element == 5) && (sens->temperature == 0))
        {
            negative_temperature_flag = 1;
        }
        else
        {
            return -1;
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

int16_t minimum_month_temperature(int month_number, int year_number, struct sensor** arr, int arr_size)
{
    int min_temp = 100;

    if ((month_number < 1) || (month_number > 12))
    {
        return -100;
    }

    for (int i = 0; i < arr_size; i++)
    {
        if (((arr[i]->year) == year_number) && ((arr[i]->month) == month_number) && ((arr[i]->temperature) < min_temp))
        {
            min_temp = arr[i]->temperature;
        }
    }

    return min_temp;
}

int8_t  minimum_year_temperature(int year_number, struct sensor** arr, int arr_size)
{
    int8_t year_min_temp = 100, current_month_temp;

    for (int i = 1; i <= 12; i++)
    {
        current_month_temp = minimum_month_temperature(i, year_number, arr, arr_size);

        if (current_month_temp < year_min_temp)
        {
            year_min_temp = current_month_temp;
        }
    }

    return year_min_temp;
}

