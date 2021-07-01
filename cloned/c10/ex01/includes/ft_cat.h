#ifndef FT_CAT_H
# define FT_CAT_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <sys/errno.h>

# define BUFF_SIZE 20000

int	ft_cat(int fd, char *file, char *name);
int	ft_cat_stdin(char *name);
int	ft_print_error(char *file, char *name);

#endif
