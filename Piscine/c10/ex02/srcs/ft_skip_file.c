#include "ft.h"
#include "ft_tail.h"

void	ft_skip_file(int fd, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i++ < n)
		read(fd, &c, 1);
}
