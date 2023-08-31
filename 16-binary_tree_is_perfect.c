#include "binary_trees.h"

unsigned char is_leaf(const binary_tree_t *node);
size_t n_depth(const binary_tree_t *tree);
const binary_tree_t *fecth_leaf(const binary_tree_t *tree);
int is_recursive(const binary_tree_t *tree, size_t l_depth,
		size_t lvl);
int binary_tree_is_perfect(const binary_tree_t *tree);

/**
 * is_leaf - Checks if node is leaf
 * @node: pointer
 * Return: 1 if leaf otherwise 0
 */
unsigned char is_leaf(const binary_tree_t *node)
{
	return ((node->left == NULL && node->right == NULL) ? 1 : 0);
}

/**
 * n_depth - returns the depth
 * @tree: pointer
 * Return: depth of node
 */
size_t n_depth(const binary_tree_t *tree)
{
	return (tree->parent != NULL ? 1 + n_depth(tree->parent) : 0);
}

/**
 * fetch_leaf - returns a leaf
 * @tree: pointer
 * Return: pointer to the first leaf
 */
const binary_tree_t *fetch_leaf(const binary_tree_t *tree)
{
	if (is_leaf(tree) == 1)
		return (tree);
	return (tree->left ? fetch_leaf(tree->left) : fetch_leaf(tree->right));
}

/**
 * is_perfect_recursive - checks for perfect recursive
 * @tree: pointer
 * @l_depth: depth of a leaf
 * @lvl: the level of node
 * Return: 1 otherwise 0 if tree is not perfect
 */
int is_recursive(const binary_tree_t *tree, size_t l_depth,
		size_t lvl)
{
	if (is_leaf(tree))
		return (lvl == l_depth ? 1 : 0);
	if (tree->left == NULL || tree->right == NULL)
		return (0);
	return (is_recursive(tree->left, l_depth, lvl + 1) &&
		is_recursive(tree->right, l_depth, lvl + 1));
}

/**
 * binary_tree_is_perfect - will check if tree is perfect
 * @tree: pointer
 * Return: if tree not perfect 0
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	return (is_recursive(tree, n_depth(fetch_leaf(tree)), 0));
}
