#include "binary_trees.h"

/**
 * binary_tree_balance - measures balance factor of binary tree
 * @tree: pointer
 * Return: the balance factor
 */
int binary_tree_balance(const binary_tree_t *tree)
{
	if (tree)
		return (binary_tree_height(tree->left) - binary_tree_height(tree->right));

	return (0);
}

/**
 * binary_tree_height - measures height of binary tree
 * @tree: pointer
 * Return: 0 if tree is null
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef_t = 0, righ_t = 0;

		lef_t = tree->left ? 1 + binary_tree_height(tree->left) : 1;
		righ_t = tree->right ? 1 + binary_tree_height(tree->right) : 1;
		return ((lef_t > righ_t) ? lef_t : righ_t);
	}
	return (0);
}
