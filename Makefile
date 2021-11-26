# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 01:30:16 by rcorenti          #+#    #+#              #
#    Updated: 2021/11/26 08:21:31 by rcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc

FLAGS = -g3 # -Wall -Wextra -Werror -g3

HEADER = -I includes -I ${MLX}

srcs =	main.c\
	so_long.c\
	parser.c\
	game.c\
	utils.c\
	get_next_line.c\
	get_next_line_utils.c

OBJS = ${addprefix srcs/,${srcs:.c=.o}}

MLX = minilibx-linux

MLXFLAGS = -L ${MLX}/ -lmlx -lXext -lX11

.c.o :
	${CC} ${FLAGS} ${HEADER} -c $< -o ${<:.c=.o}

all: $(NAME)

$(NAME): $(OBJS) ${MLX}/libmlx.a
	${CC} ${FLAGS} ${OBJS} ${MLXFLAGS} -o ${NAME}

${MLX}/libmlx.a:
	make -C ${MLX} all

clean:
	rm -f $(OBJS)
	make -C ${MLX} clean

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re
