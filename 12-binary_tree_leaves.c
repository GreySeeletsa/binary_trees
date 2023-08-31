#include "binary_trees.h"

/**
 * binary_tree_leaves - counts the leaves in binary tree
 * @tree: pointer to root node of the tree to count num
 * Return: If tree is NULL funct must return 0
 */
size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t _leaves = 0;

	if (tree)
	{
		_leaves += (!tree->left && !tree->right) ? 1 : 0;
		_leaves += binary_tree_leaves(tree->left);
		_leaves += binary_tree_leaves(tree->right);
	}
	return (_leaves);
}
