int ft_check_line_left(int line, int col, int **tab, int size, int *input)
{
	int	i;
	int	max;
	int	vis;

	i = 0;
	max = 0;
	vis = 0;
	while (i < col)
		if (tab[line][i++] > max)
			vis += 1;
	if (vis <= input[size * 2 + line])
		return (1);
	return (0);
}

int ft_check_line_right(int line, int col, int **tab, int size, int *input)
{
    int i;
    int max;
    int vis;

    i = col;
    max = 0;
    vis = 0;
    while (i >= 0)
        if (tab[line][i--] > max)
            vis += 1;
    if (vis == input[size * 3 + line])
        return (1);
    return (0);
}

int ft_check_col_up(int line, int col, int **tab, int size, int *input)
{
    int i;
    int max;
    int vis;

    i = 0;
    max = 0;
    vis = 0;
    while (i < line)
        if (tab[i++][col] > max)
            vis += 1;
    if (vis <= input[size * 0 + col])
        return (1);
    return (0);
}

int ft_check_col_right(int line, int col, int **tab, int size, int *input)
{
    int i;
    int max;
    int vis;

    i = line;
    max = 0;
    vis = 0;
    while (i >= 0)
        if (tab[i--][col] > max)
            vis += 1;
    if (vis <= input[size + col])
        return (1);
    return (0);
}
