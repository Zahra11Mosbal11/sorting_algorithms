#include "sort.h"
/**
 * merge_sort - Sort an array of integers.
 * @array: An array of integers.
 * @size: The size of the array.
 * Return: void.
 */
void merge_sort(int *array, size_t size)
{
	int *buf = malloc(sizeof(int) * size);

	if (array == NULL || size < 2)
		return;

	if (buf == NULL)
		return;

	merge_action(array, buf, 0, size);

	free(buf);
}
/**
 * merge_action - Implement the merge sort algorithm through recursion.
 * @subarr: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted result.
 * @front: The front index of the subarray.
 * @back: The back index of the subarray.
 */
void merge_action(int *subarr, int *buf, size_t front, size_t back)
{
	size_t mid;

	if (back - front > 1)
	{
		mid = front + (back - front) / 2;
		merge_action(subarr, buf, front, mid);
		merge_action(subarr, buf, mid, back);
		merge_subarr(subarr, buf, front, mid, back);
	}
}
/**
 * merge_subarr - Sort a subarray of integers.
 * @subarr: A subarray of an array of integers to sort.
 * @buf: A buffer to store the sorted subarray.
 * @front: The front index of the array.
 * @mid: The middle index of the array.
 * @back: The back index of the array.
 */
void merge_subarr(int *subarr, int *buf, size_t front, size_t mid,
		size_t back)
{
	size_t i, j, k = 0;

	printf("Merging...\n[left]: ");
	print_array(subarr + front, mid - front);

	printf("[right]: ");
	print_array(subarr + mid, back - mid);

	for (i = front, j = mid; i < mid && j < back; k++)
		buf[k] = (subarr[i] < subarr[j]) ? subarr[i++] : subarr[j++];
	for (; i < mid; i++)
		buf[k++] = subarr[i];
	for (; j < back; j++)
		buf[k++] = subarr[j];
	for (i = front, k = 0; i < back; i++)
		subarr[i] = buf[k++];

	printf("[Done]: ");
	print_array(subarr + front, back - front);
}
