#include "binary_trees.h"

/**
 * sorted_array_to_avl - AVL binary tree
 *
 * @array: pointer to array
 * @size: size of array
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	int len = size;
	int mid = (len - 1) / 2;
	avl_t *root, *temp, *extra;

	root = malloc(sizeof(avl_t));
	if (root == NULL)
		return (NULL);

	if (len == 1)
	{
		root->n = array[len];
		return (root);
	}

	root->n = array[mid];
	root->left = Tree_builder(root, array, mid);
	root->right = Tree_builder(root, &array[mid + 1], mid);

	if (len % 2 == 0)
	{
		temp = root;
		while (temp->right != NULL)
		{
			temp = temp->right;
		}
		extra = malloc(sizeof(avl_t));
		if (root == NULL)
			return (NULL);
		extra->n = array[len - 1];
		extra->parent = temp;
		temp->right = extra;
	}
	return (root);
}

/**
 * Tree_builder - AVL binary tree
 *
 * @root: pointer to root node
 * @array: pointer to array of items
 * @endidx: end inde of array
 */
avl_t *Tree_builder(avl_t *root, int *array, int endidx)
{
	int mid = endidx / 2;
	avl_t *new;

	new = malloc(sizeof(avl_t));
	if (new == NULL)
		return (NULL);

	if (endidx == 1)
	{
		if (array[0] == root->n)
			return (NULL);

		new->n = array[0];
		new->parent = root;
		new->left = NULL;
		new->right = NULL;
		return (new);
	}

	new->n = array[mid];
	new->parent = root;
	new->left = Tree_builder(new, array, mid);
	new->right = Tree_builder(new, &array[mid + 1], mid);

	return (new);
}
