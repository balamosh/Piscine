int	ft_iterative_power(int nb, int power)
{
	long int	i;
	int			res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 1)
		return (1);
	i = 1;
	res = 1;
	while (i++ <= power)
		res *= nb;
	return (res);
}
