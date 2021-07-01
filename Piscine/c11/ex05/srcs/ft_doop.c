#include "ft.h"

int	ft_opid(char *op)
{
	if (ft_strcmp(op, "+") == 0)
		return (0);
	if (ft_strcmp(op, "-") == 0)
		return (1);
	if (ft_strcmp(op, "/") == 0)
		return (2);
	if (ft_strcmp(op, "*") == 0)
		return (3);
	if (ft_strcmp(op, "%") == 0)
		return (4);
	return (-1);
}

int	ft_doop(char *val1, char *op, char *val2)
{
	int	v1;
	int	v2;
	int	(*op_ptr[5])(int, int);

	op_ptr[0] = ft_add;
	op_ptr[1] = ft_sub;
	op_ptr[2] = ft_div;
	op_ptr[3] = ft_mul;
	op_ptr[4] = ft_mod;
	if (ft_opid(op) < 0)
		return (ft_print_error(1, "0\n"));
	v1 = ft_atoi(val1);
	v2 = ft_atoi(val2);
	(*op_ptr[ft_opid(op)])(v1, v2);
	return (0);
}
