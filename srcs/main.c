/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:07:43 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/23 06:05:11 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	stock_xpm(t_mlx *mlx)
{
	mlx->back.img = mlx_xpm_file_to_image(mlx->mlx_ptr, BACK_PATH,
			&mlx->back.width, &mlx->back.height);
	mlx_get_data_addr(mlx->back.img, &mlx->back.bpp,
			&mlx->back.size_line, &mlx->back.endian);
        //mlx->collec.img = mlx_xpm_file_to_image(mlx->mlx_ptr, COLLEC_PATH,
        //                &mlx->collec.width, &mlx->collec.height);
        //mlx_get_data_addr(mlx->collec.img, &mlx->collec.bpp,
	//		&mlx->collec.size_line, &mlx->collec.endian);
        //mlx->door.img = mlx_xpm_file_to_image(mlx->mlx_ptr, DOOR_PATH,
	//		&mlx->door.width, &mlx->door.height);
        //mlx_get_data_addr(mlx->door.img, &mlx->door.bpp,
	//		&mlx->door.size_line, &mlx->door.endian);
        //mlx->wall.img = mlx_xpm_file_to_image(mlx->mlx_ptr, WALL_PATH,
	//		&mlx->wall.width, &mlx->wall.height);
        //mlx_get_data_addr(mlx->wall.img, &mlx->wall.bpp,
	//		&mlx->wall.size_line, &mlx->wall.endian);
        //mlx->player.img = mlx_xpm_file_to_image(mlx->mlx_ptr, PLAYER_PATH,
	//		&mlx->player.width, &mlx->player.height);
        //mlx_get_data_addr(mlx->player.img, &mlx->player.bpp,
	//		&mlx->player.size_line, &mlx->player.endian);
}

int	main(int argc, char **argv)
{
	t_mlx	mlx;

	if (argc != 2)
	{
		printf("Error\nNot enough or too many arguments\n");
		return (0);
	}
	check_map(argv, &mlx);
	mlx.mlx_ptr = mlx_init();
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH,
			WIN_HEIGHT, "So Long !");
	stock_xpm(&mlx);
	//so_long(&mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
