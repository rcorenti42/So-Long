/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 01:03:10 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/25 07:41:11 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void    chars_valid(t_mlx *mlx)
{
        int     i;
        int     j;
        int     k;
        int     valid;

        i = 0;
        while (i < mlx->height / TEXTURES_SIZE)
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

void    chars_minimum(t_mlx *mlx)
{
        int     C;
        int     E;
        int     P;
        int     i;
        int     j;

        C = 0;
        E = 0;
        P = 0;
        i = 0;
        while (i < mlx->height / TEXTURES_SIZE)
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

void    check_walls(t_mlx *mlx, int line, int col)
{
        int     i;

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

void    malloc_map(t_mlx *mlx, int line, int col, char *file)
{
        int     fd;
        int     i;
        int     buff;

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

void	check_map(char **argv, t_mlx *mlx)
{
        int             fd;
        int             i;
        int             j;
        char    *buff;

        i = 0;
        j = -1;
        fd = open(argv[1], O_RDONLY);
       	if (fd < 0)
		ft_error("File Error");
        while (get_next_line(fd, &buff))
        {
                if (j != -1 && j != ft_strlen(buff))
                        ft_error("Invalid Map Size");
                j = ft_strlen(buff);
                i++;
        }
        close(fd);
	mlx->height = i * TEXTURES_SIZE;
	mlx->width = j * TEXTURES_SIZE;
        malloc_map(mlx, i, j, argv[1]);
        chars_valid(mlx);
        chars_minimum(mlx);
        check_walls(mlx, i, j);
}
