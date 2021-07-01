#include <stdlib.h>

int	*ft_map(int *tab, int length, int(*f)(int))
{
	int	i;
	int	*arr;

	arr = (int *) malloc(sizeof(int) * length);
	if (NULL == arr)
		return (NULL);
	i = 0;
	while (i < length)
	{
		arr[i] = (*f)(tab[i]);
		i += 1;
	}
	return (arr);
}
