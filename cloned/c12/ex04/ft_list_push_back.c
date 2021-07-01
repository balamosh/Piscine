#include "ft_list.h"

t_list	*ft_create_elem(void *data);

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
