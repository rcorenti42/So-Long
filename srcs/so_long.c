/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/16 00:14:48 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/16 01:31:11 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "so_long.h"

int	main(int argc, char **argv)
{
	t_winit		winit;
	t_imgsetup	imgsetup;

	if (argc != 2)
	{
		printf("Error\nNot enough or too many arguments\n");
		return (0);
	}
	winit.mlx = mlx_init();
	winit.win = mlx_new_windows(winit.mlx, WIN_WIDTH, WIN_HEIGHT, "So Long !");
	
	return (0);
}
