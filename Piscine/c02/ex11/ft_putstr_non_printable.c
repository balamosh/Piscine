#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_is_printable(char c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

void	ft_puthex(char c)
{
	if (c <= 9)
		ft_putchar(c + '0');
	else
		ft_putchar(c - 10 + 'a');
}

void	ft_putcharhex(char c)
{
	ft_puthex(c / 16);
	ft_puthex(c % 16);
}

void	ft_putstr_non_printable(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (ft_is_printable(str[i]))
			ft_putchar(str[i]);
		else
		{
			ft_putchar('\\');
			ft_putcharhex(str[i]);
		}
		i += 1;
	}
}
