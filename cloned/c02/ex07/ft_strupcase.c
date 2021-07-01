char	*ft_strupcase(char *str)
{
	int	i;
	int	offset;

	i = 0;
	offset = 'A' - 'a';
	while (str[i] != '\0')
	{
		if (str[i] >= 'a' && str[i] <= 'z')
			str[i] += offset;
		i += 1;
	}
	return (str);
}
