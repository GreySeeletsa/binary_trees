#include "binary_trees.h"

/**
 * binary_tree_nodes - counts nodes with at least 1 child in binary tree
 * @tree: pointer to root node of the tree to count num of nodes
 * Return: node count
 */
size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t _nodes = 0;

	if (tree)
	{
		_nodes += (tree->left || tree->right) ? 1 : 0;
		_nodes += binary_tree_nodes(tree->left);
		_nodes += binary_tree_nodes(tree->right);
	}
	return (_nodes);
}
