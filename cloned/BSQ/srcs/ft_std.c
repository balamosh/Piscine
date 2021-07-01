#include "ft.h"

void	ft_putstr(const char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	ft_strlen(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

char	*ft_strcpy(char *dest, const char *src)
{
	int	i;

	i = 0;
	while (1)
	{
		dest[i] = src[i];
		if (src[i] == '\0')
			break ;
		i += 1;
	}
	return (dest);
}

char	*ft_strdup(const char *src)
{
	char	*dest;
	int		len;

	len = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (NULL == dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}
