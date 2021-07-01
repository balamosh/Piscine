#include "ft.h"
#include "ft_tail.h"

void	ft_print_head(char *file, int head)
{
	if (!head)
		return ;
	if (head == 2)
		ft_putstr("\n");
	ft_putstr("==> ");
	ft_putstr(file);
	ft_putstr(" <==\n");
}
