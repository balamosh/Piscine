SRC_DIR		:= ./srcs/
SRC_FILES	:= ft_putchar.c \
			  ft_putstr.c \
			  ft_print_error.c \
			  ft_print_file.c
SRC_PROG	= $(SRC_DIR)main.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS		= $(SRCS:.c=.o)

HEAD		:= includes/

LIB			= $(SRC_DIR)libft.a

NAME		:= ft_display_file

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

RM			:= rm -f

all				: obj $(NAME)

obj				: $(SRCS)

$(SRC_DIR)%.o 	: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(NAME)			: $(LIB)
	$(CC) $(CFLAGS) $(SRC_PROG) -o $(NAME) $< -I $(HEAD)

$(LIB)			: $(OBJS)
	ar rc $(LIB) $(OBJS)
	ranlib $(LIB)

clean			:
	$(RM) $(OBJS)
	$(RM) $(LIB)

fclean			: clean
	$(RM) $(NAME)

re				: fclean all

norm			:
	@norminette -R CheckForbiddenSourceHeader $(SRCS)
	@norminette -R CheckForbiddenSourceHeader $(SRC_PROG)
	@norminette -R CheckDefine $(HEAD)*

.PHONY 			: all obj clean fclean re norm
