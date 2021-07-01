#include "ft_stock_str.h"
#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i += 1;
	}
	return (dest);
}

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (NULL == dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}

void	ft_free_all(struct s_stock_str *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
		free(arr[i++].copy);
	free(arr);
}

struct s_stock_str	*ft_strs_to_tab(int ac, char **av)
{
	struct s_stock_str	*out;
	int					i;

	out = (struct s_stock_str *) malloc(sizeof(struct s_stock_str) * (ac + 1));
	if (NULL == out)
		return (NULL);
	i = 0;
	while (i < ac)
	{
		out[i].copy = ft_strdup(av[i]);
		if (NULL == out[i].copy)
		{
			ft_free_all(out, i + 1);
			return (NULL);
		}
		out[i].size = ft_strlen(av[i]);
		out[i].str = av[i];
		i += 1;
	}
	out[i].str = NULL;
	return (out);
}
