#include <stdio.h>

int	ft_is_sort(int *tab, int length, int(*f)(int, int))
{
	int	i;
	int	sort;

	i = -1;
	while (++i < length - 1)
		printf("- %d - , ", i);
	i = -1;
	sort = 1;
	while (++i < length - 1)
		if ((*f)(tab[i], tab[i + 1]) > 0)
			sort = 0;
	if (sort)
		return (1);
	i = -1;
	sort = 1;
	while (++i < length - 1)
		if ((*f)(tab[i], tab[i + 1]) < 0)
			sort = 0;
	if (sort)
		return (1);
	return (0);
}
