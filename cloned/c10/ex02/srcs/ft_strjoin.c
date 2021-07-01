#include "ft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	int		len;
	int		i;
	char	*out;

	len = 0;
	len += ft_strlen(s1);
	len += ft_strlen(s2);
	out = (char *) malloc(sizeof(char) * (len + 1));
	i = 0;
	while (*s1 != '\0')
		out[i++] = *(s1++);
	while (*s2 != '\0')
		out[i++] = *(s2++);
	out[i] = '\0';
	return (out);
}
