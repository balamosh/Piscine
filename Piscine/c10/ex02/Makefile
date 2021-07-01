SRC_DIR		= ./srcs/

SRC_FILES	= ft_putchar.c \
			  ft_putstr.c \
			  ft_strcmp.c \
			  ft_print_error.c \
			  ft_putstr_error.c \
			  ft_atoi.c \
			  ft_max.c \
			  ft_print_head.c \
			  ft_strdup_last.c \
			  ft_strjoin.c \
			  ft_strcpy.c \
			  ft_strlen.c \
			  ft_head_type.c \
			  ft_tail_check_flags.c \
			  ft_tail.c

HEAD		= includes/

SRC_PROG	= $(SRC_DIR)main.c

SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS		= $(SRCS:.c=.o)

LIB			= $(SRC_DIR)libft.a

NAME		= ft_tail

CC			= gcc
CFLAGS		= -Wall -Wextra -Werror

RM			= rm -f

all				: obj $(NAME)

obj				: $(OBJS)

$(SRC_DIR)%.o 	: $(SRC_DIR)%.c
	@$(CC) $(CFLAGS) -c $< -o $@ -I $(HEAD)

$(NAME)			: $(LIB)
	@$(CC) $(CFLAGS) $(SRC_PROG) -o $(NAME) $(LIB) -I $(HEAD)

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
