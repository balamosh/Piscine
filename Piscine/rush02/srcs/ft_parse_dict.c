#include "ft.h"

static int	ft_iszeros(char *str)
{
	while (*str != '\0')
	{
		if (*str != '0')
			return (0);
		str += 1;
	}
	return (1);
}

static int	ft_is_dec_nbr(t_dict *elem)
{
	int	len;

	if (ft_strcmp(elem->nbr, "100") == 0)
		return (1);
	len = ft_strlen(elem->nbr);
	if (len < 3)
		return (0);
	if ((elem->nbr)[0] == '1' && (len - 1) % 3 == 0)
		if (ft_iszeros(elem->nbr + 1))
			return (1);
	return (0);
}

static t_list	*ft_dict_line_len(int fd)
{
	int		*elem;
	t_list	*len_vals;
	int		rd;
	int		len;
	char	buff;

	rd = read(fd, &buff, 1);
	len = 1;
	len_vals = NULL;
	while (rd > 0)
	{
		if (buff == '\n')
		{
			elem = (int *) malloc(sizeof(int));
			*elem = len;
			ft_list_push_back(&len_vals, elem);
			len = 0;
		}
		len += 1;
		rd = read(fd, &buff, 1);
	}
	return (len_vals);
}

static void	ft_fill_dict_values(int fd, t_list **reg_nbrs, t_list **dec_nbrs, \
		t_list *len_vals)
{
	char	*buff;
	t_dict	*elem;
	int		len;
	char	*word;

	while (len_vals)
	{
		len = *((int *)(len_vals->data));
		buff = (char *) malloc(sizeof(char) * (len + 1));
		read(fd, buff, len);
		buff[len] = '\0';
		if (len > 1)
		{
			word = ft_dict_extract_word(buff);
			elem = ft_fill_dict_elem(ft_dict_extract_nbr(buff), word);
			if (ft_is_dec_nbr(elem))
				ft_list_push_front(dec_nbrs, elem);
			else
				ft_list_push_front(reg_nbrs, elem);
		}
		len_vals = len_vals->next;
		free(buff);
	}
	ft_list_clear(len_vals, &free);
}

void	ft_parse_dict(char *file, t_list **reg_nbrs, t_list **dec_nbrs)
{
	int		fd;
	t_list	*len_vals;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		*reg_nbrs = NULL;
		*dec_nbrs = NULL;
		return ;
	}
	len_vals = ft_dict_line_len(fd);
	close(fd);
	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		*reg_nbrs = NULL;
		*dec_nbrs = NULL;
		return ;
	}
	ft_fill_dict_values(fd, reg_nbrs, dec_nbrs, len_vals);
}
