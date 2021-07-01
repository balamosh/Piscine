SRC_DIR		:= ./srcs/
SRC_FILES	:=	ft_print_error.c \
				ft_putchar.c \
				ft_putstr.c \
				ft_strlen.c	\
				ft_strcmp.c	\
				ft_strcpy.c \
				ft_strdup.c \
				ft_ischar.c \
				ft_max.c \
				ft_create_elem.c \
				ft_list_find.c \
				ft_list_foreach.c \
				ft_list_push_front.c \
				ft_list_push_back.c \
				ft_list_clear.c \
				ft_free_dict.c \
				ft_fill_dict_elem.c \
				ft_dict_extract.c \
				ft_parse_dict.c
SRC_PROG	= $(SRC_DIR)test_parse.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS		= $(SRCS:.c=.o)

HEAD		:= includes/

LIB			= $(SRC_DIR)libft.a

NAME		:= rush-02

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

RM			:= rm -f

all				: obj $(NAME)

obj				: $(SRCS)

$(SRC_DIR)%.o 	: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(NAME)			: $(LIB)
	@$(CC) $(CFLAGS) $(SRC_PROG) -o $(NAME) $< -I $(HEAD)

$(LIB)			: $(OBJS)
	@ar rc $(LIB) $(OBJS)
	@ranlib $(LIB)

clean			:
	@$(RM) $(OBJS)
	@$(RM) $(LIB)

fclean			: clean
	@$(RM) $(NAME)

re				: fclean all

norm			:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckForbiddenSourceHeader $(SRC_PROG)
	@norminette -R CheckDefine $(HEAD)*

.PHONY 			: all obj clean fclean re norm
