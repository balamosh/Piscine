#include "ft.h"

int	main(int ac, char **av)
{
	int	i;

	if (ac == 1)
		bsq_stdin();
	else if (ac == 2)
		bsq(av[1]);
	else
	{
		i = 0;
		while (++i < ac)
		{
			bsq(av[i]);
			if (i != ac - 1)
				write(1, "\n", 1);
		}
	}
	return (0);
}
