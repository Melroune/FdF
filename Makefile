# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: akerkeb <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/12/12 12:56:46 by akerkeb           #+#    #+#              #
#    Updated: 2014/12/13 00:24:55 by akerkeb          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME=fdf

SRC=main.c fdf.c print.c drawc.c get_next_line.c

FLAGS= -Wall -Wextra -Werror

OBJ=$(SRC:.c=.o)

INCLUDES= -I libft/includes

LIB= -L /usr/X11/lib -lmlx -lXext -lx11 -L libft -lft 

all:
	make -C libft
	gcc -c $(INCLUDES) $(SRC) 
	gcc -o $(NAME) $(OBJ) $(LIB)
clean:
	rm -rf $(OBJ)
fclean: clean
	rm -rf $(NAME)
re: fclean all
