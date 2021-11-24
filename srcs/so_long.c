/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:14:48 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/24 06:02:24 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	add_background(t_mlx *mlx, t_img *screen)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->height)
	{
		j = 0;
		while (j < mlx->width)
		{
			((int *)screen->img_ptr)[j + i * screen->size_line / 4]
				= ((int *)mlx->back.img_ptr)[j % TEXTURES_SIZE
				+ i % TEXTURES_SIZE * mlx->back.size_line / 4];
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
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, screen.img, 0, 0);
}
