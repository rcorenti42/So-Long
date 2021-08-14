/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 01:36:59 by rcorenti          #+#    #+#             */
/*   Updated: 2019/10/16 01:37:07 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isprint(int c)
{
	if (c == 32)
		return (1);
	if (c > 47 && c < 58)
		return (1);
	if (c > 96 && c < 123)
		return (1);
	if (c > 64 && c < 91)
		return (1);
	if (c < 32 || c > 126)
		return (0);
	return (1);
}