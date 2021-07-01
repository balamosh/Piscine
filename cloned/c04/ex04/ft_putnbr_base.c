#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
		i += 1;
	return (i);
}

int	ft_is_sign(char c)
{
	if (c == '+')
		return (1);
	if (c == '-')
		return (1);
	return (0);
}

int	ft_base_check(char *base)
{
	char	found[256];
	int		i;
	int		max_found;
	int		base_len;

	base_len = ft_strlen(base);
	if (base_len < 2)
		return (0);
	max_found = 0;
	while (*base != '\0')
	{
		i = 0;
		while (i < max_found)
			if (*base == found[i++] || ft_is_sign(*base))
				return (0);
		found[max_found] = *base;
		max_found += 1;
		base += 1;
	}
	return (base_len);
}

void	ft_putnbr_base(int nbr, char *base)
{
	long int	n;
	int			base_len;

	base_len = ft_base_check(base);
	if (base_len < 2)
		return ;
	n = nbr;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n < base_len)
		ft_putchar(base[n]);
	else
	{
		ft_putnbr_base(n / base_len, base);
		ft_putchar(base[n % base_len]);
	}
}
