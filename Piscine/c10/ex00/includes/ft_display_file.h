#ifndef FT_DISPLAY_FILE_H
# define FT_DISPLAY_FILE_H

# include <unistd.h>
# include <fcntl.h>

# define BUFF_SIZE 20000

int	ft_print_error(int code, char *str);
int	ft_print_file(int fd);

#endif
