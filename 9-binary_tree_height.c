#include "binary_trees.h"

/**
 * binary_tree_height - measures the height of  binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: If tree is NULL function must return 0
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	if (tree)
	{
		size_t lef_t = 0, righ_t = 0;

		lef_t = tree->left ? 1 + binary_tree_height(tree->left) : 0;
		righ_t = tree->right ? 1 + binary_tree_height(tree->right) : 0;
		return ((lef_t > righ_t) ? lef_t : righ_t);
	}
	return (0);
}
