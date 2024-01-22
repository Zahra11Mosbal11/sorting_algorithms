#include "sort.h"
/**
 * shell_sort - sorts an array of integers
 * @array: the array of integers
 * @size: the size of array
 * Return: void
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap;
	int temp;

	if (!array || size < 2)
		return;
	gap = 1;
	while (gap <= size / 3)
	{
		gap = gap * 3 + 1;
	}
	while (gap > 0)
	{
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			j = i;

			while (j >= gap && array[j - gap] > temp)
			{
				array[j] = array[j - gap];
				j = j - gap;
			}
			array[j] = temp;
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
