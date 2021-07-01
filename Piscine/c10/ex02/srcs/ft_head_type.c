#include "ft_tail.h"

int	ft_head_type(int i, int ac, int start)
{
	int	head;

	if (ac > start + 1)
	{
		if (i > start)
			head = 2;
		else
			head = 1;
	}
	else
		head = 0;
	return (head);
}
