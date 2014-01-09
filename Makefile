CC			= gcc

NAME		= ft_select

INCLUDE		= ./includes/

SRCS		= 	main.c				\
				list_fct.c			\
				put_fct.c			\
				str_fct.c			\
				sighandler_fct.c	\
				keyhandler_fct.c	\
				cursor_fct.c		\
				term_fct.c			\
				divers_fct.c		\
				misc.c 				\
				arrow_fct.c			\
				effect_fct.c		\
				keycheck_fct.c		\
				elem_fct.c

OBJS		= $(SRCS:.c=.o)

CFLAGS		= -Wall -Werror -Wextra

LFLAGS		= -ltermcap

all:		$(NAME)

%.o:		%.c
			$(CC) $(CFLAGS) -c $^ -I $(INCLUDE)

$(NAME):	$(OBJS)
			$(CC) $(CFLAGS) -o $(NAME) $(OBJS) $(LFLAGS)

clean:
			rm -rf $(OBJS)

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
