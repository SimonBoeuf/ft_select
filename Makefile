CC			= gcc
NAME		= ft_select

INCLUDE		= ./includes/

SRC			= 	main.c list_fct.c put_fct.c str_fct.c sighandler_fct.c \
				keyhandler_fct.c cursor_fct.c term_fct.c divers_fct.c misc.c

CFLAGS		= -Wall -Werror -Wextra -ltermcap

all:		$(NAME)

$(NAME):
			$(CC) $(CFLAGS) -o $(NAME) -I $(INCLUDE) $(SRC)

clean:

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
