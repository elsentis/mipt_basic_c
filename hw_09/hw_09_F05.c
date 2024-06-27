// Write only one function that finds the maximum element in the array.
// There is no need to download the entire program.
// Function prototype
// int find_max_array(int size, int a[])
// Input format:
// An array consisting of integers.
// The first argument is the size of the array,
// the second argument is the address of the zero element.
// (983 749 909 601 270 147 433 737)
// Output format:
// The function must take a string as input and print it in the format: Digit space quantity.
// (983)



#define SIZE 10

int find_max_array(int size, int a[]);

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
