#include "ft.h"

int	atoi_map(const char *str, int n)
{
	int	i;
	int	result;

	i = 0;
	result = 0;
	while (i < n - 3)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
		result = result * 10 + (str[i++] - '0');
	}
	return (result);
}

int	ft_ismap(const t_map *map, const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] != map->empty && str[i] != map->obstacle)
			return (0);
		i++;
	}
	return (1);
}
