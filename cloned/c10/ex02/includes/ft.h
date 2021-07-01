#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>

void	ft_putchar(char c);
void	ft_putstr(char *str);
void	ft_putstr_error(char *str);
int		ft_strcmp(char *s1, char *s2);
int		ft_strlen(char *str);
char	*ft_strcpy(char *dest, char *src);

int		ft_max(int a, int b);
int		ft_atoi(char *str);

#endif
