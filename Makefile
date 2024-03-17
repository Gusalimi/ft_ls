# ======= FILES ========
NAME		= ft_ls
OBJDIR		= .objFiles
FILES		= main parsing get_entries error
SRCS		= $(addprefix srcs/, $(FILES:=.cpp))
OBJS		= $(addprefix $(OBJDIR)/, $(SRCS:.cpp=.o))
LIBFT		= libft/libft.a

# ======= COMPILATION ========
CC		= gcc
CFLAGS	= -Wall -Wextra -Werror
INCLUDE	= -I libft -I includes
RM		= rm -rf


#Colors:
GREEN		=	\e[92;5;118m
YELLOW		=	\e[93;5;226m
GRAY		=	\e[33;2;37m
RESET		=	\e[0m
CURSIVE		=	\e[33;3m

#Debug 
ifeq ($(DEBUG), 1)
   OPTS = -g3 -fsanitize=address
endif

.PHONY: all clean fclean re bonus norm

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	@$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(OPTS) -o $(NAME)
	@printf "$(CURSIVE)$(GREEN)- Executable ready.\n$(RESET)"
	@$(MAKE) clean

$(OBJDIR)/%.o: %.c
	@mkdir -p $(dir $@)
	@$(CC) $(CFLAGS) $(OPTS) $(INCLUDE) -c $< -o $@

$(LIBFT):
	@make -C libft
	@printf "$(CURSIVE)$(GREEN)- Libft.a ready.$(RESET)\n"

clean:
	@$(RM) $(OBJDIR)
	@make -C libft clean
	@printf "$(CURSIVE)$(GRAY)- Object files removed.$(RESET)\n"

fclean: clean
	@$(RM) $(NAME) *.dSYM
	@make -C libft fclean
	@printf "$(CURSIVE)$(GRAY)- Executable removed.$(RESET)\n"

re: fclean all