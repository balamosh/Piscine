#include "ft.h"
#include "ft_tail.h"

int	ft_print_input_error(char *name, char *nbr)
{
	ft_putstr_error(name);
	ft_putstr_error(": illegal offset -- ");
	ft_putstr_error(nbr);
	ft_putstr_error("\n");
	return (1);
}

int	ft_tail_check_flags(char *name, char *flag, char *nbr, int *n)
{
	int	start;

	if (ft_strcmp(flag, "-c") == 0)
		start = 3;
	else
	{
		nbr = flag + 2;
		start = 2;
	}
	*n = ft_atoi(nbr);
	if (*n < 0)
		return (ft_print_input_error(name, nbr));
	return (start);
}
