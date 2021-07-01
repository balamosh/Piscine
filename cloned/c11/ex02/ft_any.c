int	ft_any(char **tab, int(*f)(char*))
{
	while (*tab != (void *) 0)
	{
		if ((*f)(*tab))
			return (1);
		tab += 1;
	}
	return (0);
}
