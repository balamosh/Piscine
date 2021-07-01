int ft_check_line_left_ex(int line, int **tab, int size, int *input)
{
	int	i;
	int	max;
	int	vis;

	i = 0;
	max = 0;
	vis = 0;
	while (i < size)
		if (tab[line][i++] > max)
			vis += 1;
	if (vis == input[size * 2 + line])
		return (1);
	return (0);
}

int ft_check_line_right_ex(int line, int **tab, int size, int *input)
{
    int i;
    int max;
    int vis;

    i = size - 1;
    max = 0;
    vis = 0;
    while (i >= 0)
        if (tab[line][i--] > max)
            vis += 1;
    if (vis == input[size * 3 + line])
        return (1);
    return (0);
}

int ft_check_col_up_ex(int col, int **tab, int size, int *input)
{
    int i;
    int max;
    int vis;

    i = 0;
    max = 0;
    vis = 0;
    while (i < size)
        if (tab[i++][col] > max)
            vis += 1;
    if (vis == input[col])
        return (1);
    return (0);
}

int ft_check_col_right(int col, int **tab, int size, int *input)
{
    int i;
    int max;
    int vis;

    i = size - 1;
    max = 0;
    vis = 0;
    while (i >= 0)
        if (tab[i--][col] > max)
            vis += 1;
    if (vis == input[size + col])
        return (1);
    return (0);
}

int	ft_check_solutions(int **tab, int size, int *input)
{
	int	i;

	i = 0;
	while (i < size)
		if(!ft_check_line_left_ex(i, tab, size, input) ||
			!ft_check_line_right_ex(i, tab, size, input))
			return (0);
	i = 0;
	while (i < size)
		if(!ft_check_col_up_ex(i, tab, size, input) ||
            !ft_check_col_up_ex(i, tab, size, input))
            return (0);
	return (1);
}
