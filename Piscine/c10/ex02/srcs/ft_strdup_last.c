#include "ft.h"

char	*ft_strdup_last(char *src, int n)
{
	char	*dest;
	int		len;
	int		offset;

	len = ft_strlen(src);
	dest = (char *) malloc(sizeof(char) * (ft_max(len, n) + 1));
	offset = ft_max(len - n, 0);
	if (NULL == dest)
		return (NULL);
	ft_strcpy(dest, src + offset);
	return (dest);
}
