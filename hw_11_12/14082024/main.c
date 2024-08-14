#include "temp_function.h"


int main(int argc, char **argv)
{
    int month = 0;

    FILE* in;

    parsing_cmd (argc, argv, in, &month);

    int processed_sensors_number = 0;
    struct sensor** array_of_pointers = 0;

    processed_sensors_number = file_to_array_of_sensors(in, array_of_pointers);

    if (month)
    {
        printf("#\tYear\tMonth\tMonthAvg\tMonthMax\tMonthMin\n");
        printf("%d\t", 1);
        printf("%d\t", array_of_pointers[1]->year);
        printf("%d", month);
        printf("%f", average_month_temperature(month, array_of_pointers[1]->year, array_of_pointers, processed_sensors_number));
        printf("%d", maximum_month_temperature(month, array_of_pointers[1]->year, array_of_pointers, processed_sensors_number));
        printf("%d", minimum_month_temperature(month, array_of_pointers[1]->year, array_of_pointers, processed_sensors_number));
        printf("\n");
    }

    return 0;
}

