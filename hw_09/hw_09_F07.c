// Write a function that compresses the series
// of an array consisting of ones and zeros according to the following principle:
// for example, the array [0,0,0,0,1,1,1,1,1,1,1,0,0,1,1 ,1,1]
// is converted to [4,7,2,4]
// (since it starts from zero, the number of elements
// of the first series is immediately recorded);
// and the array [1,1,1,0,0,0,0,0,0,0] is converted to [0,3,7]
// (since the first series is ones, then the first element of the converted array is 0) .
// Only one function needs to be implemented;
// there is no need to download the entire program.
// Function prototype :
// int compression(int a[], int b[], int N)
// Input format:
// The function takes the original array a[]
// and compresses it into an array b[],
// N is the number of elements in the array a[].
// (0,0,0,0,1,1,1,1,1,1,1,0,0,1,1,1,1)
// Output format:
// function returns the number of elements of the compressed array b[]
// ([4,7,2,4])

#include <stdio.h>

#define SIZE 1000

void printArray(int n, int arr[]);
int compression(int a[], int b[], int N);

/*int main(void)
{
	int arr[] = {0, 0, 0, 0, 1, 1, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1};

	int b[SIZE] = {0};

	int b_size = compression(arr, b, sizeof(arr) / sizeof(int));

	printArray(b_size, b);
}*/



int compression(int a[], int b[], int N)
{
	
	int prev = a[0];
	int j = 0;
	if (prev == 1)
	{
		b[0] = 0;
		j++;
	}

	for (int i = 1, count_same = 1; i < N; i++)
	{
		if (prev == a[i])
		{
			if (i == N - 1)
			{
				prev = a[i];
				b[j] = count_same + 1;
				j++;
				break;
			}
			else
			{
				count_same++;
			}
		}
		else
		{
			if (i == N - 1)
			{
				b[j] = count_same;
				j++;
				count_same = 1;
				b[j] = count_same;
				j++;
			}
			else
			{
				prev = a[i];
				b[j] = count_same;
				j++;
				count_same = 1;
			}
			
		}
	}

	return j;
}

void printArray(int n, int arr[])
{
	int i = 0;

	for (i = 0; i < n; i++)
	{
		printf("%d ", arr[i]);
	}

	printf("\n");

	return 0;
}