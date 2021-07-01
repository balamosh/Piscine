void	ft_putchar(char c);

void	ft_print_line(int n, char first, char mid, char last)
{
	int	i;

	if (n < 1)
		return ;
	i = 0;
	if (i < n)
		ft_putchar(first);
	while (++i < n - 1)
		ft_putchar(mid);
	if (i < n)
		ft_putchar(last);
	ft_putchar('\n');
}

void	rush(int x, int y)
{
	int	i;

	i = 0;
	if (i < y)
		ft_print_line(x, 'A', 'B', 'C');
	while (++i < y - 1)
		ft_print_line(x, 'B', ' ', 'B');
	if (i < y)
		ft_print_line(x, 'A', 'B', 'C');
}
