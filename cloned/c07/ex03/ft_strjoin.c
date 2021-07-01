#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

char	*ft_insert_str(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i += 1;
	}
	return (dest + i);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		str_len;
	char	*dest;
	char	*orig_dest;

	i = 0;
	str_len = 0;
	while (i < size)
		str_len += ft_strlen(strs[i++]);
	str_len += ft_max(size - 1, 0) * ft_strlen(sep);
	dest = (char *) malloc(sizeof(char) * (str_len + 1));
	if (NULL == dest)
		return (dest);
	orig_dest = dest;
	i = 0;
	while (i < size)
	{
		dest = ft_insert_str(dest, strs[i]);
		if (i != size - 1)
			dest = ft_insert_str(dest, sep);
		i += 1;
	}
	*dest = '\0';
	return (orig_dest);
}
