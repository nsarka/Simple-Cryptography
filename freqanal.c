/*
 * Created for Khan Academy cryptography challenge
 *
 * Usage: freqanal <filename> - Prints number of occurances of every letter in a text
 * June 3, 2016
*/

#include <stdio.h>
#include <stdlib.h>

int letters[25] = { 0 };

int main(int argc, char *argv[])
{
	if(argc != 2)
	{
		printf("Usage: %s <filename>\n - Prints number of occurances of every letter\n", argv[0]);
		return 0;
	}

	FILE *file = fopen(argv[1], "r");

	if(file == 0)
	{
		printf("Could not open file\n");
	}
	else
	{
		int index;

		while((index = fgetc(file)) != EOF)
		{
			//Space or new line, respectively
			if(index == 32 || index == 10)
			{
				printf("%c", index);
				continue;
			}

			if(index >= 97 && index <= 122)
			{
				letters[index - 97]++;
			}
			else if(index >= 65 && index <= 90)
			{
				letters[index - 65]++;
			}
		}

		fclose(file);
	}

	for(int i = 0; i < 26; i++)
	{
		printf("%c: %d\n", i + 97, letters[i]);
	}

	return 0;
}


