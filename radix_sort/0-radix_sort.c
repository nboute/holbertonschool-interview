#include "sort.h"
#include <stdlib.h>
#include <stdio.h>
#include <stddef.h>

/**
 * get_max - gets the maximum value in an array
 * @array: array to be checked
 * @size: size of the array
 * Return: the maximum value in the array
 */
int get_max(int *array, size_t size)
{
	int max = array[0];
	size_t i;

	for (i = 1; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	return (max);
}

/**
 * countSort - sorts the array using the count sort algorithm
 * @array: array to be sorted
 * @n: size of the array
 * @exp: exponent

*/
void countSort(int *array, int n, int exp)
{
	int *output;
	int i;
	int count[10] = {0};

	output = malloc(n * sizeof(int));
	if (output == NULL)
		return;

	for (i = 0; i < n; i++)
		count[(array[i] / exp) % 10]++;

	for (i = 1; i < 10; i++)
		count[i] += count[i - 1];

	for (i = n - 1; i >= 0; i--)
	{
		output[count[(array[i] / exp) % 10] - 1] = array[i];
		count[(array[i] / exp) % 10]--;
	}

	for (i = 0; i < n; i++)
		array[i] = output[i];

	free(output);

}


/**
 * radix_sort - sorts an array of integers using the Radix sort algorithm
 * @array: array to be sorted
 * @size: size of the array
 */
void radix_sort(int *array, size_t size)
{
	int max;

	max = get_max(array, size);
	for (int exp = 1; max / exp > 0; exp *= 10)
	{
		countSort(array, size, exp);
		print_array(array, size);
	}
}
