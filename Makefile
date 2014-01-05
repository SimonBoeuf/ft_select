# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 15:23:59 by lfouquet          #+#    #+#              #
#    Updated: 2014/01/05 17:00:22 by sboeuf           ###   ########.fr        #
# **************************************************************************** #

CC			= gcc
NAME		= ft_select

SRC			= 	main.c

CFLAGS		= -Wall -Werror -Wextra -ltermcap

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) -o $(NAME) $(SRC)

clean:

fclean:		clean
			rm -rf $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
