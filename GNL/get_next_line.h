/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:26:20 by rcorenti          #+#    #+#             */
/*   Updated: 2020/01/13 15:26:29 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 32
# endif

int		    get_next_line(int fd, char **line);
char	    *ft_linejoin(char **s1, char **s2, int i);
char	    *ft_strndup(const char *s, size_t size);
static int  get_newline(char *str);
static int	get_line(char **ptr, char **line);
static int	read_line(int fd, char **ptr, char **line);



#endif
