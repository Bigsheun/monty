#include "monty.h"
/**
* found_in - checks if c is found in s
* @c: character c
* @s: String s
*
* Return: true if found else false
*/
short found_in(char c, char *s)
{
	short True = (1 == 1), False = (1 == 0);
	int i;

	i = 0;
	while (c != s[i] && s[i] != '\0')
		i++;
	if (s[i] == '\0')
		return (False);
	else
		return (True);

}
/**
* wordstart - find the begining of a word(non-delimiter)
* @str: string
* @delims: delimeters
* @index: starting index
*
* Return: index of start
*/
int wordstart(char *str, char *delims, int index)
{
	int i;

	i = index;
	while (str[i] != '\0' && found_in(str[i], delims))
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}
/**
* delimstart - find end of words(begin of delimeters)
* @str: string
* @delims: delimeters
* @index: starting index
*
* Return: index of start
*/
int delimstart(char *str, char *delims, int index)
{
	int i;

	i = index;
	while (str[i] != '\0' && !found_in(str[i], delims))
		i++;
	if (str[i] == '\0')
		return (-1);
	return (i);
}
/**
* wordcount - count number of words in string
* @str: string
* @delims: word separators
*
* Return: number
*/
int wordcount(char *str, char *delims)
{
	int i = 0, count = 0;

	while (i != -1)
	{
		i = wordstart(str, delims, i);
		if (i != -1)
			count++;
		if (i != -1)
			i = delimstart(str, delims, i);
	}

	return (count);
}

/**
* split_arg - splits string into NULL terminated array of words
* @arg: string
* @delims: delimeters
*
* Return: said array
*/
char **split_arg(char *arg, char *delims)
{
	char **words;
	int count = 0, index = 0, i, j = 0;

	count = wordcount(arg, delims);

	words = malloc(sizeof(char *) * (count + 1));
	if (words == NULL)
		return (NULL);

	for (i = 0; i < count && index != -1; i++)
	{
		index = wordstart(arg, delims, index);
		if (index != -1)
			words[j++] = &arg[index];
		if (index != -1)
		{
			index = delimstart(arg, delims, index);
			if (index != -1)
			{
				arg[index] = '\0';
				index += 1;
			}
		}
	} /*end-for*/
	words[j] = NULL;
	return (words);
}
