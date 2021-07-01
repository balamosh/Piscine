void	ft_str_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i += 1;
	}
	res = s1[i] - s2[i];
	return (res);
}

int	ft_strs_size(char **strs)
{
	int	i;

	i = 0;
	while (strs[i] != (void *) 0)
		i += 1;
	return (i);
}

void	ft_sort_string_tab(char **strs)
{
	int	i;
	int	size;

	size = ft_strs_size(strs);
	while (size > 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(strs[i], strs[i + 1]) > 0)
				ft_str_swap(&strs[i], &strs[i + 1]);
			i += 1;
		}
		size -= 1;
	}
}
