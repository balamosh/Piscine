#include "ft.h"

char	*ft_strdup(char *src)
{
	char	*dest;
	int		len;

	if (!src)
		return (NULL);
	len = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (NULL == dest)
		return (NULL);
	return (ft_strcpy(dest, src));
}

char	*ft_strndup(char *src, int n)
{
	char	*dest;
	int		len;

	len = ft_max(ft_strlen(src), n);
	dest = (char *) malloc(sizeof(char) * (len + 1));
	if (NULL == dest)
		return (NULL);
	return (ft_strncpy(dest, src, n));
}
