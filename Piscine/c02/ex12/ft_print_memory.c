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

void	ft_puthex(char hex)
{
	if (hex <= 9)
		ft_putchar(hex + '0');
	else
		ft_putchar(hex - 10 + 'a');
}

void	ft_putnbrhex(long int c)
{
	int	i;
	int	hex[16];

	i = 0;
	while (i < 16)
	{
		hex[15 - i] = c % 16;
		c /= 16;
		i += 1;
	}
	i = 0;
	while (i < 16)
		ft_puthex(hex[i++]);
}

void	*ft_print_memory(void *addr, unsigned int size)
{
	unsigned int	i;
	unsigned int	j;
	long int		*adr;

	i = 0;
	adr = (long int *) addr;
	while (i < size)
	{
		ft_putnbrhex((long int) (addr + i));
		write(1, ": ", 3);
		j = 0;
		while (j < 16)
		{
			adr = (long int *) addr + i + j;
			ft_puthex((char) (*adr / 16));
			ft_puthex((char) (*adr % 16));
			adr++;
			ft_puthex((char) (*adr / 16));
			ft_puthex((char) (*adr % 16));
			ft_putchar(' ');
			j += 2;
		}
		ft_putchar('\n');
		i += 16;
	}
	return (addr);
}
