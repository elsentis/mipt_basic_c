#include "temp_function.h"

void print_help()
{
    printf("Temp statistic application. Please enter key:\n");
    printf("-h for help.\n");
    printf("-f file_name for load this file.\n");
    printf("-m xx statistic for xx month.\n");
}

//анализирует входные опции от пользователя и передает их в main
//если ошибки в входных данных выводит пользователю сообщение об ошибках и заканчивает выполнение программы
void parsing_cmd (int argc, char **argv, struct input_data* in)
{
    int res = 0, incorrect_sequencde_file_month_flag = 0, month_number = 0;
    int help_flag = 0, month_flag = 0, file_flag = 0;
    char file_path[256] = {0};

    for(opterr = 0; (res = getopt(argc, argv, "hf:m:")) != -1; )
    {
        switch(res)
        {
            case 'h': help_flag = 1;
                      break;
            case 'f': strcpy(file_path, argv[optind-1]);
                      //file_path = argv[optind + 1];
                      file_flag = 1;
                      break;
            case 'm':
                    {
                        if(file_flag == 0)
                            {
                                incorrect_sequencde_file_month_flag == 1;
                            }

                            month_flag = 1;
                            month_number = atoi(argv[optind - 1]);
                            break;
                    }
                      
            case '?': printf( "unrecognized command-line option '%s'\n", argv[optind-1]);
                      exit(EXIT_FAILURE);
                      break;
        }
    }

    if(help_flag)
        {
            print_help();
            exit(EXIT_FAILURE);
        }
    if (incorrect_sequencde_file_month_flag)
        {
            print_help();
            exit(EXIT_FAILURE);
        }

    if(month_flag)
        {
            if((month_number < 1) || (month_number > 12))
                {
                    printf("incorrect month number\n");
                    exit(EXIT_FAILURE);
                }
            else
                {
                    (*in).month = month_number;
                }
        }
    if(file_flag)
        {
             if (((*in).in = fopen(file_path, "r")) == NULL)
            {
                printf("Can't open file %s\n", file_path);
                exit(EXIT_FAILURE);
            }
        }

    return 0; 
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

    if (((getc(f)) != '\n') && (count>0))
    {
        count++;
    }


    fseek(f, 0L, SEEK_SET);

    return count;
}

void file_to_array_of_sensors(struct input_data* in)
{
    uint16_t number_of_readed_sensors = 0, string_record_flag = 1;
    char ch = 0;

    for (uint16_t processed_strings = 0; (processed_strings < in->number_of_strings_in_file) && string_record_flag; processed_strings++)
    {
        FILE* file_current_string_pointer = in->in;
        string_record_flag = string_in_file_to_sensor_struct(file_current_string_pointer, &(in->array_of_sensors[number_of_readed_sensors]));

        if (string_record_flag == -1)
        {
            continue;
            //äîáàâëåíèå processed_strings in queue
        }
        else if (string_record_flag == 0)
        {
            
            fseek(in->in, file_current_string_pointer, SEEK_SET);

            if ((ch = getc(in->in)) < 0)
            {
                processed_strings--;
                fseek(in->in, 0L, SEEK_SET);
                continue;
            }
            else
            {
                if (check_correct_sensor(&(in->array_of_sensors[number_of_readed_sensors])))
                {
                    number_of_readed_sensors++;
                    continue;
                }
                else
                {
                    //äîáàâëåíèå processed_strings in queue
                    continue;
                }
                
            }
        }
        else if (string_record_flag == 1)
        {
            if (!(check_correct_sensor(&(in->array_of_sensors[number_of_readed_sensors]))))
            {
                //äîáàâëåíèå processed_strings in queue
                continue;
            }
            else
            {
                number_of_readed_sensors++;
            } 
        }
    }

    in->processed_sensors_number = number_of_readed_sensors;
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

float average_month_temperature(int month_number, int year_number, struct sensor** arr, int arr_size)
{
    int current_month_sensors_count = 0, summ_of_source_temp = 0;

    if ((month_number < 1) || (month_number > 12))
    {
        return -100;
    }

    for (int i = 0; i < arr_size; i++)
    {
        if (((arr[i]->year) == year_number) && ((arr[i]->month) == month_number))
        {
            summ_of_source_temp += arr[i]->temperature;
            current_month_sensors_count++;
        }
    }

    if (current_month_sensors_count != 0)
    {
        return (float)summ_of_source_temp / current_month_sensors_count;
    }
    else
    {
        return -100;
    }
    
}

int16_t maximum_month_temperature(int month_number, int year_number, struct sensor** arr, int arr_size)
{
    int max_temp = -100;

    if ((month_number < 1) || (month_number > 12))
    {
        return -100;
    }

    for (int i = 0; i < arr_size; i++)
    {
        if (((arr[i]->year) == year_number) && ((arr[i]->month) == month_number) && ((arr[i]->temperature) > max_temp))
        {
            max_temp = arr[i]->temperature;
        }
    }

    return max_temp;
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