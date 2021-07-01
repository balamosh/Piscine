#include <stdlib.h>

int	ft_ultimate_range(int **range, int min, int max)
{
	int	i;

	if (NULL == range)
		return (-1);
	*range = NULL;
	if (min >= max)
		return (0);
	*range = (int *) malloc(sizeof(int) * (max - min));
	if (NULL == *range)
		return (-1);
	i = 0;
	while (i < max - min)
	{
		(*range)[i] = min + i;
		i += 1;
	}
	return (max - min);
}
