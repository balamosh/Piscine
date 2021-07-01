#include "ft_list.h"
#include <stdlib.h>

void	ft_init(t_list **list, t_list **prev, t_list *begin_list)
{
	*list = begin_list;
	prev = (void *) 0;
}

void	ft_list_remove_if(t_list **begin_list, void *data_ref, \
		int (*cmp)(), void (*free_fct)(void *))
{
	t_list	*list;
	t_list	*tmp;
	t_list	*prev;

	ft_init(&list, &prev, *begin_list);
	while (list)
	{
		if ((*cmp)(list -> data, data_ref) == 0)
		{
			(*free_fct)(list -> data);
			tmp = list;
			list = list -> next;
			tmp -> next = (void *) 0;
			if (tmp == *begin_list)
				*begin_list = list;
			else if (prev)
				prev -> next = list;
			free(tmp);
		}
		else
		{
			prev = list;
			list = list -> next;
		}
	}
}
