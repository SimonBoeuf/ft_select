CC			= gcc
NAME		= ft_select

SRC			= 	main.c list_fct.c put_fct.c str_fct.c sighandler_fct.c \
				error_fct.c keyhandler_fct.c cursor_fct.c

CFLAGS		= -Wall -Werror -Wextra -ltermcap

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) -o $(NAME) -I. $(SRC)

clean:

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
