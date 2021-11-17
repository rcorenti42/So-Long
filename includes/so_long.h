/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:41:06 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/17 06:43:07 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <string.h>
# include <stdio.h>
# include <errno.h>
# include <unistd.h>
# include "mlx.h"
# include "get_next_line.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define VALID_CHARS "01CEP"

typedef struct	s_mlx {
	void	*img_ptr;
	char	*img;
	char	**map;
	void	*mlx_ptr;
	void	*mlx_win;
	int	event;
	int	sqrt_size;
	int	width;
	int	height;
	int	size_line;
	int	bpp;
	int	endian;
	int	moves;
}		t_mlx;

int	check_map(char **argv, t_mlx *mlx);
void	ft_error(char *str);
void	ft_putstr_fd(char *str, int fd);
char	*ft_strcpy(char *dest, char *src);

#endif
