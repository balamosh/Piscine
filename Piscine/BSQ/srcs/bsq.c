#include "ft.h"

void	bsq(const char *file)
{
	t_map	*map;
	t_ans	*answer;

	map = read_input(file);
	if (map)
		answer = fill_answer(map);
	else
	{
		write(2, "map error\n", 10);
		return ;
	}
	print_answer(map, answer);
	free_map(map);
	free(answer);
}

void	bsq_stdin(void)
{
	t_map	*map;
	t_ans	*answer;

	map = read_std();
	if (map)
		answer = fill_answer(map);
	else
	{
		write(2, "map error\n", 10);
		return ;
	}
	print_answer(map, answer);
	free_map(map);
	free(answer);
}
