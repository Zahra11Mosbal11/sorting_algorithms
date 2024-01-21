#include "sort.h"
/**
 * quick_sort - sorts an array of integers.
 * @array: The array of integers to sort
 * @size: The size of the array of integers
 * Return: void
 */
void quick_sort(int *array, size_t size)
{
	int start = 0, end = size - 1;

	if (!array || size < 2)
		return;
	quick_sort_lim(array, start, end, size);
}
/**
 * quick_sort_lim - sorts an array of integers.
 * @array: The array of integers to sort
 * @start: the start of array
 * @end: the end of array
 * @size: The size of the array of integers
 * Return: void.
 */
void quick_sort_lim(int *array, int start, int end, size_t size)
{
	int partIndex;

	if (start < end)
	{
		partIndex = partition(array, start, end, size);
		quick_sort_lim(array, start, partIndex - 1, size);
		quick_sort_lim(array, partIndex + 1, end, size);
	}
}
/**
 * partition - to sprit the array
 * @array: The array of integers to sort
 * @start: the start of array
 * @end: the end of array
 * @size: The size of the array of integers
 * Return: the index
 */
int partition(int *array, int start, int end, size_t size)
{
	int i, temp, pivot = array[end];
	int partIndex = start;

	for (i = start; i < end; i++)
	{
		if (array[i] <= pivot)
		{
			if (i != partIndex)
			{
				temp = array[i];
				array[i] = array[partIndex];
				array[partIndex] = temp;

				print_array(array, size);
			}
			partIndex++;
		}
	}
	if (end != partIndex)
	{
		temp = array[partIndex];
		array[partIndex] = array[end];
		array[end] = temp;

		print_array(array, size);
	}
	return (partIndex);
}
