/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:41:06 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/23 06:00:49 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "mlx.h"
# include "get_next_line.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define VALID_CHARS "01CEP"

# define BACK_PATH "../textures/background.xpm"
# define COLLEC_PATH "../textures/collectible.xpm"
# define DOOR_PATH "../textures/door.xpm"
# define WALL_PATH "../textures/wall.xpm"
# define PLAYER_PATH "../textures/player.xpm"

typedef struct	s_img {
	void	*img;
	char	*img_ptr;
	int	width;
	int	height;
	int	bpp;
	int	size_line;
	int	endian;
}		t_img;

typedef struct	s_mlx {
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	int	event;
	int	sqrt_size;
	int	width;
	int	height;
	int	moves;
	t_img	back;
	t_img	collec;
	t_img	door;
	t_img	wall;
	t_img	player;
}		t_mlx;

void	check_map(char **argv, t_mlx *mlx);
void	ft_error(char *str);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strcpy(char *dest, char *src);

#endif
