/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/18 06:07:43 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/22 23:21:22 by rcorenti         ###   ########.fr       */
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

void	chars_valid(t_mlx *mlx)
{
	int	i;
	int	j;
	int	k;
	int	valid;

	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			k = 0;
			valid = 0;
			while (VALID_CHARS[k])
			{
				if (mlx->map[i][j] == VALID_CHARS[k])
					valid++;
				k++;
			}
			if (!valid)
				ft_error("Invalid Char Map");
			j++;
		}
		i++;
	}
}

void	chars_minimum(t_mlx *mlx)
{
	int	C;
	int	E;
	int	P;
	int	i;
	int	j;

	C = 0;
	E = 0;
	P = 0;
	i = 0;
	while (mlx->map[i])
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'C')
				C++;
			else if (mlx->map[i][j] == 'E')
				E++;
			else if (mlx->map[i][j] == 'P')
				P++;
			j++;
		}
		i++;
	}
	if (!C || !E || P != 1)
		ft_error("Miss Char Type Map Or Too Much Players");
}

void	check_walls(t_mlx *mlx, int line, int col)
{
	int	i;

	i = 0;
	while (mlx->map[0][i])
	{
		if (mlx->map[0][i] != '1')
			ft_error("Map Wall Error");
		i++;
	}
	i = 0;
	while (mlx->map[line - 1][i])
	{
		if (mlx->map[line - 1][i] != '1')
			ft_error("Map Wall Error");
		i++;
	}
	i = 1;
	while (i < line - 1)
	{
		if (mlx->map[i][0] != '1' || mlx->map[i][col - 1] != '1')
			ft_error("Map wall Error");
		i++;
	}
}

void	ft_error(char *str)
{
	printf("Error\n%s\n", str);
	exit(EXIT_FAILURE);
}

void	malloc_map(t_mlx *mlx, int line, int col, char *file)
{
	int	fd;
	int	i;
	int	buff;

	i = 0;
	buff = col;
	mlx->map = (char **)malloc(sizeof(char *) * col);
	if (!mlx->map)
		ft_error("malloc error");
	while (buff)
	{
		mlx->map[i] = (char *)malloc(sizeof(char) * line);
		buff--;
		i++;
	}
	i = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("File Error");
	while (get_next_line(fd, &mlx->map[i]))
		i++;
}

int	check_map(char **argv, t_mlx *mlx)
{
	int		fd;
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = -1;
	fd = open(argv[1], O_RDONLY);
	if (!fd)
		ft_error("File Error");
	while (get_next_line(fd, &buff))
	{
		if (j != -1 && j != ft_strlen(buff))
			ft_error("Invalid Map Size");
		j = ft_strlen(buff);
		i++;
	}
	close(fd);
	malloc_map(mlx, i, j, argv[1]);
	chars_valid(mlx);
	chars_minimum(mlx);
	check_walls(mlx, i, j);
	return (1);
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
        mlx.img_ptr = mlx_new_image(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT);
	mlx.img = mlx_get_data_addr(mlx.img_ptr, &mlx.bpp,
                        &mlx.size_line, &mlx.endian);

	pixel_put(&mlx, 5, 5, 0x00FF0000);
	mlx_put_image_to_window(mlx.mlx_ptr, mlx.mlx_win, mlx.img_ptr, 0, 0);

	//so_long(mlx);
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
