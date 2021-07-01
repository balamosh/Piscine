#ifndef FT_TAIL_H
# define FT_TAIL_H

# include <unistd.h>
# include <fcntl.h>
# include <string.h>
# include <libgen.h>
# include <sys/errno.h>

# define BUFF_SIZE 20000

typedef struct s_file
{
	int		fd;
	char	*filename;
}				t_file;

int		ft_tail_stdin(char *name, int n);
int		ft_print_error(char *file, char *name, int head);
void	ft_print_head(char *file, int head);
int		ft_head_type(int i, int ac, int start);
int		ft_tail_check_flags(char *name, char *flag, char *nbr, int *n);

int		ft_tail_malloc(t_file file, char *name, int n, int head);

char	*ft_strdup_last(char *str, int n);
char	*ft_strjoin(char *s1, char *s2);
char	*ft_append_tail(char *tail, char *buff, int rd, int n);

#endif
