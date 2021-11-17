/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:14:48 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/17 06:42:16 by rcorenti         ###   ########.fr       */
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

int	char_valid(char c)
{
	int	i;

	i = 0;
	while (VALID_CHARS[i])
	{
		if (c == VALID_CHARS[i])
			return (1);
		i++;
	}
	return (0);
}

void	ft_error(char *str)
{
	write(2, str, ft_strlen(str));
	exit(EXIT_FAILURE);
}

t_mlx	*malloc_map(t_mlx *mlx, int line, int col, char *file)
{
	int	fd;
	int	i;

	i = 0;
	mlx->map = (char **)malloc(sizeof(char *) * line);
	if (!mlx->map)
		ft_error("malloc error");
	while (line)
	{
		mlx->map[i] = (char *)malloc(sizeof(char) * col);
		i++;
		line--;
	}
	i = 0;
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("File Error");
	while (get_next_line(fd, &mlx->map[i]))
		i++;
	return (mlx);
}

int	check_map(char **argv, t_mlx *mlx)
{
	int	fd;
	int	i;
	int	j;
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
	mlx = malloc_map(mlx, i, j, argv[1]);
	i = 0;
	return (1);
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
	mlx.mlx_win = mlx_new_window(mlx.mlx_ptr, WIN_WIDTH, WIN_HEIGHT, "So Long !");
	mlx_loop(mlx.mlx_ptr);
	return (0);
}
