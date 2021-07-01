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

int	ft_search_base(char c, char *base)
{
	int	i;

	i = 0;
	while (base[i] != '\0')
		if (base[i++] == c)
			return (i - 1);
	return (-1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

int	ft_base_check(char *base)
{
	char	found[256];
	int		i;
	int		max_found;
	int		base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	max_found = 0;
	while (*base != '\0')
	{
		i = 0;
		if (*base == '+' || *base == '-' || ft_is_space(*base))
			return (0);
		while (i < max_found)
			if (*base == found[i++])
				return (0);
		found[max_found] = *base;
		max_found += 1;
		base += 1;
	}
	return (base_len);
}

int	ft_atoi_base(char *str, char *base)
{
	int	i;
	int	nb;
	int	sign;
	int	base_len;

	i = 0;
	nb = 0;
	sign = 1;
	base_len = ft_base_check(base);
	if (base_len < 2)
		return (0);
	while (ft_is_space(str[i]))
		i += 1;
	while (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= -1;
		i += 1;
	}
	while (ft_search_base(str[i], base) != -1)
		nb = nb * base_len + ft_search_base(str[i++], base);
	return (sign * nb);
}
