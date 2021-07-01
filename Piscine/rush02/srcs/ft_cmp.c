#include "ft.h"

int	ft_cmp(void *data_ref, void *data)
{
	t_dict	*elem;
	t_dict	*ref;

	elem = (t_dict *) data;
	ref = (t_dict *) data_ref;
	return (ft_strcmp(elem->nbr, ref->nbr));
}
