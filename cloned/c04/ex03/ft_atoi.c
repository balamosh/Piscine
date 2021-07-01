int	ft_is_space(char c)
{
	if (c == ' ')
		return (1);
	if (c == '\t')
		return (1);
	if (c == '\n')
		return (1);
	if (c == '\v')
		return (1);
	if (c == '\f')
		return (1);
	if (c == '\r')
		return (1);
	return (0);
}

int	ft_is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

int	ft_is_sign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (1);
	return (0);
}

int	ft_atoi(char *str)
{
	int	i;
	int	nb;
	int	sign;

	i = 0;
	nb = 0;
	sign = 1;
	while (ft_is_space(str[i]))
		i += 1;
	while (ft_is_sign(str[i]))
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (ft_is_digit(str[i]))
		nb = nb * 10 + str[i++] - '0';
	return (sign * nb);
}
