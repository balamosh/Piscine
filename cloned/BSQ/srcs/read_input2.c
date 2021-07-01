#include "ft.h"

static int	ft_is_printable(const char *str)
{
	while (*str != '\0')
	{
		if (!(*str >= 32 && *str <= 126))
			return (0);
		str += 1;
	}
	return (1);
}

static t_map	*process_first_line(t_map *map, const char *line)
{
	int	len;

	if (!line)
		return (free_map(map));
	len = ft_strlen(line);
	if (len < 4 || !ft_is_printable(line))
		return (free_map(map));
	map->sizeY = atoi_map(line, len);
	if (!map->sizeY)
		return (free_map(map));
	map->full = line[len - 1];
	map->obstacle = line[len - 2];
	map->empty = line[len - 3];
	if (map->full == map->obstacle
		|| map->obstacle == map->empty
		|| map->empty == map->full)
		return (free_map(map));
	return (map);
}

static t_map	*process_second_line(t_map *map, char *line)
{
	int	len;

	if (!line)
		return (free_map(map));
	len = ft_strlen(line);
	if (len == 0)
		return (free_map(map));
	if (!ft_ismap(map, line))
		return (free_map(map));
	map->sizeX = len;
	if (!ft_init_map(map))
		return (free_map(map));
	map->tab[0] = line;
	return (map);
}

static t_map	*process_map_end(int fd, t_map *map)
{
	char	*line;
	int		rd;
	int		i;

	i = 0;
	while (++i < map->sizeY)
	{
		line = (char *) malloc(sizeof(char) * (map->sizeX + 1));
		map->tab[i] = line;
		if (!line)
			return (free_map(map));
		rd = read(fd, line, map->sizeX + 1);
		if (rd != map->sizeX + 1 || line[map->sizeX] != '\n')
			return (free_map(map));
		line[map->sizeX] = '\0';
	}
	rd = read(fd, line, map->sizeX);
	if (rd != 0)
		return (free_map(map));
	return (map);
}

t_map	*fill_map(int fd, const char *first_line, char *second_line)
{
	t_map	*map;

	map = (t_map *) malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->tab = NULL;
	map = process_first_line(map, first_line);
	if (!map)
		return (NULL);
	map = process_second_line(map, second_line);
	if (!map)
		return (NULL);
	map = process_map_end(fd, map);
	return (map);
}
