#include "temp_api.h"

#define SIZE 5 //(60*24*365)
#define MONTH_PER_YEAR 12

int main(void)
{
FILE *in;

    if ((in = fopen("temperature_big.csv", "r")) == NULL)
	{
		printf("Can't open file %s\n", "temperature_big");
		exit(EXIT_FAILURE);
	}

    struct sensor * array = malloc(SIZE * sizeof(struct sensor));
    struct sensor ** arr = &array;

    arr[0]->year = 2001;
    arr[0]->month = 2;
    arr[0]->day = 21;
    arr[0]->hour = 23;
    arr[0]->minute = 23;
    arr[0]->temperature = 12;

    arr[1]->year = 2001;
    arr[1]->month = 2;
    arr[1]->day = 22;
    arr[1]->hour = 12;
    arr[1]->minute = 24;
    arr[1]->temperature = 2;


    float temp = monthly_average_temperature(arr, 2, SIZE);
    printf("%f\n", temp);

    //fclose(in);

    return 0;
}

