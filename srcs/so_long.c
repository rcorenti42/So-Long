/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/14 05:04:13 by rcorenti          #+#    #+#             */
/*   Updated: 2021/08/14 05:05:51 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdio.h>
#include <errno.h>
#include <unistd.h>

int	main(int argc, char **argv)
{
    if (argc != 2)
    {
        printf("Error\nNot enough or too many arguments\n");
        return (0);
    }
    
    return (0);
}