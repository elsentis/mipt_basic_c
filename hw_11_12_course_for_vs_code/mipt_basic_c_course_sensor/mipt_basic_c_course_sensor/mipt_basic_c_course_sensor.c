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

    //����������� ���������� ����� � �������� ����� 
    uint32_t number_of_sensors_in_file = file_to_string_count(in);

    //��������� ������ ��� ����������� ���������� ������ �� ��������� (������ ������)
    struct sensor** array_of_pointers = malloc(number_of_sensors_in_file * sizeof(struct sensor*));
    

    //��������� ������ ��� ����������� ���������� �������� (������ ��������, ������ � ���
    //����� ������ ������)
    for (int i = 0; i < number_of_sensors_in_file; i++)
    {
        array_of_pointers[i] = malloc(sizeof(struct sensor));
    }

   


    //������� ����������� ������� ��������
    for (int i = 0; i < number_of_sensors_in_file; i++)
    {
        free(array_of_pointers[i]);
    }

    file_to_arr_of_sensors(in, array_of_pointers);

    int i = 0;

    //������� ����������� ������� ����������
    free(array_of_pointers);

    fclose(in);

    return 0;
}

