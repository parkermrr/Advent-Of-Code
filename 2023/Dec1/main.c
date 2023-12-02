/* Problem 1 - December 1st */
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void findAndReplace(char* line, char* search, char* rep)
{
	char newLine[256];
	char* p = line;
	char* prev = line;
	newLine[0] ='\0';

	while((p = strstr(p, search)))
	{
		strncat(newLine, prev, p - prev);
		strcat(newLine, rep);
		p += strlen(search);
		prev = p;
	}

	strcat(newLine, prev);
	strcpy(line, newLine);
}

void preprocessLine(char* line)
{
	char * numbers[] = { "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};
	char * reps[] = { "1ne", "2wo", "3hree", "4our", "5ive", "6ix", "7even", "8ight", "9ine"};
	char buffer[256];
	char rev_buffer[256];
	char out_buffer[256];
	char* min;
	char* search;
	int found;
	int repIdx;
	strcpy(buffer, line);
	strcpy(rev_buffer, line);
	out_buffer[0] ='\0';

	do
	{
		found = 0;
		min = NULL;
		for(int i = 0; i < 9; i++)
		{
			search = strstr(line, numbers[i]);
			if(search != NULL)
			{
				found = 1;
				if(search < min || min == NULL)
				{
					min = search;
					repIdx = i;
				}
			}
		}

		if(found != 0)
		{
			findAndReplace(line, numbers[repIdx], reps[repIdx]);
		}

	} while(found);

}

int main(int argc, char **argv) 
{
	FILE* inputFile;
	char line[256];
	char num[3];
	int sum = 0;
	int seenFirst;
	int seenSecond;
	num[2] = '\0';

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: %s <input_file>\n", argv[0]);
		return -1;
	}
	else
	{
		 inputFile = fopen(argv[1], "r");
		 if (inputFile == NULL)
		 {
			fprintf(stderr, "File error. Input file invalid. Exiting...\n");
			return -1;
		 }
		 printf("Input file: %s\n", argv[1]);
	}

	while(fgets(line, sizeof(line), inputFile))
	{

		preprocessLine(line);

		seenFirst = 0;
		seenSecond = 0;;
		for(int i = 0; i < strlen(line); i++)
		{
			char c = line[i];
			if(isdigit(c))
			{
				if(!seenFirst)
				{
					seenFirst = 1;
					num[0] = c;
				}
				else
				{
					seenSecond = 1;
					num[1] = c;
				}
			}
		}

		if(!seenSecond)
		{
			num[1] = num[0];
		}

		sum += atoi(num);
	}

	printf("Final value: %d\n", sum);
	return 0;
}