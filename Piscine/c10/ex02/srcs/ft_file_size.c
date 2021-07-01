#include "ft.h"
#include "ft_tail.h"

int	ft_file_size(char *file)
{
	char	buff[BUFF_SIZE];
	int		fd;
	int		len;
	int		rd;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (-1);
	len = 0;
	rd = read(fd, buff, BUFF_SIZE);
	while (rd > 0)
	{
		len += rd;
		rd = read(fd, buff, BUFF_SIZE);
	}
	if (rd == -1)
		return (-1);
	return (len);
}
