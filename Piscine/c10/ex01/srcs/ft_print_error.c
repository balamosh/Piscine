#include "ft.h"
#include "ft_cat.h"

void	ft_putstr_error(char *str)
{
	while (*str != '\0')
		write(2, str++, 1);
}

int	ft_print_error(char *file, char *name)
{
	char	*error;

	ft_putstr_error(name);
	ft_putstr_error(": ");
	ft_putstr_error(file);
	ft_putstr_error(": ");
	error = strerror(errno);
	ft_putstr_error(error);
	ft_putstr_error("\n");
	return ((int) errno);
}
