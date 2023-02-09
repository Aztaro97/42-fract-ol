# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yonamog2 <yonamog2@student.42abudhabi.a    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/13 08:07:28 by yonamog2          #+#    #+#              #
#    Updated: 2022/11/15 05:59:29 by yonamog2         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fractal

FILES = mandelbrot.c main.c julia.c exit.c draw.c event.c event2.c event3.c ft_atof.c burning_ship.c messages.c

OBJ = $(FILES:.c=.o)

CC = gcc 

CFLAGS = -Wall -Werror -Wextra

all : $(NAME)

$(NAME): $(OBJ)
	cd ft_printf && make
	$(CC) $(OBJ) ./ft_printf/libft.a -Lmlx -lm -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean: 
	cd ft_printf && make clean
	rm -f $(OBJ)

fclean: clean
	cd ft_printf && make fclean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re