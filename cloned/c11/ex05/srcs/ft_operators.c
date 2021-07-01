#include "ft.h"

int	ft_add(int a, int b)
{
	ft_putnbr(a + b);
	ft_putchar('\n');
	return (a + b);
}

int	ft_sub(int a, int b)
{
	ft_putnbr(a - b);
	ft_putchar('\n');
	return (a - b);
}

int	ft_div(int a, int b)
{
	if (b == 0)
		return (ft_print_error(0, "Stop : division by zero\n"));
	ft_putnbr(a / b);
	ft_putchar('\n');
	return (a / b);
}

int	ft_mul(int a, int b)
{
	ft_putnbr(a * b);
	ft_putchar('\n');
	return (a * b);
}

int	ft_mod(int a, int b)
{
	if (b == 0)
		return (ft_print_error(0, "Stop : modulo by zero\n"));
	ft_putnbr(a % b);
	ft_putchar('\n');
	return (a % b);
}
