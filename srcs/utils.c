/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:00:20 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/26 05:52:57 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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

int	ft_strncmp_inv(char *s1, char *s2, int n)
{
	int	s1_len;
	int	s2_len;

	s1_len = ft_strlen(s1) - 1;
	s2_len = ft_strlen(s2) - 1;
	while (n)
	{
		if (s1[s1_len] != s2[s2_len])
			return (0);
		n--;
		s1_len--;
		s2_len--;
	}
	return (1);
}
