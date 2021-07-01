#include "ft_list.h"

t_list	*ft_list_at(t_list *begin_list, unsigned int nbr)
{
	unsigned int	i;

	i = 0;
	while (begin_list)
	{
		if (i == nbr)
			return (begin_list);
		begin_list = begin_list -> next;
		i += 1;
	}
	return ((void *) 0);
}

int	ft_list_size(t_list *begin_list)
{
	int	i;

	i = 0;
	while (begin_list)
	{
		begin_list = begin_list->next;
		i += 1;
	}
	return (i);
}

void	ft_list_swap_data(t_list *begin_list, unsigned int i, unsigned int j)
{
	void	*tmp;
	t_list	*a;
	t_list	*b;

	a = ft_list_at(begin_list, i);
	b = ft_list_at(begin_list, j);
	tmp = a -> data;
	a -> data = b -> data;
	b -> data = tmp;
}

void	ft_list_reverse_fun(t_list *begin_list)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = ft_list_size(begin_list) - 1;
	while (i < j)
		ft_list_swap_data(begin_list, i++, j--);
}
