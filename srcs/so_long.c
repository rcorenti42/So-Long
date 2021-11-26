/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:14:48 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/26 05:51:48 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_texture(t_img *screen, t_img *texture, int x, int y)
{
	int	i;
	int	j;

	i = 0;
	while (i < TEXTURES_SIZE)
	{
		j = 0;
		while (j < TEXTURES_SIZE)
		{
			if (((int *)texture->img_ptr)[i + j * texture->size_line / 4]
				!= -16777216)
				((int *)screen->img_ptr)[(x * TEXTURES_SIZE + i)
					+ (y * TEXTURES_SIZE + j) * screen->size_line / 4]
					= ((int *)texture->img_ptr)[i + j * texture->size_line / 4];
			j++;
		}
		i++;
	}
}

void	add_textures(t_mlx *mlx)
{
	int	i;
	int	j;

	i = 0;
	while (i < mlx->height / TEXTURES_SIZE)
	{
		j = 0;
		while (mlx->map[i][j])
		{
			put_texture(&mlx->screen, &mlx->back, j, i);
			if (mlx->map[i][j] == '1')
				put_texture(&mlx->screen, &mlx->wall, j, i);
			if (mlx->map[i][j] == 'C')
				put_texture(&mlx->screen, &mlx->collec, j, i);
			if (mlx->map[i][j] == 'E')
				put_texture(&mlx->screen, &mlx->door, j, i);
			put_texture(&mlx->screen, &mlx->player, mlx->pos_x, mlx->pos_y);
			j++;
		}
		i++;
	}
}

void	so_long(t_mlx *mlx)
{
	mlx->screen.img = mlx_new_image(mlx->mlx_ptr, mlx->width, mlx->height);
	mlx->screen.img_ptr = mlx_get_data_addr(mlx->screen.img, &mlx->screen.bpp,
			&mlx->screen.size_line, &mlx->screen.endian);
	add_textures(mlx);
	mlx_put_image_to_window(mlx->mlx_ptr, mlx->mlx_win, mlx->screen.img, 0, 0);
	mlx_destroy_image(mlx->mlx_ptr, mlx->screen.img);
}
