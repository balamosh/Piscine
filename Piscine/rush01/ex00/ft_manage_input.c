#include <stdlib.h>
#include "ft_char_check.h"

int	ft_count_digits(char *str)
{
	int	i;
	int	n;
	int	ch;

	i = 0;
	n = 0;
	ch = 1;
	while (str[i] != '\0')
	{
		if ((ch == 1) && !ft_isdigit(str[i]))
			return (0);
		if ((ch == -1) && !ft_isspace(str[i]))
			return (0);
		i += 1;
		if (ch == 1)
			n += 1;
		ch *= -1;
	}
	if (n % 4 || ch == 1)
		return (0);
	return (n);
}

int	*ft_str_to_arr(char *str, int n)
{
	int	i;
	int	*arr;

	i = 0;
	arr = (int *) malloc(sizeof(int) * n);
	if (NULL == arr)
		return (NULL);
	while (str[2 * i] != '\0' && i < n)
	{
		arr[i] = str[2 * i] - '0';
		i += 1;
	}
	return (arr);
}

int	ft_check_arr(int *arr, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		if (arr[i] < 1 || arr[i] > (n / 4))
			return (0);
		i += 1;
	}
	return (1);
}

int	ft_manage_input(int **input, char *str)
{
	int	n;
	int	*arr;

	n = ft_count_digits(str);
	*input = NULL;
	if (n == 0)
		return (0);
	arr = ft_str_to_arr(str, n);
	if (ft_check_arr(arr, n))
		*input = arr;
	return (n / 4);
}
