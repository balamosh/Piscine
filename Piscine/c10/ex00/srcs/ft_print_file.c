#include "ft.h"
#include "ft_display_file.h"

int	ft_print_file(int fd)
{
	char	buff[BUFF_SIZE];
	int		rd;

	rd = read(fd, buff, BUFF_SIZE);
	while (rd > 0)
	{
		write(1, buff, rd);
		rd = read(fd, buff, BUFF_SIZE);
	}
	if (rd == -1)
		return (ft_print_error(3, "Cannot read file.\n"));
	return (0);
}
