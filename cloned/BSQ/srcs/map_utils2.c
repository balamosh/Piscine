#include "ft.h"

static void	ft_free_tab(char **tab)
{
	int	i;

	i = 0;
	if (!tab)
		return ;
	while (tab[i])
		free(tab[i++]);
	free(tab);
}

t_map	*free_map(t_map *map)
{
	if (!map)
		return (NULL);
	ft_free_tab(map->tab);
	free(map);
	return (NULL);
}

int	ft_init_map(t_map *map)
{
	char	**tab;
	int		i;

	if (!map)
		return (0);
	tab = (char **) malloc(sizeof(char *) * (map->sizeY + 1));
	if (!tab)
		return (0);
	i = 0;
	while (i < map->sizeY + 1)
		tab[i++] = NULL;
	map->tab = tab;
	return (1);
}

void	print_answer(const t_map *map, const t_ans *answer)
{
	int	i;
	int	j;

	i = answer->row;
	while (i > answer->row - answer->len)
	{
		j = answer->col;
		while (j > answer->col - answer->len)
			map->tab[i][j--] = map->full;
		i--;
	}
	i = 0;
	while (i < map->sizeY && map->tab[i])
	{
		write(1, map->tab[i++], map->sizeX);
		write(1, "\n", 1);
	}
}
