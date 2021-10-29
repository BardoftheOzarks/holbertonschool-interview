#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an avl tree
 * @array: a sorted array of ints
 * @size: elements in the array
 * Return: root node of avl tree
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *root = NULL;
	int left = 0, right = size - 1;

	root = make_tree(root, array, left, right);
	if (!root)
		return (NULL);
	return (root);
}

/**
 * make_tree - builds n avl tree recursively
 * @parent: root node for tree/branch
 * @array: sorted array of ints
 * @left: left index
 * @right: right index
 * Return: root node of entire tree
 */
avl_t *make_tree(avl_t *parent, int *array, int left, int right)
{
	avl_t *new;
	int placement = (right - left) / 2 + left;

	if (left > right)
		return (NULL);

	new = new_node(array[placement], parent);
	if (!new)
		return (NULL);

	new->left = make_tree(new, array, left, placement - 1);
	new->right = make_tree(new, array, placement + 1, right);

	return (new);
}

/**
 * new_node - makes a new node
 * @value: int value for node
 * @parent: parent node
 * Return: new node
 */
avl_t *new_node(int value, avl_t *parent)
{
	avl_t *new = malloc(sizeof(avl_t));

	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	return (new);
}
