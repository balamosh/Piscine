#include "ft.h"

int	ft_print_error(int code, char *err)
{
	while (*err != '\0')
		write (1, err++, 1);
	return (code);
}
