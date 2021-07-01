char	*ft_strlowcase(char *str)
{
	int	i;
	int	offset;

	i = 0;
	offset = 'a' - 'A';
	while (str[i] != '\0')
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += offset;
		i += 1;
	}
	return (str);
}
