int	ft_recursive_power(int nb, int power)
{
	int	res;

	if (power < 0)
		return (0);
	if (power == 0)
		return (1);
	if (nb == 1)
		return (1);
	res = ft_recursive_power(nb, power - 1) * nb;
	return (res);
}
