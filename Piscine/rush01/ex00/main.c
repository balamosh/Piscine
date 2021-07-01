#include "ft_head.h"
#include <stdlib.h>

int	main(int ac, char **av)
{
	int	*input;
	int	size;
	int	**answer;

	if (ac != 2)
		return (ft_print_error(1));
	size = ft_manage_input(&input, av[1]);
	if (NULL == input)
		return (ft_print_error(2));
	answer = ft_solve(input, size);
	if (NULL == answer)
		return (ft_print_error(3));
	ft_print_answer(answer, size);
	return (0);
}
