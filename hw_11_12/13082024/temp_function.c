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
void parsing_cmd (int argc, char **argv, FILE *file, int *month)
{
    int res = 0, incorrect_sequencde_file_month_flag = 0, month_number = 0;
    int help_flag = 0, month_flag = 0, file_flag = 0;
    char *file_path = 0;
    

    for(opterr = 0; (res = getopt(argc, argv, "hf:m:")) != -1; )
    {
        switch(res)
        {
            case 'h': help_flag = 1;
                      break;
            case 'f': file_path = argv[optind - 1];
                      file_flag = 1;
                      break;
            case 'm':
                    {
                        if(file_flag == 0)
                            {
                                incorrect_sequencde_file_month_flag == 1;
                            }

                            month_flag = 1;
                            month_number = (argv[optind - 1] - '0');
                            break;
                    }
                      
            case '?': printf( "unrecognized command-line option '%s'\n", argv[optind-1]);
                      break;
        }
    }

    if(help_flag)
        {
            print_help();
            exit(EXIT_FAILURE);
        }
    else if (incorrect_sequencde_file_month_flag)
        {
            print_help();
            exit(EXIT_FAILURE);
        }
    else if(month_flag)
        {
            if((month_number < 1) || (month_number > 12))
                {
                    printf("incorrect month number\n");
                    exit(EXIT_FAILURE);
                }
            else
                {
                    *month = month_number;
                }
        }
    else if(file_flag)
        {
             if ((file = fopen(file_path, "r")) == NULL)
            {
                printf("Can't open file %s\n", file_path);
                exit(EXIT_FAILURE);
            }
        }

    return 0; 
}

int file_to_array_of_sensors(FILE* in, uint32_t number_of_strings_in_file, struct sensor** arr)
{
    uint32_t number_of_strings_in_file = file_to_string_count(in);

    array_of_pointers = malloc(number_of_strings_in_file * sizeof(struct sensor*));

    for (uint32_t i = 0; i < number_of_strings_in_file; i++)
    {
        array_of_pointers[i] = malloc(sizeof(struct sensor));
    }

     int processed_sensors_number = file_to_array_of_sensors_aux(in, number_of_strings_in_file, array_of_pointers);

     return processed_sensors_number;
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


int file_to_array_of_sensors_aux(FILE* in, uint32_t number_of_strings_in_file, struct sensor** arr)
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
            //äîáàâëåíèå processed_strings in queue
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
                    //äîáàâëåíèå processed_strings in queue
                    continue;
                }
                
            }
        }
        else if (string_record_flag == 1)
        {
            if (!(check_correct_sensor(arr[number_of_readed_sensors])))
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