#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 *
 * Return: the balance factor
 *         0 if tree is NULL
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	int height_l, height_r;

	if (!tree)
                return (0);

	if (!binary_tree_is_bst(tree))
		return (0);

	height_l = tree->left ? 1 + binary_tree_is_avl(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_is_avl(tree->right) : 0;

	if (abs(height_l - height_r) > 1)
		return (0);
	else
		return (1);
}

/**
 * binary_tree_is_bst - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - checks if a binary tree is a valid Binary Search Tree
 * @tree: a pointer to the root node of the tree to check
 * @min: Lower bound of checked nored
 * @max: Upper bound of checked nodes
 *
 * Return: 1 if tree is a valid BST
 *         0 otherwise
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
	/* -1 and +1 stem from "There must be no duplicate values" req */
}
