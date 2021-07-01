#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

void	ft_putstr(char *str)
{
	while (*str != '\0')
	{
		ft_putchar(*str);
		str += 1;
	}
}

int	main(int ac, char **av)
{
	ac = ac - 0;
	ft_putstr(av[0]);
	ft_putstr("\n");
}
