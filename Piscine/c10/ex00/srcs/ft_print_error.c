#include "ft.h"

void	ft_putstr_error(char *str)
{
	while (*str != '\0')
		write(2, str++, 1);
}

int	ft_print_error(int code, char *str)
{
	ft_putstr_error(str);
	return (code);
}
