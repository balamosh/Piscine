#include "ft.h"
#include "ft_tail.h"

int	ft_tail_stdin(char *name, int n)
{
	t_file	std_inp;

	std_inp.fd = 0;
	std_inp.filename = "";
	return (ft_tail_malloc(std_inp, name, n, 0));
}

char	*ft_append_tail(char *tail, char *buff, int rd, int n)
{
	char	*out;
	char	*tail_cp;

	if (NULL == tail || rd >= n)
	{
		free(tail);
		return (ft_strdup_last(buff, n));
	}
	tail_cp = ft_strdup_last(tail, n - rd);
	out = ft_strjoin(tail_cp, buff);
	free(tail);
	free(tail_cp);
	return (out);
}

int	ft_tail_malloc(t_file file, char *name, int n, int head)
{
	char	buff[BUFF_SIZE + 1];
	int		rd;
	char	*tail;

	if (file.fd == -1)
		return (ft_print_error(file.filename, name, head));
	rd = read(file.fd, buff, BUFF_SIZE);
	tail = NULL;
	while (rd > 0)
	{
		buff[rd] = '\0';
		tail = ft_append_tail(tail, buff, rd, n);
		if (NULL == tail)
			return (ft_print_error("malloc", name, 0));
		rd = read(file.fd, buff, BUFF_SIZE);
	}
	if (rd == -1)
		return (ft_print_error(file.filename, name, head));
	ft_print_head(file.filename, head);
	ft_putstr(tail);
	return (0);
}
