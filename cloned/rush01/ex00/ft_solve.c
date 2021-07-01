#include <stdlib.h>

int	ft_check_line_left(int line, int col, int **tab, int size, int *input);
int ft_check_line_right(int line, int col, int **tab, int size, int *input);
int ft_check_col_up(int line, int col, int **tab, int size, int *input);
int ft_check_col_down(int line, int col, int **tab, int size, int *input);
int	ft_check_solution(int **tab, int size, int *input);

int	**ft_init_table(int size)
{
	int	i;
	int	**arr;

	i = 0;
	arr = (int **) malloc (sizeof(int *) * size);
	while (i < size)
		arr[i++] = (int *) malloc(sizeof(int) * size);
	return (arr);
}

int	ft_check(int line, int col, int **tab, int size, int *input)
{
	int	ch_col;
	int	ch_line;

	if (col == size - 1)
		ch_line = ft_check_line_left(line, col, tab, size, input);
	else
		ch_line = ft_check_line_right(line, col, tab, size, input);
	if (line == size - 1)
		ch_col = ft_check_col_up(line, col, tab, size, input);
	else
		ch_col = ft_check_col_down(line, col, tab, size, input);
	return (ch_line * ch_col);
}

int	ft_rec_solve(int line, int col, int **tab, int size, int *input)
{
	int	i;

	if (line == size || col == size)
		if (ft_check_solution(tab, size, input))
			return (1);
	i = 0;
	while (i < size)
	{
		if (ft_check(line, col, tab, size, input))
		{
			i += 1;
			continue ;
		}
		tab[line][col] = i++;
		if (col == size - 1)
			ft_rec_solve(line + 1, 0, tab, size, input);
		else
			ft_rec_solve(line, col + 1, tab, size, input);
	}
	return (0);
}

int	**ft_solve(int *input, int size)
{
	int	**tab;

	tab = ft_init_table(size);
	if(ft_rec_solve(0, 0, tab, size, input))
		return (tab);
	return (NULL);
}
