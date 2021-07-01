#include <stdlib.h>

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

int	ft_strncmp(char *s1, char *s2, unsigned int n)
{
	unsigned int	i;
	int				res;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0' && i < n - 1)
	{
		if (s1[i] != s2[i])
			break ;
		i += 1;
	}
	res = s1[i] - s2[i];
	return (res);
}

int	ft_word_count(char *str, char *sep)
{
	int		wc;
	int		sep_len;
	int		i;
	int		word_len;

	wc = 0;
	i = 0;
	sep_len = ft_strlen(sep);
	word_len = 0;
	while (str[i] != '\0')
	{
		if (ft_strncmp(str + i, sep, sep_len) == 0)
		{
			if (word_len != 0)
				wc += 1;
			i += sep_len - 1;
			word_len = 0;
		}
		else
			word_len += 1;
		i += 1;
	}
	if (word_len > 0)
		return (wc + 1);
	return (wc);
}

int	ft_strdup_to_sep(char *str, char *sep, char **dup)
{
	int		i;
	int		sep_len;

	i = 0;
	sep_len = ft_strlen(sep);
	while (str[i] != '\0' && ft_strncmp(str + i, sep, sep_len) != 0)
		i += 1;
	if (i == 0)
		return (0);
	*dup = (char *) malloc(sizeof(char) * (i + 1));
	if (NULL == *dup)
		return (0);
	i = 0;
	while (str[i] != '\0' && ft_strncmp(str + i, sep, sep_len) != 0)
	{
		(*dup)[i] = str[i];
		i += 1;
	}
	(*dup)[i] = '\0';
	return (i);
}

char	**ft_split(char *str, char *charset)
{
	int		wi;
	int		sep_len;
	int		word_len;
	char	**out;

	out = (char **) malloc(sizeof(char *) * (ft_word_count(str, charset) + 1));
	if (NULL == out)
		return (NULL);
	sep_len = ft_strlen(charset);
	wi = 0;
	while (*str != '\0')
	{
		if (ft_strncmp(str, charset, sep_len) == 0)
		{
			str += sep_len;
			continue ;
		}
		word_len = ft_strdup_to_sep(str, charset, out + wi);
		if (word_len > 0)
			wi += 1;
		str += word_len;
	}
	out[wi] = NULL;
	return (out);
}
