#include <unistd.h>
#include <stdio.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		write(1, str + i, 1);
		i += 1;
	}
}

int	ft_coma_check(char *buf, int n)
{
	int	i;
	int	j;

	i = 9;
	j = n - 1;
	while (j >= 0)
	{
		if (buf[j] != i + '0')
			return (1);
		j -= 1;
		i -= 1;
	}
	return (0);
}

void	ft_rec_print(char *buf, int i, int n)
{
	int	digit;

	if (i == n)
	{
		write(1, buf, n);
		if (ft_coma_check(buf, n))
		{
			ft_putchar(',');
			ft_putchar(' ');
		}
		else
			ft_putchar('\n');
		return ;
	}
	if (i == 0)
		digit = 0;
	else
		digit = buf[i - 1] - '0' + 1;
	while (digit <= 9)
	{
		buf[i] = digit + '0';
		ft_rec_print(buf, i + 1, n);
		digit += 1;
	}
}

void	ft_print_combn(int n)
{
	char	buff[10];

	buff[n + 1] = '\0';
	ft_rec_print(buff, 0, n);
}
