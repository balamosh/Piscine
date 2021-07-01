int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i += 1;
	}
	res = s1[i] - s2[i];
	return (res);
}

char	*ft_strstr(char *str, char *to_find)
{
	int	i;
	int	find_len;
	int	diff;

	i = 0;
	find_len = ft_strlen(to_find);
	if (find_len == 0)
		return (str);
	while (str[i] != '\0')
	{
		diff = ft_strncmp(str + i, to_find, find_len);
		if (diff == 0)
			return (str + i);
		i += 1;
	}
	return ((void *)0);
}
