#include "libft.h"
#include <stdio.h>

int	main()
{
	int		a;
	int		b;
	char	str1[] = "str1";
	char	str2[] = "str2";

	a = 42;
	b = 21;
	ft_putstr("Testing my libft\n");
	printf("a = %d, b = %d\n", a, b);
	ft_putstr("SWAP a and b\n");
	ft_swap(&a, &b);
	printf("a = %d, b = %d\n", a, b);
	ft_putchar('%');
	ft_putchar('\n');
	printf("len(\"%s\") = %d\n", str1, ft_strlen(str1));
	if (ft_strcmp(str1, str2) >= 0)
		printf("\"%s\" >= \"%s\"", str1, str2);
	else
		printf("\"%s\" < \"%s\"", str1, str2);
}
