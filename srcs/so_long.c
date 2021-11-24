/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:14:48 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/24 06:48:05 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_background(t_mlx *mlx, t_img *screen)
{
	int	x;
	int	y;

	y = 0;
	while (y < mlx->height)
	{
		x = 0;
		while (x < mlx->width)
		{
			((int *)screen->img_ptr)[x + y * screen->size_line / 4]
				= ((int *)mlx->back.img_ptr)[x % TEXTURES_SIZE
				+ y % TEXTURES_SIZE * mlx->back.size_line / 4];
			x++;
		}
		y++;
	}
}

void	add_wall(t_mlx *mlx, t_img *screen)
{
	int	i;
	int	j;
	int	x;
	int	y;

	i = 0;
	while (i < mlx->height / TEXTURES_SIZE)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1')
			{
				y = 0;
				while (y < TEXTURES_SIZE)
				{
					x = 0;
					while (x < TEXTURES_SIZE)
					{
						
						x++;
					}
					y++;
				}
			}
			j++;
		}
		i++;
	}
}

void	so_long(t_mlx *mlx)
{
	t_img	screen;

	screen.img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	screen.img_ptr = mlx_get_data_addr(screen.img, &screen.bpp,
			&screen.size_line, &screen.endian);
	add_background(mlx, &screen);
	add_wall(mlx, &screen);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, screen.img, 0, 0);
}
