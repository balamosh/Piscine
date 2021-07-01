#include "ft.h"
#include <stdio.h>

void	ft_print_data(void *data)
{
	t_dict	*elem;

	elem = (t_dict *) data;
	printf("nbr:%s\n", elem->nbr);
	printf("word:%s\n", elem->word);
	printf("nbr_len = %d\n", elem->nbr_len);
	printf("word_len = %d\n", elem->word_len);
	printf("\n");
}

int	main(int ac, char **av)
{
	t_list	*dec_nbrs;
	t_list	*reg_nbrs;
	t_list	*elem;

	if (ac != 2)
		return (1);
	ft_parse_dict(av[1], &reg_nbrs, &dec_nbrs);
	ft_list_foreach(reg_nbrs, &ft_print_data);
	printf("-------------------------------------\n");
	ft_list_foreach(dec_nbrs, &ft_print_data);
	elem = ft_list_find(reg_nbrs, ft_fill_dict_elem("1", "one"), &ft_cmp);
	if (!elem)
		printf("not found\n");
	else
		printf("found:%s\n", ((t_dict *)(elem->data))->nbr);
}
