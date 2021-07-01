#include "ft.h"

static char	*ft_append_char(char *str, char c, int len)
{
	char	*dest;

	dest = (char *) malloc(sizeof(char) * (len + 2));
	ft_strcpy(dest, str);
	dest[len] = c;
	dest[len + 1] = '\0';
	free(str);
	return (dest);
}

static char	*read_line_char(void)
{
	char	buff;
	char	*str;
	int		rd;
	int		len;

	str = ft_strdup("\0");
	len = 0;
	rd = read(0, &buff, 1);
	while (rd > 0 && buff != '\n')
	{
		str = ft_append_char(str, buff, len++);
		rd = read(0, &buff, 1);
	}
	if (rd == -1 || len == 0)
	{
		free(str);
		return (NULL);
	}
	return (str);
}

t_map	*read_std(void)
{
	t_map	*map;
	char	*first_line;
	char	*second_line;

	first_line = read_line_char();
	second_line = read_line_char();
	map = fill_map(0, first_line, second_line);
	free(first_line);
	return (map);
}
