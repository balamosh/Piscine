#include <unistd.h>

void	ft_putstr(char *str)
{
	while (*str != '\0')
		write(1, str++, 1);
}

int	ft_print_error(int code)
{
	ft_putstr("Error\n");
	return (code);
}
