#include "ft.h"

t_list	*ft_read_one(char *str, t_list *reg_nbrs, t_list *begin_fin, t_list *dec_nbrs, int i)
{
	t_list	*list;
	t_list	*list_d
	int		count;
	
	check = i;
	count = 0;
	elem = 	ft_fill_dict_elem(str, Null)
	list = ft_list_find (reg_nbrs, elem, &ft_cmp)
	ft_free_dict(elem);
	if (i == 0)
	{
		elem = ft_fill_dict_elem("100", Null)
   		list_d = ft_list_find (dec_nbrs, elem, &ft_cmp);
		ft_free_dict(elem);
		ft_list_push_back(begin_fin, list_d->data->word);
	}
	ft_list_push_front(begin_fin, list->data->word);
	count++;
	while (i > 0)
		str[2 - i--] = '0';
	if (count > 0)
		return (begin_fin);
	return (0);
}

char	*ft_nbr_to_text(char *str, t_list *reg_nbrs, t_list *begin_fin, t_list *dec_nbrs)
{
	int	i;

	i = 2;
	if (str[1] == '1') 
		i = 1;
	while (i >= 0)
	{
		if (str[i] == 0)
			continue;
		if (i = 0)
			begin_fin = ft_read_one(str[0], reg_nbrs, begin_fin, dec_nbrs, i);
		else
			begin_fin = ft_read_one(str + i, reg_nbrs, begin_fin, dec_nbrs, i);
		if (begin_fin == 0)
			return (0);
	}
	return (begin_fin);
}

char	*ft_create_str(int l, char *str, int len)
{
	char	*full_str;
	char	*ptr;
	int		i;
	
	i = 0;
	full_str = (char *)malloc(l + 1);
	full_str[l] = '\0';
	ptr = full_str;
	while (str != '\0')
		*ptr = '0'; 
	while (i < len)
		full_str[l - i - 1] = str[len - i];
	return (full_str);
}

char	*ft_typer(char *strng, t_list *reg_nbrs, t_list *begin_fin, t_list *dec_nbrs)
{
	int					i;
	int					len;
	char				*str;
   	char				*full_str;

	i = 0;
	len = strlen(string);
	if (*string == '0' && len == 1)
		return (ft_list_find (reg_nbrs, ft_fill_dict_elem(string, Null), &ft_cmp);
	full_str = ft_create_str(len + len % 3, str, len);
	while (i <= len / 3)
	{
		str = full_str[len - (3 * i + 3) + len % 3 - 1];
		if (str[0] == str[1] && str[1] == str[2] && str[2] == str[3] && str[3] == '0')
		{
			i++;
			continue ;
		}
		else 
			begin_fin = ft_nbr_to_text(str, reg_nbrs, begin_fin, dec_nbrs);
		i++;
	}
	free(full_str);
	return (begin_fin);
}
