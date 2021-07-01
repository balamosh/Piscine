#ifndef FT_H
# define FT_H

# include <unistd.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_atoi(char *str);
void	ft_putnbr(int nbr);

int		ft_print_error(int code, char *str);

int		ft_add(int a, int b);
int		ft_sub(int a, int b);
int		ft_div(int a, int b);
int		ft_mul(int a, int b);
int		ft_mod(int a, int b);

int		ft_doop(char *val1, char *op, char *val2);

#endif
