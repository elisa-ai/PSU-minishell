##
## EPITECH PROJECT, 2026
## Makefile
## File description:
## bootstrap minishell1
##


SRC     =   src/main.c \
			src/parsing.c \
			builtins/exit.c \
			lib/my_strcmp.c \
			lib/my_putchar.c \
			lib/my_putstr.c \
			lib/my_strlen.c \
			lib/my_strdup.c \
			lib/my_strncmp.c \
			builtins/env.c \
			lib/my_strcpy.c \
			src/path.c \
			lib/my_strcat.c \
			src/handle_signal.c \
			lib/mini_printf.c \
			lib/my_put_nbr.c \
			builtins/setenv.c \
			builtins/cd.c \
			builtins/unsetenv.c \
			lib/is_alphanum.c \
			lib/my_isalpha.c \
			lib/my_isnum.c \

OBJ     =   $(SRC:.c=.o)

NAME    =   mysh

all:
	clang -o $(NAME) $(SRC) -Wall -Werror -Wextra

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -f ~*

re:	fclean all
