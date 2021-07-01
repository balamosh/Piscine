#include "ft.h"

int	main(int ac, char **av)
{
	t_nlist	*reg_nbrs;
	t_nlist	*dec_nbrs;
	char	*err;

	if (ac > 3)
		return (ft_print_error(1, "Error\n"));
	ft_fill_std_dict();
	if (ac > 2)
	{
		ft_parse_dict(av[1], &reg_nbrs, &dec_nbrs);
		nbr = av[2];
	}
	else if (ac == 2)
	{
		reg_nbrs = g_std_reg_nbrs;
		dec_nbrs = g_std_dec_nbrs;
		nbr = av[1];
	}
	err = ft_check_input(nbr, &reg_nbrs, &dec_nbrs);
	if (err)
		return (ft_print_error(2, err));
	ft_print_result(nbr, &reg_nbrs, &dec_nbrs);
	return (1);
}
