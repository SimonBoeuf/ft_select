# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfouquet <lfouquet@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/01/04 15:23:59 by lfouquet          #+#    #+#              #
#    Updated: 2014/01/05 16:39:53 by lfouquet         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC			= gcc
NAME		= ft_select

SRC			= 	main.c

OBJ			= $(SRC:.c=.o)

CFLAGS		= -Wall -Werror -Wextra -I. -ltermcap

all:		$(NAME)

$(NAME):	$(OBJ)
			$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

clean:
			rm -rf $(OBJ)

fclean:		clean
			rm -rf $(OBJ) $(NAME)

re:			fclean all

.PHONY:		all clean re fclean
