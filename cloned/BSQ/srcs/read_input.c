#include "ft.h"

static void	count_lenghts(int fd, int *i, int *n)
{
	int		rd;
	char	buff;

	rd = read(fd, &buff, 1);
	while (rd > 0 && buff != '\n')
	{
		(*i)++;
		rd = read(fd, &buff, 1);
	}
	rd = read(fd, &buff, 1);
	while (rd > 0 && buff != '\n')
	{
		(*n)++;
		rd = read(fd, &buff, 1);
	}
	close(fd);
}

static int	fill_first_lines(const char *file, char **first_line,
		char **second_line)
{
	int		fd;
	char	buff;
	int		i;
	int		n;
	int		rd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (fd);
	i = 0;
	n = 0;
	count_lenghts(fd, &i, &n);
	fd = open(file, O_RDONLY);
	*first_line = malloc(sizeof (char) * (i + 1));
	rd = read(fd, *first_line, i);
	(*first_line)[i] = '\0';
	rd = read(fd, &buff, 1);
	*second_line = malloc(sizeof (char) * (n + 1));
	rd = read(fd, *second_line, n);
	(*second_line)[n] = '\0';
	rd = read(fd, &buff, 1);
	return (fd);
}

t_map	*read_input(const char *file)
{
	t_map	*map;
	char	*first_line;
	char	*second_line;
	int		fd;

	first_line = NULL;
	second_line = NULL;
	fd = fill_first_lines(file, &first_line, &second_line);
	map = fill_map(fd, first_line, second_line);
	free(first_line);
	close(fd);
	return (map);
}
