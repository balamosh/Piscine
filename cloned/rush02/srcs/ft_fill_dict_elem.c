#include "ft.h"

t_dict	*ft_fill_dict_elem(char *nbr, char *word)
{
	t_dict	*elem;

	elem = (t_dict *) malloc (sizeof(t_dict));
	if (!elem)
		return (NULL);
	elem->nbr = ft_strdup(nbr);
	elem->word = ft_strdup(word);
	elem->nbr_len = ft_strlen(elem->nbr);
	elem->word_len = ft_strlen(elem->word);
	return (elem);
}
