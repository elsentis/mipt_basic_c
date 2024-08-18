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
    int number_of_strings_in_file;
    int month;
    int processed_sensors_number;
    struct sensor** array_of_sensors;
};

void parsing_cmd (int argc, char **argv, FILE **file, int *month);
uint32_t file_to_string_count(FILE* f);
void print_help();
void add_temp(struct input_data in);

int main(int argc, char **argv)
{
    struct input_data current_input_data = {0, 0, 0, 0, 0};

    parsing_cmd (argc, argv,&(current_input_data.in), &(current_input_data.month));

    current_input_data.number_of_strings_in_file = file_to_string_count(current_input_data.in);

    current_input_data.array_of_sensors = malloc(current_input_data.number_of_strings_in_file * sizeof(struct sensor));

    for(int i = 0; i < current_input_data.number_of_strings_in_file; i++)
    {
        current_input_data.array_of_sensors[i] = malloc(sizeof(struct sensor));
    }

    add_temp(current_input_data);

    for(int i = 0; i < current_input_data.number_of_strings_in_file; i++)
    {
        printf("%d ", current_input_data.array_of_sensors[i]->temperature);
    }

    return 0;

}



void print_help()
{
    printf("Temp statistic application. Please enter key:\n");
    printf("-h for help.\n");
    printf("-f file_name for load this file.\n");
    printf("-m xx statistic for xx month.\n");
}



void parsing_cmd (int argc, char **argv, FILE **file, int *month)
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
                    *month = month_number;
                }
        }
    if(file_flag)
        {
             if ((*file = fopen(file_path, "r")) == NULL)
            {
                printf("Can't open file %s\n", file_path);
                exit(EXIT_FAILURE);
            }

            printf("%d\n", *file);
            char c = getc(*file);
            printf("%c\n", c);
            fseek(*file, 0L, SEEK_SET);
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

    if ((getc(f)) != '\n')
    {
        count++;
    }


    fseek(f, 0L, SEEK_SET);

    return count;
}

void add_temp(struct input_data in)
{
    for(int i = 0; i < in.number_of_strings_in_file; i++)
    {
        in.array_of_sensors[i]->temperature = i;
    }

}