#include "ft.h"

void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *))
{
	t_list	*tmp;

	while (begin_list)
	{
		(*free_fct)(begin_list -> data);
		tmp = begin_list;
		begin_list = begin_list -> next;
		tmp -> next = (void *) 0;
		free(tmp);
	}
}
