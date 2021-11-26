/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:41:06 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/26 09:04:14 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "mlx.h"
# include "get_next_line.h"

# define VALID_CHARS "01CEP"
# define TEXTURES_SIZE 64

# define BACK_PATH "textures/background.xpm"
# define COLLEC_PATH "textures/collectible.xpm"
# define DOOR_PATH "textures/door.xpm"
# define WALL_PATH "textures/wall.xpm"
# define PLAYER_PATH "textures/player.xpm"

typedef struct s_img {
	void	*img;
	char	*img_ptr;
	int		width;
	int		height;
	int		bpp;
	int		size_line;
	int		endian;
}		t_img;

typedef struct s_mlx {
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	int		event;
	int		width;
	int		height;
	int		moves;
	int		pos_x;
	int		pos_y;
	t_img	back;
	t_img	collec;
	t_img	door;
	t_img	wall;
	t_img	player;
	t_img	screen;
}		t_mlx;

void	check_map(char **argv, t_mlx *mlx);
void	ft_error(char *str);
char	*ft_strcpy(char *dest, char *src);
size_t		ft_strlen(const char *str);
int		ft_press(int key, t_mlx *mlx);
void	so_long(t_mlx *mlx);
int		ft_strncmp_inv(char *s1, char *s2, int n);
void	malloc_map(t_mlx *mlx, int line, int col, char *file);
int		destroy_all(t_mlx *mlx);

#endif
