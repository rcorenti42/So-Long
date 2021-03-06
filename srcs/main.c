/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:07:43 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/28 02:05:37 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

int	destroy_all(t_mlx *mlx)
{
	int	i;

	i = 0;
	mlx_destroy_image(mlx->mlx_ptr, mlx->back.img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->collec.img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->door.img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->wall.img);
	mlx_destroy_image(mlx->mlx_ptr, mlx->player.img);
	mlx_destroy_window(mlx->mlx_ptr, mlx->mlx_win);
	while (i < mlx->height / TEXTURES_SIZE)
	{
		free(mlx->map[i]);
		i++;
	}
	free(mlx->map);
	exit(0);
	return (0);
}

static void	stock_xpm(t_mlx *mlx)
{
	mlx->back.img = mlx_xpm_file_to_image(mlx->mlx_ptr, BACK_PATH,
			&mlx->back.width, &mlx->back.height);
	mlx->back.img_ptr = mlx_get_data_addr(mlx->back.img, &mlx->back.bpp,
			&mlx->back.size_line, &mlx->back.endian);
	mlx->collec.img = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLEC_PATH,
			&mlx->collec.width, &mlx->collec.height);
	mlx->collec.img_ptr = mlx_get_data_addr(mlx->collec.img,
			&mlx->collec.bpp, &mlx->collec.size_line,
			&mlx->collec.endian);
	mlx->door.img = mlx_xpm_file_to_image(mlx->mlx_ptr, DOOR_PATH,
			&mlx->door.width, &mlx->door.height);
	mlx->door.img_ptr = mlx_get_data_addr(mlx->door.img, &mlx->door.bpp,
			&mlx->door.size_line, &mlx->door.endian);
	mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL_PATH,
			&mlx->wall.width, &mlx->wall.height);
	mlx->wall.img_ptr = mlx_get_data_addr(mlx->wall.img, &mlx->wall.bpp,
			&mlx->wall.size_line, &mlx->wall.endian);
	mlx->player.img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_PATH,
			&mlx->player.width, &mlx->player.height);
	mlx->player.img_ptr = mlx_get_data_addr(mlx->player.img,
			&mlx->player.bpp, &mlx->player.size_line,
			&mlx->player.endian);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	mlx.moves = 1;
	if (argc != 2)
	{
		printf("Error\nNot enough or too many arguments\n");
		return (0);
	}
	check_map(argv, &mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, mlx.width,
			mlx.height, "So Long !");
	stock_xpm(&mlx);
	so_long(&mlx);
	mlx_hook(mlx.mlx_win, 17, 1L << 17, &destroy_all, &mlx);
	mlx_hook(mlx.mlx_win, 2, 1L << 0, &ft_press, &mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
