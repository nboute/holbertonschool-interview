#include "binary_trees.h"

/**
 * swap_nodes - Swaps two nodes
 *
 * @node1: Pointer to the first node
 * @node2: Pointer to the second node
 */
void swap_nodes(heap_t *node1, heap_t *node2)
{
	int temp;

	temp = node1->n;
	node1->n = node2->n;
	node2->n = temp;
}

/**
 * max_heapify - Heapifies max binary heap
 *
 * @root: Pointer to the root node
 */
void max_heapify(heap_t *root)
{
	heap_t *largest = root;
	heap_t *left = root->left;
	heap_t *right = root->right;

	if (left && left->n > largest->n)
		largest = left;
	if (right && right->n > largest->n)
		largest = right;
	if (largest != root)
	{
		swap_nodes(root, largest);
		max_heapify(largest);
	}
}

/**
 * count_nodes - Counts the number of nodes in a binary tree
 *
 * @root: Pointer to the root node
 *
 * Return: Number of nodes
 */
int count_nodes(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + count_nodes(root->left) + count_nodes(root->right));
}

/**
 * get_node_at_index - Gets the node at a given index
 *
 * @root: Pointer to the root node
 * @index: Index of the node to get
 * @curr_index: Current index
 *
 * Return: Pointer to the node at index @index or NULL if it doesn't exist
 */
heap_t * get_node_at_index(heap_t *root, int index, int curr_index)
{
	heap_t *left, *right;

	if (!root)
		return (NULL);
	if (curr_index == index)
		return (root);
	left = get_node_at_index(root->left, index, curr_index * 2 + 1);
	right = get_node_at_index(root->right, index, curr_index * 2 + 2);
	if (left)
		return (left);
	return (right);
}

/**
 * heap_extract - Extracts the root node of a Max Binary Heap
 *
 * @root: Double pointer to the root node
 *
 * Return: Value stored in the root node
 */
int heap_extract(heap_t **root)
{
	int value, nodes;
	heap_t *last_node, *parent;

	if (!root || !*root)
		return (0);
	if (!(*root)->left && !(*root)->right)
	{
		value = (*root)->n;
		free(*root);
		*root = NULL;
		return (value);
	}
	nodes = count_nodes(*root);
	last_node = get_node_at_index(*root, nodes - 1, 0);
	(*root)->n = last_node->n;
	parent = last_node->parent;
	if (parent->right == last_node)
		parent->right = NULL;
	else
		parent->left = NULL;
	free(last_node);
	max_heapify(*root);
	return ((*root)->n);
}
