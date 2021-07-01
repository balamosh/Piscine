#include "ft.h"
#include "ft_cat.h"

int	ft_cat(int fd, char *file, char *name)
{
	char	buff[BUFF_SIZE];
	int		rd;

	if (fd == -1)
		return (ft_print_error(file, name));
	rd = read(fd, buff, BUFF_SIZE);
	while (rd > 0)
	{
		write(1, buff, rd);
		rd = read(fd, buff, BUFF_SIZE);
	}
	if (rd == -1)
		return (ft_print_error(file, name));
	return (0);
}

int	ft_cat_stdin(char *name)
{
	return (ft_cat(0, "", name));
}
