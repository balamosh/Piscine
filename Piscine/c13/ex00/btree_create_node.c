#include "ft_btree.h"
#include <stdlib.h>

t_btree	*btree_create_node(void *item)
{
	t_btree	*node;

	node = (t_btree *) malloc(sizeof(t_btree));
	if (!node)
		return (NULL);
	node -> left = NULL;
	node -> right = NULL;
	node -> item = item;
	return (node);
}
