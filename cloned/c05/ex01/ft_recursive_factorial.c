int	ft_recursive_factorial(int nb)
{
	int	fac;

	if (nb < 0)
		return (0);
	if (nb == 0 || nb == 1)
		return (1);
	fac = ft_recursive_factorial(nb - 1) * nb;
	return (fac);
}
