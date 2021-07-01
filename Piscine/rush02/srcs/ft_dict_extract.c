#include "ft.h"
#include <stdio.h>

char	*ft_dict_extract_nbr(char *str)
{
	char	*start;
	int		i;

	while (ft_isspace(*str) && *str != '\n')
		str += 1;
	if (*str == '+')
		str += 1;
	start = str;
	i = 0;
	while (ft_isdigit(str[i]))
		i += 1;
	if (i == 0)
		return (NULL);
	return (ft_strndup(start, i));
}

char	*ft_dict_extract_word(char *str)
{
	char	*start;
	int		i;

	i = 0;
	while (*str != ':' && *str != '\n')
		str += 1;
	if (*str != ':')
		return (NULL);
	str += 1;
	while (ft_isspace(*str) && *str != '\n')
		str += 1;
	start = str;
	i = 0;
	while (ft_isprintable(str[i]))
		i += 1;
	if (i == 0 || str[i] != '\n')
		return (NULL);
	str[i] = '\0';
	return (ft_strdup(start));
}
