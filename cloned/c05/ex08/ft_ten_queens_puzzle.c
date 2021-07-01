#include <unistd.h>

int	ft_check_col(int col, int line, int *table)
{
	int	i;

	i = 0;
	while (i < line)
		if (table[i++] == col)
			return (1);
	return (0);
}

int	ft_check_diag(int col, int line, int *table)
{
	int	i;

	i = 0;
	while (i < line)
	{
		if ((table[i] - col == i - line) || (table[i] - col == line - i))
			return (1);
		i += 1;
	}
	return (0);
}

void	ft_print_solution(int *table, int n)
{
	int		i;
	char	c;

	i = 0;
	while (i < n)
	{
		c = table[i++] + '0';
		write(1, &c, 1);
	}
	write(1, "\n", 1);
}

int	ft_queens_rec(int line, int *table, int max)
{
	int	i;
	int	solutions;

	i = 0;
	solutions = 0;
	if (line == max)
	{
		ft_print_solution(table, max);
		return (1);
	}
	while (i < max)
	{
		if (ft_check_col(i, line, table) || ft_check_diag(i, line, table))
		{
			i += 1;
			continue ;
		}
		table[line] = i++;
		solutions += ft_queens_rec(line + 1, table, max);
	}
	return (solutions);
}

int	ft_ten_queens_puzzle(void)
{
	int	table[10];
	int	i;

	i = 0;
	while (i < 10)
		table[i++] = -1;
	return (ft_queens_rec(0, table, 10));
}
