#include "ft.h"

void	ft_list_push_back(t_list **begin_list, void *data)
{
	t_list	*elem;
	t_list	*list;

	elem = ft_create_elem(data);
	list = *begin_list;
	if (!elem)
		return ;
	if (!list)
	{
		*begin_list = elem;
		return ;
	}
	while (list->next)
		list = list->next;
	list->next = elem;
}
