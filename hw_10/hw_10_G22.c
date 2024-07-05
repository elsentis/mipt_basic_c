// The well-known Soundex algorithm 
// determines whether two English words sound similar.
// It takes a word as input and replaces it with some four-character code.
// If the codes of two words match, then the words tend to sound similar.
// You need to implement this algorithm.It works like this:
// The first letter of the word is retained.
// In the rest of the word :
// letters denoting, as a rule, vowel sounds :
// a, e, h, i, o, u, w and y - are discarded;
// the remaining letters(consonants) are replaced with numbers from 1 to 6,
// and similar - sounding letters correspond to the same numbers :
// 1 : b, f, p, v
// 2 : c, g, j, k, q, s, x, z
// 3 : d, t
// 4 : l
// 5 : m, n
// 6 : r
// Any sequence of identical digits is reduced to one such digit.
// The resulting string is truncated to the first four characters.
// If the string length is less than required,
// the missing characters are replaced with a 0.
// Examples :
// àmmonium -> ammnm -> a5555 -> a5 -> a500
// implementation -> implmnttn -> i51455335 -> i514535 -> i514
// 
// Input format
// The input file input.txt contains one non-empty word, written in lowercase Latin letters.
// The word length does not exceed 20 characters.
// ammonium
// 
// Output format
// Type the four-letter code corresponding to the word into the output.txt file.
// a500


#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>

void soundex_code_from_file(FILE* in, FILE* out);

int main(void)
{
	FILE* in, * out;

	if ((in = fopen("input.txt", "r")) == NULL)
	{
		printf("Can't open file %s\n", "input.txt");
		exit(EXIT_FAILURE);
	}

	if ((out = fopen("output.txt", "w")) == NULL)
	{
		printf("Can't open file %s\n", "output.txt");
		exit(EXIT_FAILURE);
	}

	soundex_code_from_file(in, out);

	fclose(in);
	fclose(out);

	return 0;
}

void soundex_code_from_file(FILE* in, FILE* out)
{
	char ch = 0, prev = 0;
	int ch_code = 0, prev_code = 0;	
	int i = 0;

	for (; ((ch = getc(in)) != 'EOF') && (ch != 'ÿ') && (ch != '\n') && (i < 4);)
	{
	

		switch (ch)
		{
		case('b'):
		case('f'):
		case('p'):
		case('v'):
			ch_code = 1;
			break;
		case('c'):
		case('g'):
		case('j'):
		case('k'):
		case('q'):
		case('s'):
		case('x'):
		case('z'):
			ch_code = 2;
			break;
		case('d'):
		case('t'):
			ch_code = 3;
			break;
		case('l'):
			ch_code = 4;
			break;
		case('m'):
		case('n'):
			ch_code = 5;
			break;
		case('r'):
			ch_code = 6;
			break;
		default:
			if (i == 0)
			{
				putc(ch, out);
				prev_code = ch_code;
				i++;
			}
			continue;
			break;
		}

		if (i == 0)
		{
			putc(ch, out);
			prev_code = ch_code;
			i++;
		}
		else if ((ch_code == prev_code) && (i > 1))
		{
			continue;
		}
		else
		{
			putc(ch_code + '0', out);
			prev_code = ch_code;
			i++;
		}
	}

	for (; i < 4; i++)
	{
		putc('0', out);
	}
	
}
