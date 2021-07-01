int	ft_ceil_sqrt(int nb)
{
	long int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i += 1;
	}
	return (i);
}

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

int	ft_is_prime(int nb)
{
	int	i;
	int	ceil_sqrt;

	if (nb < 2)
		return (0);
	i = 2;
	ceil_sqrt = ft_ceil_sqrt(nb);
	ceil_sqrt = ft_min(ceil_sqrt, nb - 1);
	while (i <= ceil_sqrt)
	{
		if (nb % i == 0)
			return (0);
		i += 1;
	}
	return (1);
}

int	ft_find_next_prime(int nb)
{
	if (nb < 0)
		return (2);
	while (!ft_is_prime(nb))
		nb += 1;
	return (nb);
}
