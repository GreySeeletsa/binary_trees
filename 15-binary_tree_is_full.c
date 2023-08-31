#include "binary_trees.h"

/**
 * is_recursive - checks if a binary tree is full
 * @tree: pointer
 * Return: If tree is null(0) otherwise 1
 */
int is_recursive(const binary_tree_t *tree)
{
	if (tree != NULL)
	{
		if ((tree->left != NULL && tree->right == NULL) ||
		    (tree->left == NULL && tree->right != NULL) ||
		    is_recursive(tree->left) == 0 ||
		    is_recursive(tree->right) == 0)
			return (0);
	}
	return (1);
}

/**
 * binary_tree_is_full - checks if a binary tree is full
 * @tree: pointer
 * Return: 0 if null
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_recursive(tree));
}
