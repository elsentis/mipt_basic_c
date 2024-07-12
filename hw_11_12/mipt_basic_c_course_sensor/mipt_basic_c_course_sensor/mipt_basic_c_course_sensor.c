#define _CRT_SECURE_NO_WARNINGS

#include "temp_api.h"

//#define SIZE 5 //(60*24*365)
#define MONTH_PER_YEAR 12



int main(void)
{
    FILE* in;

    if ((in = fopen("temperature_big.csv", "r")) == NULL)
    {
        printf("Can't open file %s\n", "temperature_big");
        exit(EXIT_FAILURE);
    }

    //определение количества строк в исходном файле 
    uint32_t number_of_sensors_in_file = file_to_string_count(in);

    //выделение пам€ти под необходимое количество ссылок на структуру (массив ссылок)
    struct sensor** array_of_pointers = malloc(number_of_sensors_in_file * sizeof(struct sensor*));
    

    //выделение пам€ти под необходимое количество структур (массив структур, доступ к ним
    //через массив ссылок)
    for (int i = 0; i < number_of_sensors_in_file; i++)
    {
        array_of_pointers[i] = malloc(sizeof(struct sensor));
    }

   


    //очистка выдел€емого массива структур
    for (int i = 0; i < number_of_sensors_in_file; i++)
    {
        free(array_of_pointers[i]);
    }

    file_to_arr_of_sensors(in, array_of_pointers);

    int i = 0;

    //очистка выдел€емого массива указателей
    free(array_of_pointers);

    fclose(in);

    return 0;
}

