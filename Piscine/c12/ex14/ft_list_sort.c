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

t_list	*ft_list_swap_neigh(t_list *begin_list, unsigned int i, unsigned int j)
{
	t_list	*tmp;
	t_list	*i_prev;
	t_list	*j_prev;
	t_list	*i_el;
	t_list	*j_el;

	i_prev = ft_list_at(begin_list, i - 1);
	j_prev = ft_list_at(begin_list, j - 1);
	i_el = ft_list_at(begin_list, i);
	j_el = ft_list_at(begin_list, j);
	if (i_prev)
		i_prev -> next = j_el;
	if (j_prev)
		j_prev -> next = i_el;
	tmp = i_el;
	i_el -> next = j_el -> next;
	j_el -> next = i_el;
	if (i == 0)
		return (j_el);
	if (j == 0)
		return (i_el);
	return (begin_list);
}

t_list	*ft_list_swap(t_list *begin_list, unsigned int i, unsigned int j)
{
	t_list			*el_i[3];
	t_list			*el_j[3];
	unsigned int	k;

	k = -1;
	while (++k < 3)
	{
		el_i[k] = ft_list_at(begin_list, i + k - 1);
		el_j[k] = ft_list_at(begin_list, j + k - 1);
	}
	if (el_i[0])
		(el_i[0])->next = el_j[1];
	if (el_j[0])
		(el_j[0])->next = el_i[1];
	(el_i[1])->next = el_j[2];
	(el_j[1])->next = el_i[2];
	if (i == 0)
		return (el_j[1]);
	if (j == 0)
		return (el_i[1]);
	return (begin_list);
}

void	ft_list_sort(t_list **begin_list, int (*cmp)())
{
	int	i;
	int	size;

	size = ft_list_size(*begin_list);
	while (size > 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if ((*cmp)(ft_list_at(*begin_list, i)->data, \
						ft_list_at(*begin_list, i + 1)->data) > 0)
				*begin_list = ft_list_swap_neigh(*begin_list, i, i + 1);
			i += 1;
		}
		size -= 1;
	}
}
