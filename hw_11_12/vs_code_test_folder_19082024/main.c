#include "temp_function.h"


int main(int argc, char **argv)
{
    struct input_data current_input_data = {0, 0, 0, 0, 0};

    parsing_cmd (argc, argv,(&current_input_data));
    current_input_data.number_of_strings_in_file = file_to_string_count(current_input_data.in);
    
    current_input_data.array_of_sensors = malloc(current_input_data.number_of_strings_in_file * sizeof(struct sensor*));

    for(int i = 0; i < current_input_data.number_of_strings_in_file; i++)
    {
        current_input_data.array_of_sensors[i] = malloc(sizeof(struct sensor));
    }

    file_to_array_of_sensors(&current_input_data);

    if (current_input_data.month)
    {   printf("#\tYear\tMonth\tMonthAvg\tMonthMax\tMonthMin\n");
        printf("%d\t", 1);
        printf("%d\t", current_input_data.array_of_sensors[0]->year);
        printf("%d", current_input_data.month);
       // printf("%f", average_month_temperature(current_input_data.month, current_input_data.array_of_sensors[0]->year, current_input_data.array_of_sensors, current_input_data.processed_sensors_number));
       // printf("%d", maximum_month_temperature(current_input_data.month, current_input_data.array_of_sensors[0]->year, current_input_data.array_of_sensors, current_input_data.processed_sensors_number));
       // printf("%d", minimum_month_temperature(current_input_data.month, current_input_data.array_of_sensors[0]->year, current_input_data.array_of_sensors, current_input_data.processed_sensors_number));
       // printf("\n");
    }

    return 0;
}

