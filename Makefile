MAKEFLAGS += -s

CC = cc -g

CFLAGS = -Wall -Wextra -Werror
LIBS = -lreadline -lhistory

#CFLAGS += -fsanitize=thread
#CFLAGS += -fsanitize=address

NAME = minishell

SRCS = main.c tester.c syntax.c utils.c utils2.c utils3.c token_utils.c ft_quotes_split.c free_funcs.c \
	type_check.c syntax2.c expand.c build_commands.c create_env.c redirections.c heredoc.c \
	heredoc_utils.c utils4.c utilc5.c tokens.c fds_signals.c execute_utils.c fds_signals_utils.c \
	minihell/ft_pwd.c minihell/ft_echo.c\
	minihell/ft_built_in.c minihell/ft_cd.c\
	minihell/ft_env.c minihell/ft_built_errors.c \
	minihell/ft_execute_m.c minihell/ft_execute.c \
	minihell/utils.c minihell/ft_unset.c minihell/ft_export.c \
	minihell/ft_export_utils.c minihell/ft_pipes.c minihell/ft_exit.c minihell/utils2.c


LIBFT = ./libft/libft.a
PRINTF = ./libft/ft_printf/ft_printf.a

#BONUS_SRCS =

OBJS = $(SRCS:.c=.o)

all: $(LIBFT) $(PRINTF) $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME) $(LIBFT) $(PRINTF) -lreadline -o $(NAME)
#bonus: $(BONUS_OBJS) $(OBJS)
#	ar rc $(NAME) $(BONUS_OBJS) $(OBJS)  mete no clean -> $(BONUS_OBJS)

valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --suppressions=readline.supp --leak-check=full ./minishell

clean:
	rm -rf $(OBJS)
	@echo "$(YELLOW)Removing $(NAME) and libft objects files$(RESET)"
	 cd libft && make clean
	 cd libft/ft_printf && make clean

fclean: clean
	rm -rf $(NAME)

re: fclean all

.phony: all bonus clean fclean re

################################# Making librarys #########################
$(LIBFT):
	cd libft && cd libft && make

$(PRINTF):
	cd libft/ft_printf && make



############################## Checking norm and Funcs #####################

PERMITTED_FUNCTIONS    = readline rl_clear_history rl_on_new_line \
                         rl_replace_line rl_redisplay add_history printf \
                         malloc free write access open read close fork wait \
                         waitpid wait3 wait4 signal sigaction sigemptyset \
                         sigaddset kill exit getcwd chdir stat lstat fstat \
                         unlink execve dup dup2 pipe opendir readdir \
                         closedir strerror perror isatty ttyname ttyslot \
                         ioctl getenv tcsetattr tcgetattr tgetent tgetflag \
                         tgetnum tgetstr tgoto tputs

check: all


