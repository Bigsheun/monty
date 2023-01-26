#include "monty.h"
#include "monty-global.h"

/**
* main - monty code interpreter
* @argc: number of arguments
* @argv: monty file location
* Return: 0 on success
*/
int main(int argc, char *argv[])
{
	char *content;
	stack_t *stack = NULL;
	unsigned int counter = 0;
	int result;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	content = file_load_all(argv[1]);

	content = s_getline(content);
	counter = 0;
	while (content != NULL)
	{
		bus.content = content;
		result = execute(content, &stack, counter);

		if (result != MNT_OK)
			break;

		content = s_getline(NULL);
		counter++;
	}

	print_error(counter, bus.opcode);
	free_all(stack, content);

	if (bus.err_code != MNT_OK)
	exit(EXIT_FAILURE);

	return (0);
}

/**
* file_Size - compute the size of a file
* @file_name: Name(path) of the file
*
* Return: the length of the file
*/

long int file_Size(char *file_name)
{
	/*opening the file in read mode*/
	FILE *fp;
	long int res;

	fp = fopen(file_name, "r");
	/*checking if the file exist or not*/
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", file_name);
		exit(EXIT_FAILURE);
	}

	/*calculating the size of the file*/
	fseek(fp, 0L, SEEK_END);
	res = ftell(fp);

	/*closing the file */
	fclose(fp);
	return (res);
}

/**
* file_load_all - loads an entire file
* @Filename: name of file to load
*
* Return: a string holding the content
*/
char *file_load_all(char *Filename)
{
	FILE *FP;
	int   N, Length;
	char *Buffer;

	Length = file_Size(Filename);
	Buffer = (char *) malloc(sizeof(char) * Length + 1);
	if (Buffer == NULL)
		fprintf(stderr, "Error: malloc failed\n");

	FP = fopen(Filename, "rb");
	N = fread(Buffer, sizeof(char), Length, FP);
	fclose(FP);

	Buffer[N] = '\0';
	return (Buffer);
}

/**
* free_all - untility function to free the guys
* @stack: This is the main stack
* @content: This one holds the data read from file
*/
void free_all(stack_t *stack, char *content)
{
	free_stack(stack);
	free(content);

}

/**
* s_getline - Gets a line from string
* @pLine: the string
*
* Return: Pointer to the line
*/
char *s_getline(char *pLine)
{
	static unsigned int index1, index2;
	static int flag;
	static char *Line;

	if (pLine != NULL)
	{
		Line = pLine;
		index1 = 0;
		flag = 0;
	}
	else
		index1 = index2 + 1;

	if (flag == -1)
		return (NULL);

	index2 = index1;
	while (Line[index2] != '\n' && Line[index2] != '\0')
		index2++;

	if (Line[index2] == '\0')
		flag = -1;

	Line[index2] = '\0';
	return (&Line[index1]);
}
