#include "binary_trees.h"

/**
 * heap_insert - inserts a node into a Max Binary Heap
 * @root: root of the binary heap
 * @value: value to be inserted
 * Return: a pointer to the inserted node
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new;

	if (!*root)
	{
		*root = binary_tree_node(*root, value);
		return (*root);
	}
	/*traverse by level for next available slot*/
	new = traverse(*root, value);
	/*loop: compare with parent, swap as needed*/
	if (new->parent && new->parent->n < new->n)
		swap_parent(new);
	/*check and adjust if new root node*/
	if ((*root)->parent)
		while ((*root)->parent)
			*root = (*root)->parent;
	return (new);
}

/**
 * nodes - Measures the number of nodes recursively
 * @tree: Pointer to the root node
 * Return: the amount of nodes on the tree
 */
int nodes(heap_t *tree)
{
	if (!tree)
		return (0);
	return (nodes(tree->left) + nodes(tree->right) + 1);
}

/**
 * height - measures the length of the tree in nodes
 * @tree: tree or branch to be measured
 * Return: length of tree
 */
int height(heap_t *tree)
{
	int lheight, rheight;

	if (!tree)
		return (0);
	lheight = height(tree->left);
	rheight = height(tree->right);
	if (lheight > rheight)
		return (lheight + 1);
	return (rheight + 1);
}

/**
 * swap_parent - replaces a new node with the parent node
 * @promotee: child node to swap with parent
 */
void swap_parent(heap_t *promotee)
{
	int hold;
	heap_t *demotee;

	if (!promotee || !promotee->parent)
		return;
	while (promotee->parent && promotee->parent->n < promotee->n)
	{
		demotee = promotee->parent;
		hold = demotee->n;
		demotee->n = promotee->n;
		promotee->n = hold;
	}
}

/**
 * traverse - searches a heap by level order traversal for next available node
 * @root: root of the binary tree to be traversed
 * @value: value to be inserted
 * Return: new node
 */
heap_t *traverse(heap_t *root, int value)
{
	int lcount, rcount, lheight, rheight;

	/*end placements for new nodes*/
	if (!root)
	{	root = binary_tree_node(NULL, value);
		if (!root)
			return (NULL);
		return (root);
	}
	if (!root->left)
	{	root->left = binary_tree_node(root, value);
		if (!root->left)
			return (NULL);
		return (root->left);
	}
	if (!root->right)
	{	root->right = binary_tree_node(root, value);
		if (!root->right)
			return (NULL);
		return (root->right);
	}
	/*traversal navigation for full nodes*/
	if (root->left && root->right)
	{	lcount = nodes(root->left);
		lheight = height(root->left);
		rcount = nodes(root->right);
		rheight = height(root->right);
		if (lcount == rcount && lheight == rheight)
			return (traverse(root->left, value));
		if (lheight > rheight && lcount > rcount * 2)
			return (traverse(root->right, value));
		if (lheight > rheight && lcount < rcount * 2)
			return (traverse(root->left, value));
		if (lheight == rheight && lcount > rcount)
			return (traverse(root->right, value));
	}
	return (traverse(root->left, value));
}
