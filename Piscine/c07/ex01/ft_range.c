#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	i;
	int	*range;

	if (min >= max)
		return (NULL);
	range = (int *) malloc(sizeof(int) * (max - min));
	if (NULL == range)
		return (NULL);
	i = 0;
	while (i < max - min)
	{
		range[i] = min + i;
		i += 1;
	}
	return (range);
}
