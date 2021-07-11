NAME = minishell

SRCS = main.c get_next_line.c get_next_line_utils.c init_env.c help_function.c parser.c redirect.c \
redirect2.c quotes.c quotes2.c env.c check_correct_row.c help_function2.c env2.c execute_pipes.c \
command_exit.c command_cd.c command_pwd.c command_export.c command_env.c command_unset.c command_echo.c parser2.c\
run_bin.c find_path.c errors.c run_redirect.c help_function3.c


OBJS = $(SRCS:.c=.o)

CFLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OBJS)
	@gcc -g $(SRCS) libft/libft.a -o minishell

clean:
	/bin/rm -f *.o

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all
