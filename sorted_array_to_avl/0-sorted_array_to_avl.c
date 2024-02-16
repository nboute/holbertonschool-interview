#include "binary_trees.h"
#include <stdlib.h>

/**
 * sorted_array_to_avl - Builds an AVL tree from an array
 * @array: Pointer to the first element of the array to be converted
 * @size: Number of elements in the array
 * Return: Pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t middle;

	if (!array || !size)
		return (NULL);
	tree = malloc(sizeof(avl_t));
	if (!tree)
		return (NULL);
	tree->parent = NULL;
	middle = size % 2 == 0 ? size / 2 - 1 : size / 2;
	tree->n = array[middle];
	tree->left = NULL;
	tree->right = NULL;
	if (size == 1)
		return (tree);
	tree->left = sorted_array_to_avl(array, middle);
	tree->right = sorted_array_to_avl(array + middle + 1, size / 2);

	if (tree->left)
		tree->left->parent = tree;
	if (tree->right)
		tree->right->parent = tree;

	return (tree);
}
