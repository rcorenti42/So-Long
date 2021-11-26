/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 05:00:20 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/26 09:06:18 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char    *ft_strcpy(char *dest, char *src)
{
        int     i;

        i = 0;
        while (src[i])
        {
                dest[i] = src[i];
                i++;
        }
        dest[i] = '\0';
        return (dest);
}

void	malloc_map(t_mlx *mlx, int line, int col, char *file)
{
	int	fd;
	int	i;

	i = 0;
	mlx->map = (char **)malloc(sizeof(char *) * col);
	if (!mlx->map)
		ft_error("malloc error");
	fd = open(file, O_RDONLY);
	if (!fd)
		ft_error("File Error");
	while (get_next_line(fd, &mlx->map[i]))
		i++;
	free(mlx->map[i]);
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
			ft_error(".ber only");
		n--;
		s1_len--;
		s2_len--;
	}
}
