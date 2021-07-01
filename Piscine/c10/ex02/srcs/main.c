#include "ft_tail.h"
#include "ft.h"

int	main(int ac, char **av)
{
	int		i;
	int		n;
	int		start;
	char	*name;
	t_file	file;

	name = basename(av[0]);
	if (ac > 2)
		start = ft_tail_check_flags(name, av[1], av[2], &n);
	else
		start = ft_tail_check_flags(name, av[1], av[1], &n);
	if (n < 0)
		return (1);
	if (ac == start)
		return (ft_tail_stdin(name, n));
	i = start;
	while (i < ac)
	{
		file.fd = open(av[i], O_RDONLY);
		file.filename = av[i];
		ft_tail_malloc(file, name, n, ft_head_type(i, ac, start));
		close(file.fd);
		i += 1;
	}
	return (0);
}
