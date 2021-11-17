/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 01:41:06 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/17 01:58:28 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "mlx.h"

# define WIN_WIDTH 1920
# define WIN_HEIGHT 1080
# define VALID_CHARS "01CEP"

typedef struct	s_imgsetup {
	void	*img;
	int	img_width;
	int	img_height;
	int	px_left;
	int	px_top;
}		t_imgsetup;

typedef	struct	s_winit {
	void	*mlx;
	void	*win;
	char	**maptab;
	int	nb_lines;
	int	nb_col;
	int	nb_corners;
	t_imgsetup	imgsetup;
}		t_winit;

#endif
