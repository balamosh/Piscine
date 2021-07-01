#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putnbr(int nb)
{
	long int	n;
	
	n = nb;
	if (n < 0)
	{
		ft_putchar('-');
		n = -n;
	}
	if (n <= 9)
		ft_putchar(n + '0');
	else
	{
		ft_putnbr(n / 10);
		ft_putchar(n % 10 + '0');
	}
}

void	ft_putstr(char *str)
{
	while (str != '\0')
		write(1, str++, 1);
}

void	ft_rec_print(int b, int i, int n)
{
	int	digit;

	if (i == n)
	{
		ft_putnbr(b);
		return;
	}
	digit = i + 1;
	while (digit <= n)
	{
		ft_rec_print(10 * b + digit, i + 1, n);
		digit += 1;
	}
}

void	ft_print_combn(int n)
{
	ft_rec_print(0, 0, n);
}
