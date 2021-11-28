/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 03:28:37 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/28 02:05:14 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	collisions(t_mlx *mlx, int end_x, int end_y)
{
	if (mlx->map[end_y][end_x] != '1')
	{
		mlx->pos_x = end_x;
		mlx->pos_y = end_y;
		printf("current number of movements : %d\n", mlx->moves);
		mlx->moves++;
	}
}

static void	ft_out(t_mlx *mlx)
{
	int	i;
	int	j;
	int	key;

	key = 0;
	i = 0;
	while (i < mlx->height / TEXTURES_SIZE)
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				key++;
			j++;
		}
		i++;
	}
	if (!key)
		destroy_all(mlx);
}

int	ft_press(int key, t_mlx *mlx)
{
	if (key == 65307)
		destroy_all(mlx);
	if (key == 119)
		collisions(mlx, mlx->pos_x, mlx->pos_y - 1);
	if (key == 115)
		collisions(mlx, mlx->pos_x, mlx->pos_y + 1);
	if (key == 97)
		collisions(mlx, mlx->pos_x - 1, mlx->pos_y);
	if (key == 100)
		collisions(mlx, mlx->pos_x + 1, mlx->pos_y);
	if (mlx->map[mlx->pos_y][mlx->pos_x] == 'C')
		mlx->map[mlx->pos_y][mlx->pos_x] = '0';
	if (mlx->map[mlx->pos_y][mlx->pos_x] == 'E')
		ft_out(mlx);
	so_long(mlx);
	return (key);
}
