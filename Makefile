# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mabdulla <dj.ali9292@gmail.com>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/09/08 10:50:00 by mabdulla          #+#    #+#              #
#    Updated: 2022/10/06 14:10:58 by mabdulla         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CFLAGS = -Wall -Wextra -Werror -I./MiniLibX
LFLAGS = -framework AppKit -framework OpenGL -L./MiniLibX -lmlx

MLX = ./MiniLibX/libmlx.a
GNL = $(wildcard get_next_line/*c)
GNLOBJS = $(GNL:.c=.o)

SRCS = $(wildcard ./*c)
OBJS = $(SRCS:.c=.o)


all : $(MLX) $(NAME)

$(MLX) :
	make -C ./Libft
	make -C ./ft_printf
	make -C ./MiniLibX

$(NAME) : $(OBJS) $(GNLOBJS)
	gcc $(OBJS) $(GNLOBJS) $(LFLAGS) ./Libft/libft.a ./ft_printf/libftprintf.a -o $(NAME)

.c.o:
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJS) $(NAME)
	make clean -C ./libft
	make clean -C ./ft_printf

fclean:
	rm -rf $(OBJS) $(NAME)
	rm -rf ./get_next_line/*.o
	make clean -C ./MiniLibX
	make fclean -C ./libft
	make fclean -C ./ft_printf

re : fclean all

.PHONY: clean fclean re