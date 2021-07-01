#include "ft.h"

static int	ft_min_of_three(int left, int diag, int up)
{
	if (left <= diag && left <= up)
		return (left);
	else if (diag <= left && diag <= up)
		return (diag);
	else
		return (up);
}

static void	modify_answer(t_ans *answer, int x, int y, int len)
{
	answer->len = len;
	answer->row = y;
	answer->col = x;
}

static void	fill_first_line(const t_map *map, int *temp, t_ans *answer)
{
	int	i;

	i = 0;
	while (i < map->sizeX)
	{
		if (map->tab[0][i] == map->empty)
		{
			temp[i] = 1;
			if (answer->len == 0)
				modify_answer(answer, i, 0, 1);
		}
		else
			temp[i] = 0;
		i++;
	}
}

static void	fill_rest_lines(const t_map *map, int *temp, t_ans *answer, int j)
{
	int	i;
	int	left;
	int	new;

	left = 0;
	if (map->tab[j][0] == map->empty)
		left = 1;
	i = 1;
	while (i < map->sizeX)
	{
		if (map->tab[j][i] == map->empty)
		{
			new = ft_min_of_three(left, temp[i - 1], temp[i]) + 1;
			if (new > answer->len)
				modify_answer(answer, i, j, new);
			temp[i++ - 1] = left;
			left = new;
		}
		else
		{
			temp[i++ - 1] = left;
			left = 0;
		}
	}
	temp[i - 1] = left;
}

t_ans	*fill_answer(const t_map *map)
{
	t_ans	*answer;
	int		j;
	int		*temp;

	answer = malloc(sizeof (t_ans));
	answer->row = map->sizeX;
	answer->col = map->sizeY;
	answer->len = 0;
	temp = malloc(sizeof (*temp) * (map->sizeX));
	if (!temp)
		return (NULL);
	fill_first_line(map, temp, answer);
	j = 1;
	while (j < map->sizeY)
		fill_rest_lines(map, temp, answer, j++);
	free(temp);
	return (answer);
}
