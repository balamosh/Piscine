#ifndef FT_HEAD_H
# define FT_HEAD_H

int		ft_print_error(int code);
int		ft_manage_input(int **input, char *str);
int		**ft_solve(int *input, int size);
void	ft_print_answer(int **answer, int size);

#endif
