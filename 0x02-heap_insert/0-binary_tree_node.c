#include "binary_trees.h"

/**
 * binary_tree_node - creates a node for a binary tree
 * @parent: pointer to parent node
 * @value: integer value for node
 * Return: pointer to new node
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new = malloc(sizeof(binary_tree_t));

	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
