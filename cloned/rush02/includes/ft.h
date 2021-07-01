#ifndef FT_H
# define FT_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>

#include <stdio.h>

# define STD_DICT = "./data/numbers.dict"

typedef struct s_dict
{
	char			*nbr;
	char			*word;
	int				nbr_len;
	int				word_len;
}				t_dict;

typedef struct s_list
{
	struct s_list	*next;
	void			*data;
}				t_list;

/* STD FUNC */
void	ft_putchar(char c);
void	ft_putstr(char *str);
int		ft_strlen(char *str);
int		ft_strcmp(char *s1, char *s2);
char	*ft_strcpy(char *dest, char *str);
char	*ft_strncpy(char *dest, char *str, int n);
char	*ft_strdup(char *str);
char	*ft_strndup(char *str, int n);

int		ft_isspace(char c);
int		ft_isdigit(char c);
int		ft_isprintable(char c);

int		ft_max(int a, int b);

/* LIST FUNC */
t_list	*ft_create_elem(void *data);
void	ft_list_push_front(t_list **begin_list, void *data);
void	ft_list_push_back(t_list **begin_list, void *data);
void	ft_list_foreach(t_list *begin_list, void (*f)(void *));
t_list	*ft_list_find(t_list *begin_list, void *data_ref, int (*cmp)());
void	ft_list_clear(t_list *begin_list, void (*free_fct)(void *));

/* RUSH FUNC */
int		ft_print_error(int code, char *err);
void	ft_parse_dict(char *file, t_list **reg_nbrs, t_list **dec_nbrs);
t_dict	*ft_fill_dict_elem(char *nbr, char *word);
void	ft_free_dict(void *data);
char	*ft_dict_extract_nbr(char *str);
char	*ft_dict_extract_word(char *str);
char	*ft_typer(char *string, t_list *reg_nbrs, t_list *begin_fin, t_list *dec_nbrs);

#endif
