int	ft_iterative_factorial(int nb)
{
	int			fac;
	long int	i;

	if (nb < 0)
		return (0);
	i = 1;
	fac = 1;
	while (i <= nb)
		fac *= i++;
	return (fac);
}
