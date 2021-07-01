SRC_DIR		:= ./srcs/
SRC_FILES	:= ft_putchar.c \
			  ft_swap.c	\
			  ft_putstr.c \
			  ft_strlen.c \
			  ft_strcmp.c
SRCS		= $(addprefix $(SRC_DIR), $(SRC_FILES))

OBJS		= $(SRCS:.c=.o)

HEAD		:= -I includes/

NAME		:= libft.a

LIBCC		:= ar rc
LIBRAN		:= ranlib

CC			:= gcc
CFLAGS		:= -Wall -Wextra -Werror

RM			:= rm -f

all				: obj $(NAME)

obj				: $(SRCS)

$(SRC_DIR)%.o 	: $(SRC_DIR)%.c
	$(CC) $(CFLAGS) -c $< -o $@ $(HEAD)

$(NAME)			: $(OBJS)
	$(LIBCC) $@ $(OBJS)
	$(LIBRAN) $@

clean			:
	$(RM) $(OBJS)

fclean			: clean
	$(RM) $(NAME)

re				: fclean all

.PHONY 			: all clean fclean re
