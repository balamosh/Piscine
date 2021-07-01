#include "ft_display_file.h"

int	main(int ac, char **av)
{
	int	fd;
	int	ret;

	if (ac == 1)
		return (ft_print_error(1, "File name missing.\n"));
	if (ac > 2)
		return (ft_print_error(2, "Too many arguments.\n"));
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		return (ft_print_error(3, "Cannot read file.\n"));
	ret = ft_print_file(fd);
	close(fd);
	return (ret);
}
