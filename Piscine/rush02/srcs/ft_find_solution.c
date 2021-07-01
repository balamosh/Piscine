#include "ft.h"

static int	ft_is_all_zeros(char *str)
{
	while (*str != '\0')
		if (*str != '0')
			return (0);
	return (1);
}

static void	ft_fill_zeros(char *str, int len)
{
	int	i;

	i = 0;
	while (i < len)
		str[i++] = '0';
}

void	ft_find_solution(t_list **answer, char *nbr, t_list *reg_nbrs, t_list *dec_nbrs, int len)
{
	int		i;
	t_list	*find;
	t_dict	*elem;
	int		dec;

	if (ft_is_all_zeros(nbr))
		return ;
	dec = 0;
	i = 0;
	while (i < len)
	{
		elem = ft_fill_dict_elem(nbr + i++, "");
		find = ft_list_find(elem, reg_nbrs, &ft_cmp);
		free(elem);
		if (find)
			break ;
	}
	if (!find)
	{
		dec = 1;
		i = 0;
		while (i < len)
		{
			elem = ft_fill_dict_elem(nbr + i++, "");
			find = ft_list_find(elem, dec_nbrs, &ft_cmp);
			free(elem);
			if (find)
				break ;
		}
	}
	if (!find)
	{
		ft_list_clear(*answer, &free);
		*answer = NULL;
		return ;
	}
	ft_list_push_front(answer, find->word);
	if (dec)
		ft_find_solution(answer, nbr + i - ft_max(len - i, 3), reg_nbrs, dec_nbrs, ft_max(len - i, 3));
	ft_fill_zeros(nbr + i, len - i);
	ft_find_solution(answer, nbr, reg_nbr, dec_nbr, len);
}
