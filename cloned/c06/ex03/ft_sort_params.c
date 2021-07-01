#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		write(1, str, 1);
		str += 1;
	}
}

void	ft_str_swap(char **s1, char **s2)
{
	char	*tmp;

	tmp = *s1;
	*s1 = *s2;
	*s2 = tmp;
}

int	ft_strcmp(char *s1, char *s2)
{
	int	i;
	int	res;

	i = 0;
	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
			break ;
		i += 1;
	}
	res = s1[i] - s2[i];
	return (res);
}

void	ft_str_sort(char **strs, int size)
{
	int	i;

	while (size > 0)
	{
		i = 0;
		while (i < size - 1)
		{
			if (ft_strcmp(strs[i], strs[i + 1]) > 0)
				ft_str_swap(&strs[i], &strs[i + 1]);
			i += 1;
		}
		size -= 1;
	}
}

int	main(int ac, char **av)
{
	int	i;

	ft_str_sort(av, ac);
	i = 1;
	while (i < ac)
	{
		ft_putstr(av[i]);
		write(1, "\n", 1);
		i += 1;
	}
}
