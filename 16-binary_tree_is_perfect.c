#include "binary_trees.h"

/**
 * binary_tree_height_p - Measures the height (node count) of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Height of the tree, or 0 if tree is NULL
 */
size_t binary_tree_height_p(const binary_tree_t *tree)
{
	size_t left_h = 0, right_h = 0;

	if (tree == NULL)
		return (0);

	left_h = binary_tree_height_p(tree->left);
	right_h = binary_tree_height_p(tree->right);

	return ((left_h > right_h ? left_h : right_h) + 1);
}

/**
 * binary_tree_size_p - Measures the size of a binary tree
 * @tree: Pointer to the root node of the tree to measure
 *
 * Return: Size of the tree, or 0 if tree is NULL
 */
size_t binary_tree_size_p(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + binary_tree_size_p(tree->left) +
		binary_tree_size_p(tree->right));
}

/**
 * binary_tree_is_perfect - Checks if a binary tree is perfect
 * @tree: Pointer to the root node of the tree to check
 *
 * Return: 1 if perfect, 0 otherwise (including if tree is NULL)
 */
int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t height = 0, size = 0;

	if (tree == NULL)
		return (0);

	height = binary_tree_height_p(tree);
	size = binary_tree_size_p(tree);

	return (size == (size_t)((1 << height) - 1));
}
