#include "search_algos.h"


/**
 * advanced_binary - search for the first element of a value in a sorted array
 * @array: an array of ints
 * @size: number of elements in array
 * @value: value to search for
 * Return: index of found value, -1 on failure
 */
int advanced_binary(int *array, size_t size, int value)
{
	int left = 0, right, result = -1;

	if (size)
	{
		right = size - 1;
		result = binary_search(array, size, left, right, value);
	}
		return (result);
}

/**
 * backtrack - finds the first occurance of a value
 * @array: a sorted array of ints
 * @index: index of a match
 * @value: value to search for
 * Return: index of first occurance
 */
int backtrack(int *array, int index, int value)
{
	if (array[index - 1] == value)
		return (backtrack(array, index - 1, value));
	return (index);
}

/**
 * binary_search - searches for a value in a sorted array
 * @array: a sorted array of ints
 * @size: number of elements
 * @left: left edge of subarray
 * @right: right index of subarray
 * @value: value to search for
 * Return: index of found value
 */
int binary_search(int *array, size_t size, int left, int right, int value)
{
	int mid;

	print_array(array, left, right);
	if (array[left] && array[right] && right > left)
	{
		mid = left + (right - left) / 2;
		if (array[mid] == value)
		{
			if (array[mid - 1] == value)
				return (binary_search(array, size, left,
						      mid, value));
			return (mid);
		}
		if (array[mid] > value)
			return (binary_search(array, size, left,
					      mid, value));
		if (array[mid] < value)
			return (binary_search(array, size, mid + 1,
					      right, value));
	}
	return (-1);
}

/**
 * print_array - prints an array of ints
 * @array: an array of ints
 * @left: leftmost index to print
 * @right: rightmost index to print
 */
void print_array(int *array, int left, int right)
{
	printf("Searching in array: ");
	while (left < right)
	{
		printf("%d, ", array[left]);
		left++;
	}
	printf("%d\n", array[right]);
}
