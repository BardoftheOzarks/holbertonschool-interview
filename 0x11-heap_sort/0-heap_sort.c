#include "sort.h"

/**
 * heap_sort - Sorts an array by sift-down heap sort
 * @array: array of ints to be sorted
 * @size: size of array
 */
void heap_sort(int *array, size_t size)
{
	int i;

	for (i = (size - 2) / 2; i >= 0; i--)
		heapify(array, size, i, size);
	for (i = size - 1; i >= 0; i--)
	{
		swap(&array[0], &array[i]);
		if (i > 0)
			print_array(array, size);
		heapify(array, i, 0, size);
	}
}

/**
 * heapify - puts an array in heab order
 * @array: array to heap
 * @n: int size
 * @i: subarray size
 * @size: size of array
 */
void heapify(int *array, int n, int i, size_t size)
{
	int max = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;

	if (left < n && array[left] > array[max])
		max = left;
	if (right < n && array[right] > array[max])
		max = right;
	if (max != i)
	{
		swap(&array[i], &array[max]);
		print_array(array, size);
		heapify(array, n, max, size);
	}
}

/**
 * swap - swaps two ints
 * @a: first int
 * @b: second int
 */
void swap(int *a, int *b)
{
	int c = *a;

	*a = *b;
	*b = c;
}
