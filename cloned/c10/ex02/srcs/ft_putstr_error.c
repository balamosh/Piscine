#include "ft.h"

void	ft_putstr_error(char *str)
{
	while (*str != '\0')
		write(2, str++, 1);
}
