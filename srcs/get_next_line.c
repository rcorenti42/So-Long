/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcorenti <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/01/13 15:25:40 by rcorenti          #+#    #+#             */
/*   Updated: 2021/11/28 02:31:57 by rcorenti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	get_newline(char *str)
{
	int	i;

	i = 0;
	if (!str)
		return (-1);
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (i);
		i++;
	}
	return (-1);
}

static int	get_line(char **ptr, char **line)
{
	char	*tmp;
	int		size;
	int		result;

	result = 0;
	tmp = NULL;
	if (!*ptr)
		return (result);
	size = get_newline(*ptr);
	if (**ptr != '\0')
	{
		result = 1;
		if (size == -1)
			*line = ft_strjoin(line, ptr, 2);
		else
		{
			tmp = ft_strndup(*ptr, size);
			*line = ft_strjoin(line, &tmp, 2);
			tmp = ft_strndup(*ptr + size + 1, ft_strlen(*ptr + size + 1));
		}
	}
	free(*ptr);
	*ptr = tmp;
	return (result);
}

static int	ret_read_line(char **ptr, char **line, int size)
{
	if (size != -1 && *ptr)
		return (get_line(ptr, line));
	else
		return (size);
}

static int	read_line(int fd, char **ptr, char **line)
{
	char	buff[BUFFER_SIZE + 1];
	char	*ptr_buff;
	char	*str;
	int		size;

	str = *ptr;
	ft_memset(buff, 0, BUFFER_SIZE + 1);
	size = read(fd, buff, BUFFER_SIZE);
	while (size > 0)
	{
		buff[BUFFER_SIZE] = '\0';
		ptr_buff = buff;
		*ptr = ft_strjoin(ptr, &ptr_buff, 1);
		ft_memset(buff, 0, BUFFER_SIZE + 1);
		if (get_newline(*ptr) != -1)
			break ;
		size = read(fd, buff, BUFFER_SIZE);
	}
	if (size == 0 && (!str || *str == '\0'))
	{
		get_line(ptr, line);
		free(*ptr);
		return (0);
	}
	return (ret_read_line(ptr, line, size));
}

int	get_next_line(int fd, char **line)
{
	static char	*ptr;
	int			result;

	result = -1;
	if (fd >= 0 && BUFFER_SIZE > 0)
	{
		*line = ft_strndup("", 0);
		result = get_line(&ptr, line);
		if (!ptr || !*line)
			result = read_line(fd, &ptr, line);
	}
	return (result);
}
