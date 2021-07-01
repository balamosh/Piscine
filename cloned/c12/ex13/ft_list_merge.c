#include "ft_list.h"

void	ft_list_merge(t_list **begin_list1, t_list *begin_list2)
{
	t_list	*list;

	list = *begin_list1;
	if (!list)
	{
		*begin_list1 = begin_list2;
		return ;
	}
	while (list -> next)
		list = list -> next;
	list -> next = begin_list2;
}
