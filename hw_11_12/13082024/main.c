#include "temp_function.h"


int main(int argc, char **argv)
{
    int month = 0;

    FILE* in;

    parsing_cmd (argc, argv, in, &month);

    int processed_sensors_number = 0;
    struct sensor** array_of_pointers = 0;

    processed_sensors_number = file_to_array_of_sensors(in, array_of_pointers);

    return 0;
}

