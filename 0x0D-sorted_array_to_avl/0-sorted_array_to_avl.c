#include "binary_trees.h"

/**
 * sorted_array_to_avl - AVL binary tree
 *
 * @array: pointer to array
 * @size: size of array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	return (Tree_builder(NULL, array, 0, size - 1));
}

/**
 * Tree_builder - AVL binary tree
 *
 * @parentnode: pointer to root node
 * @array: pointer to array of items
 * @start: start of array
 * @end: number of items between start and end
 */
avl_t *Tree_builder(avl_t *parent, int *array, int start, int end)
{
	int mid;
	avl_t *new;

	if (start > end)
		return (NULL);

	mid = (start + end) / 2;

	new = malloc(sizeof(avl_t));
	if (!new)
		return (NULL);
	new->n = array[mid];
	new->parent = parent;
	new->left = Tree_builder(new, array, start, mid - 1);
	new->right = Tree_builder(new, array, mid + 1, end);

	return (new);
}
