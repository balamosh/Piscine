int	ft_sqrt(int nb)
{
	long int	i;

	i = 0;
	while (i * i <= nb)
	{
		if (i * i == nb)
			return (i);
		i += 1;
	}
	return (0);
}
