/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:07:43 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/23 04:25:31 by rcorenti         ###   ########.fr       */
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

void	pixel_put(t_mlx *mlx, int x, int y, int color)
{
	char	*dst;

	dst = mlx->img + (y * mlx->size_line + x * (mlx->bpp / 8));
	*(unsigned int *)dst = color;
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
	so_long(mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
                                                         
