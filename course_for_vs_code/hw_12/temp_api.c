#include "temp_api.h"



uint32_t file_to_string_count(FILE *f)
{
    fseek(f, 0, SEEK_SET);
    uint32_t count = 0;
    for(char str_temp[STRING_LENGTH]; fgets(str_temp, STRING_LENGTH,f) != NULL;count++)

    fseek(f, 0, SEEK_SET);

    return ++count;
}

float monthly_average_temperature(struct sensor ** arr,
                                 int month_number, int array_size)
{
    float temperature_summ = 0;
    float day_count = 0;

    for(int i = 0; i < array_size;i++)
    {
        if((*(*(arr+i))).month != month_number)
        {
            continue;
        }

        temperature_summ += (*(*(arr+i))).temperature;
        day_count++;
    }

    return temperature_summ/day_count;
}