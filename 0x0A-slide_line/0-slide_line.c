#include "slide_line.h"

/**
 * slide_line - slides ints in an array, combining matches
 * @line: an array of integers
 * @size: length of array
 * @direction: a value determining direction
 * Return: 1 for success, 0 for failure
 */
int slide_line(int *line, size_t size, int direction)
{
	size_t index, i, lock;

	if (direction == SLIDE_LEFT)
	{	lock = 0;
		for (index = 1; index < size; index++)
		{
			if (line[index] > 0)
			{	i = index;
				while (line[i - 1] == 0 && i > 0)
				{	line[i - 1] = line[i];
					line[i] = 0;
					i--;
				}
				if (line[i] == line[i - 1] && lock < i)
				{	line[i - 1] *= 2;
					line[i] = 0;
					lock++;	}}}
		return (1); }
	else if (direction == SLIDE_RIGHT)
	{	lock = size - 1;
		for (index = size - 1; index + 1; index--)
		{
			if (line[index] > 0)
			{	i = index;
				while (i < size - 1 && line[i + 1] == 0)
				{	line[i + 1] = line[i];
					line[i] = 0;
					i++;
				}
				if (line[i] == line[i + 1] && lock > i)
				{	line[i + 1] *= 2;
					line[i] = 0;
					lock--;	}}}
		return (1); }
	return (0);
}
