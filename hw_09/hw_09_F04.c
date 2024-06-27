// Write only one function.
// There is no need to send the entire program.
// Print the numbers in the string in ascending order.
// The number is the quantity. The function must strictly correspond to the prototype:
// Input format:
// A string of English letters, spaces, punctuation marks and numbers
// (Hello123 world77.)
// Output format:
// The function must take a string as input and print it in the format: Digit space quantity.
// (1 1
//  2 1
//  3 1
//  7 2)



#define SIZE 10

void  print_digit(char s[]);

void print_digit(char s[])
{
	int arr[SIZE] = { 0 };
	int i = 0;

	for (char ch = s[i]; ch != '\0' ; ch = s[i])
	{
		if (ch >= '0' && ch <= '9')
		{
			arr[ch - '0']++;
		}

		i++;
		
	}

	for (int i = 0; i < SIZE; i++)
	{
		if (arr[i] == 0)
		{
			continue;
		}
		else
		{
			printf("%d %d\n", i, arr[i]);
		}
	}
}


