#include "ft.h"
#include "ft_tail.h"

int	ft_print_error(char *file, char *name, int head)
{
	char	*error;

	error = strerror(errno);
	if (ft_strcmp(error, "Is a directory") == 0)
	{
		ft_print_head(file, head);
		return ((int) errno);
	}
	ft_putstr_error(name);
	ft_putstr_error(": ");
	ft_putstr_error(file);
	ft_putstr_error(": ");
	ft_putstr_error(error);
	ft_putstr_error("\n");
	return ((int) errno);
}
