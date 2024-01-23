#include "sort.h"
/**
 * _bigN -  Give me the largest number in an array of integers
 * @array: The Int array
 * @size: Size of array
 * Return: The largest number
 */
int _bigN(int *array, size_t size)
{
	int k = 0;

	while (size--)
	{
		if (k < array[size])
			k = array[size];
	}
	return (k);
}
/**
 * counting_sort - sort an array with the counting sort algorithm
 * @array: The Int array
 * @size: Size of array
 * Return: The sorted list
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int k = _bigN(array, size);
	int *aux = malloc((k + 1) * sizeof(int));
	int *array_sort = malloc(size * sizeof(int));

	if (!array || size < 2)
		return;
	if (!aux || !array_sort)
	{
		free(aux);
		free(array_sort);
		return;
	}
	for (i = 0; (int)i < k + 1; i++)
		aux[i] = 0;

	for (i = 0; i < size; i++)
		aux[array[i]]++;
	for (i = 1; (int)i < k + 1; i++)
		aux[i] += aux[i - 1];
	print_array(aux, k + 1);
	for (i = 0; i < size; i++)
	{
		array_sort[aux[array[i]] - 1] = array[i];
		aux[array[i]]--;
	}
	for (i = 0; i < size; i++)
		array[i] = array_sort[i];
	free(aux);
	free(array_sort);
}
