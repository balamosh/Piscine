#include "ft.h"

void	ft_free_dict(void *data)
{
	t_dict	*elem;

	elem = (t_dict *) data;
	if (!elem)
		return ;
	free(elem->nbr);
	free(elem->word);
}
