SRCS		= $(wildcard *.c) $(wildcard */*.c)
NAME		= libft.a
OBJS		= $(SRCS:.c=.o)
CC			= gcc
RM			= rm -f
CFLAGS		= -Wall -Wextra -Werror
INC			= .

.c.o:
	@$(CC) $(CFLAGS) -I $(INC) -c $< -o $(<:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
	@ar rc $(NAME) $(OBJS)
	@ranlib $(NAME)

clean:
	@$(RM) $(OBJS) $(BONUS_OBJS)

fclean:		clean
	@$(RM) $(NAME)

re:			fclean all

.PHONY:		all clean fclean re bonus
