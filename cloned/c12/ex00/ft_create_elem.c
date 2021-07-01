#include "ft_list.h"
#include <stdlib.h>

t_list	*ft_create_elem(void *data)
{
	t_list	*elem;

	elem = (t_list *) malloc(sizeof(t_list));
	if (!elem)
		return ((void *) 0);
	elem->next = (void *) 0;
	elem->data = data;
	return (elem);
}
