# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/11/17 01:30:16 by rcorenti          #+#    #+#              #
#    Updated: 2021/11/17 03:31:47 by rcorenti         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #


NAME = so_long

CC = gcc

FLAGS = #-Wall -Wextra -Werror

HEADER = -I includes -I ${MLX}

srcs =	so_long.c\
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
