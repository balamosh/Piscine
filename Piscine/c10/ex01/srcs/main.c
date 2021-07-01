#include "ft_cat.h"
#include "ft.h"

int	main(int ac, char **av)
{
	int		fd;
	int		i;
	char	*name;

	name = basename(av[0]);
	if (ac == 1)
		return (ft_cat_stdin(name));
	i = 1;
	while (i < ac)
	{
		if (ft_strcmp(av[i], "-") == 0)
			ft_cat_stdin(name);
		else
		{
			fd = open(av[i], O_RDONLY);
			ft_cat(fd, av[i], name);
			close(fd);
		}
		i += 1;
	}
	return (0);
}
