#include "slide_line.h"

/**
 * slide_line_end - slides an array of integers
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to slide
 * Return: 1
*/
int slide_line_end(int *line, size_t size, int direction)
{
	size_t i, index;

	if (direction == SLIDE_LEFT)
	{
		for (index = 0; index < size; index++)
			if (line[index] == 0)
				break;
		for (i = index; i < size; i++)
		{
			if (line[i] != 0 && index != i)
			{
				line[index] = line[i];
				line[i] = 0;
				index++;
			}
		}
	}
	else
	{
		for (index = size - 1; index != 0; index--)
			if (line[index] == 0)
				break;
		for (i = index; index != 0; i--)
		{
			if (line[i] != 0 && index != i)
			{
				line[index] = line[i];
				line[i] = 0;
				index--;
			}
			if (i == 0)
				break;
		}
	}
	return (1);
}

/**
 * slide_line - slides and merges an array of integers
 * @line: points to an array of integers containing size elements
 * @size: size of the array
 * @direction: direction to slide
 * Return: 1 upon success, or 0 upon failure
*/
int slide_line(int *line, size_t size, int direction)
{
	size_t i, index, end;

	index = 0;
	if (direction != SLIDE_LEFT && direction != SLIDE_RIGHT)
		return (0);
	for (i = 0; i < size; i++)
	{
		if (line[i] != 0)
		{
			if (index != i)
			{
				line[index] = line[i];
				line[i] = 0;
			}
			index++;
		}
	}
	index = direction == SLIDE_LEFT ? 0 : size - 1;
	end = direction == SLIDE_LEFT ? size - 1 : 0;
	for (i = index; i != end; i += direction)
	{
		if (direction == SLIDE_LEFT)
		{
			if (line[i] == line[i + 1])
			{
				line[i] *= 2;
				line[i + 1] = 0;
			}
		}
		else
		{
			if (line[i] == line[i - 1])
			{
				line[i] *= 2;
				line[i - 1] = 0;
			}
		}
	}

	return (slide_line_end(line, size, direction));
}
