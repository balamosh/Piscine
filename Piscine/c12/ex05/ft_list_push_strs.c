#include "ft_list.h"

t_list	*ft_create_elem(void *data);

void	ft_list_push_front(t_list **begin_list, void *data)
{
	t_list	*elem;

	elem = ft_create_elem(data);
	if (!elem)
		return ;
	elem->next = *begin_list;
	*begin_list = elem;
}

t_list	*ft_list_push_strs(int size, char **strs)
{
	t_list	*begin_list;
	int		i;

	begin_list = (void *) 0;
	i = 0;
	while (i < size)
		ft_list_push_front(&begin_list, (void *)(strs[i++]));
	return (begin_list);
}
