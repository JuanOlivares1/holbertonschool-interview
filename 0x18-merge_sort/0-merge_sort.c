#include "sort.h"

/**
 * unmerch - docdoc
 * @array: array to unmerge
 * @size: size of array
 * @l: left pointer
 * @r: right pinter
 **/
void unmerch(int *array, int *l, int *r, size_t size)
{
	int i = 0, j = 0, k = 0;
	int left_s, right_s;

	left_s = size / 2;
	right_s = size - left_s;

	printf("Merging...\n");

	printf("[left]: ");
	print_array(l, left_s);

	printf("[right]: ");
	print_array(r, right_s);

	while (i < left_s && j < right_s)
	{
		if (l[i] < r[j])
			array[k++] = l[i++];
		else
			array[k++] = r[j++];
	}
	while (i < left_s)
		array[k++] = l[i++];

	while (j < right_s)
		array[k++] = r[j++];

	printf("[Done]: ");
	print_array(array, size);
}

/**
 * merge_sort - doc
 * @array: array to sort
 * @size: size of array
 **/
void merge_sort(int *array, size_t size)
{
	size_t mid = 0, i;
	int left[1000];
	int right[1000];

	if (!array)
		return;
	if (size < 2)
		return;

	mid = size / 2;
	for (i = 0; i < mid; i++)
		left[i] = array[i];
	for (i = mid; i < size; i++)
		right[i - mid] = array[i];
	merge_sort(left, mid);
	merge_sort(right, size - mid);
	unmerch(array, left, right, size);
}
