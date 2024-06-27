// Write only one logical function that determines whether
// it is true that among the elements of the array there are two identical ones.
// If the answer is yes, the function returns 1;
// if the answer is УnoФ, then 0. Strictly according to the prototype:
// int is_two_same(int size, int a[]);
// Input format:
// Array of integers
// (1 2 3 4 5 6 7)
// Output format:
// ‘ункци€ возвращает 1 или 0
// (NO)



#define SIZE 10

int is_two_same(int size, int a[]);
int find_max_array(int size, int a[]);

int is_two_same(int size, int a[])
{
	int temp_array_size = find_max_array(size, a);

	int* temp_arr = malloc(temp_array_size * sizeof(int));

	for (int i = 0; i < temp_array_size; i++)
	{
		temp_arr[i] = 0;
	}

	int event_flag = 0;

	for (int i = 0, current_number = 0; i < size; i++)
	{
		current_number = a[i];

		if (temp_arr[current_number] > 0)
		{
			event_flag = 1;
			break;
		}
		else
		{
			temp_arr[current_number]++;
		}
	}

	return event_flag;
}

int find_max_array(int size, int a[])
{
	int max = a[0];

	for (int i = 1; i < size; i++)
	{
		if (a[i] > max)
		{
			max = a[i];
		}
	}

	return max;
}
