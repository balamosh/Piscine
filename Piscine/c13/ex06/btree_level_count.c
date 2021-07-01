#include "ft_btree.h"

int	btree_level_count_rec(t_btree *root, int cur)
{
	int	left;
	int	right;

	if (!root)
		return (cur);
	left = btree_level_count_rec(root -> left, cur + 1);
	right = btree_level_count_rec(root -> right, cur + 1);
	if (left > right)
		return (left);
	return (right);
}

int	btree_level_count(t_btree *root)
{
	return (btree_level_count_rec(root, 0));
}	
