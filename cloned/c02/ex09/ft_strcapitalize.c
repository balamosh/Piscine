int	ft_is_alpha(char c)
{
	if (c >= 'a' && c <= 'z')
		return (1);
	return (0);
}

int	ft_is_numeric(char c)
{
	if (c >= '0' && c <= '9')
		return (1);
	return (0);
}

char	*ft_strcapitalize(char *str)
{
	int	i;
	int	in_word;

	i = 0;
	in_word = 0;
	while (str[i] != '\0')
	{
		if (ft_is_alpha(str[i]) || ft_is_numeric(str[i]))
		{
			if (!in_word)
			{
				if (ft_is_alpha(str[i]))
					str[i] += 'A' - 'a';
				in_word = 1;
			}
		}
		else
			in_word = 0;
		i += 1;
	}
	return (str);
}
