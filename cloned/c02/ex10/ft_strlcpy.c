unsigned int	ft_strlen(char *str)
{
	unsigned int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size)
{
	unsigned int	i;
	unsigned int	src_len;

	i = 0;
	src_len = ft_strlen(src);
	if (size == 0)
		return (src_len);
	while (i < size - 1)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			return (src_len);
		i += 1;
	}
	dest[i] = '\0';
	return (src_len);
}
