# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ssachet <ssachet@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2015/01/22 22:35:15 by ssachet           #+#    #+#              #
#    Updated: 2015/02/22 11:20:23 by ssachet          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc
CFLAGS = -Wall -Wextra -Werror  -L/usr/X11/lib -lmlx -lXext -lX11
EXEC = fdf
MAIN = fdf.c
LIB = libft/libft.a

SRC= fdf.c assistant.c math.c hook.c tracing_calls.c
H = fdf.h libft/libft.h libft/get_next_line/get_next_line.h libft/printf/ft_printf.h
O = $(SRC:.c=.o)

all: allo

allo:
	make -C libft/
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(O) $(H) $(LIB)

clean:
	rm -rf $(O)

fclean: clean
	rm -rf $(EXEC)

re: fclean all

test:
	$(CC) -c $(CFLAGS) $(SRC)
	$(CC) $(CFLAGS) -o $(EXEC) $(O) $(H) $(LIB)

.PHONY: all allo clean fclean re test
