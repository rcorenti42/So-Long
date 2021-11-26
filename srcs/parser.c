/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:03:10 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/26 08:43:34 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	parse_player(t_mlx *mlx)
{
	int	i;
	int	j;
	int	p;

	p = 0;
	i = 0;
	while (i < mlx->height / TEXTURES_SIZE)
	{
		j = 0;
		while (mlx->map[i][j])
		{
			if (mlx->map[i][j] == 'P')
			{
				mlx->pos_x = j;
				mlx->pos_y = i;
				mlx->map[i][j] = '0';
				p++;
			}
			j++;
		}
		i++;
	}
}

void	check_walls(t_mlx *mlx, int col, int line)
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
	parse_player(mlx);
}

void	chars_minimum(t_mlx *mlx)
{
	int	c;
	int	e;
	int	p;
	int	i;
	int	j;

	c = 0;
	e = 0;
	p = 0;
	i = -1;
	while (++i < mlx->height / TEXTURES_SIZE)
	{
		j = -1;
		while (mlx->map[i][++j])
		{
			if (mlx->map[i][j] == 'C')
				c++;
			else if (mlx->map[i][j] == 'E')
				e++;
			else if (mlx->map[i][j] == 'P')
				p++;
		}
	}
	if (!c || !e || p != 1)
		ft_error("Miss Char Type Map Or Too Much Players");
}

void	chars_valid(t_mlx *mlx)
{
	int	i;
	int	j;
	int	k;
	int	valid;

	i = -1;
	while (++i < mlx->height / TEXTURES_SIZE)
	{
		j = -1;
		while (mlx->map[i][++j])
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
		}
	}
	chars_minimum(mlx);
	check_walls(mlx, mlx->width / TEXTURES_SIZE, mlx->height / TEXTURES_SIZE);
}

void	check_map(char **argv, t_mlx *mlx)
{
	int		fd;
	int		i;
	int		j;
	char	*buff;

	i = 0;
	j = -1;
	ft_strncmp_inv(argv[1], ".ber", 4);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_error("File Error");
	while (get_next_line(fd, &buff))
	{
		if (j != -1 && j != (int)ft_strlen(buff))
			ft_error("Invalid Map Size");
		j = ft_strlen(buff);
		free(buff);
		i++;
	}
	free(buff);
	close(fd);
	mlx->height = i * TEXTURES_SIZE;
	mlx->width = j * TEXTURES_SIZE;
	malloc_map(mlx, i, j, argv[1]);
	chars_valid(mlx);
}
