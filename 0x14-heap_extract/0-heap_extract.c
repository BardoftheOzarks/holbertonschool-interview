#include "binary_trees.h"

/**
 * heap_extract - extracts the root node of a Max Binary Heap
 * @root: root node of the heap
 * Return: value of root node, 0 if failed
 */
int heap_extract(heap_t **root)
{
	heap_t *delete, *parent;
	int num;

	if (root == NULL || *root == NULL)
		return (0);

	delete = *root;
	num = (*root)->n;

	if (!delete->left && !delete->right)
	{
		*root = NULL;
		free(delete);
		return (num);
	}
	if (delete->left && delete->right)
	{
		if (delete->left->n > delete->right->n)
			delete = swap(delete, delete->left);
		else
			delete = swap(delete, delete->right);
		while ((*root)->parent)
			*root = (*root)->parent;
		return (heap_extract(&delete));
	}
	else if (delete->left)
		delete = swap(delete, delete->left);
	while ((*root)->parent)
		*root = (*root)->parent;
	delete = swap(delete, last_leaf(*root));
	num = delete->n;
	parent = delete->parent;
	if (parent->left == delete)
		parent->left = NULL;
	if (parent->right == delete)
		parent->right = NULL;
	free(delete);
	return (num);
}

/**
 * last_leaf - finds the last leaf of the tree
 * @root: root of the tree
 * Return: last leaf in tree
 */
heap_t *last_leaf(heap_t *root)
{
	if (root->left && root->right)
	{
		if (height(root->left) > height(root->right))
			return (last_leaf(root->left));
		return (last_leaf(root->right));
	}
	if (root->left)
		return (last_leaf(root->left));
	return (root);
}

/**
 * height - gets the height of a binary tree
 * @root: root of the tree
 * Return: height of the tree as int
 */
int height(heap_t *root)
{
	if (!root)
		return (0);
	return (1 + height(root->left));
}

/**
 * swap - swaps two heap nodes
 * @a: first node
 * @b: second node
 * Return: the demoted node
 */
heap_t *swap(heap_t *a, heap_t *b)
{
	int c;

	if (!a || !b)
		return (NULL);
	c = a->n;
	a->n = b->n;
	b->n = c;

	return (b);
}
