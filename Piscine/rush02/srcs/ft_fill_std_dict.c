#include "ft.h"

static void	ft_fill_std_dict_len(void);

static void	ft_fill_std_dict_values(void);

void	ft_fill_std_dict(void)
{
	int		fd;
	char	buff;

	fd = open(STD_DICT, O_RDONLY);
	rd = read(fd, &buff, 1);
	ft_fill_std_dict_len();
	ft_fill_std_dict_values();
}
