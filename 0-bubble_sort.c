#include "sort.h"

/**
  * bubble_sort - Sorts an array of integers in ascending
  * order using the Bubble sort algorithm.
  * @array: The array of integers to sort
  * @size: The size of the array of integers
  *
  * Return: Nothing!
  */
void bubble_sort(int *array, size_t size)
{
	int i, n, temp, swap;

	if (!array || size < 2)
		return;
	n = size - 1;
	do {
		swap = 0;
		for (i = 0; i < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				temp = array[i];
				array[i] = array[i + 1];
				array[i + 1] = temp;
				print_array(array, size);
				swap = 1;
			}
		}
		n--;
	} while (swap);
}
