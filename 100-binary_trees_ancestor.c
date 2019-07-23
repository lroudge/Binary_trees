#include "binary_trees.h"

/**
 * binary_trees_ancestor - finds the lowest common ancestor of two nodes
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	binary_tree_t *root;

	if (!first || !second)
		return (NULL);

	root = (binary_tree_t *)first;
	while (root->parent)
		root = root->parent;

	return (bta_helper(root, first, second));
}

/**
 * bta_helper - finds the lowest common ancestor of two nodes
 * @root: a pointer to the root node of the binary tree
 * @first: a pointer to the first node to find the ancestor
 * @second: a pointer to the second node to find the ancestor
 *
 * Return: pointer to the ancestor node
 *         NULL if there is no ancestor node
 */
binary_tree_t *bta_helper(binary_tree_t *root, const binary_tree_t *first,
			  const binary_tree_t *second)
{
	binary_tree_t *lca_l, *lca_r;

	if (root == NULL)
		return (NULL);

	if (root == first || root == second)
		return (root);

	lca_l = bta_helper(root->left, first, second);
	lca_r = bta_helper(root->right, first, second);

	if (lca_l && lca_r)
		return (root);

	return (lca_l ? lca_l : lca_r);
}
