#include "ft.h"

int	main(int ac, char **av)
{
	if (ac != 4)
		return (1);
	ft_doop(av[1], av[2], av[3]);
}
