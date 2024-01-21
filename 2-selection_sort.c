#include "sort.h"
/**
 * selection_sort - sorts an array of integers
 * @array: the arry of intieger.
 * @size: the size of array.
 * Return: void.
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, iMin;
	int temp;

	if (!array || size < 2)
		return;
	for (i = 0; i < size - 1; i++)
	{
		iMin = i;
		for (j = i + 1; j < size; j++)
		{
			if (array[j] < array[iMin])
				iMin = j;
		}
		if (iMin != i)
		{
			temp = array[i];
			array[i] = array[iMin];
			array[iMin] = temp;
			print_array(array, size);
		}
	}
}
