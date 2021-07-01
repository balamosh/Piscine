#include "ft_btree.h"

void	*btree_search_item(t_btree *root, void *data_ref, \
		int (*cmpf)(void *, void *))
{
	void	*found;

	if (!root)
		return ((void *) 0);
	found = btree_search_item(root -> left, data_ref, cmpf);
	if (!found && (*cmpf)(root -> item, data_ref) == 0)
		return (root -> item);
	if (!found)
		found = btree_search_item(root -> right, data_ref, cmpf);
	return (found);
}
