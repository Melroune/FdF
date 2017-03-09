/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_next_line.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akerkeb <akerkeb@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2014/11/22 03:59:19 by akerkeb           #+#    #+#             */
/*   Updated: 2014/12/01 18:36:32 by akerkeb          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdlib.h>

int		read_next_line(char **n_ret, int fd)
{
	char		*buf;
	int			c_char;
	char		*temp;

	buf = ft_strnew(BUFF_SIZE);
	c_char = BUFF_SIZE;
	while (ft_strchr(*n_ret, '\n') == NULL && c_char == BUFF_SIZE)
	{
		if ((c_char = read(fd, buf, BUFF_SIZE)) == -1)
			return (-1);
		buf[c_char] = '\0';
		temp = ft_strjoin(*n_ret, buf);
		free(*n_ret);
		*n_ret = ft_strdup(temp);
		free(temp);
	}
	free(buf);
	return (c_char);
}

int		get_next_line(int fd, char **line)
{
	static char *n_ret[256];
	int			c_char;
	char		*temp;

	if (fd < 0 || !line)
		return (-1);
	if (!n_ret[fd])
		n_ret[fd] = ft_strnew(0);
	if ((c_char = read_next_line(&n_ret[fd], fd)) == -1)
		return (-1);
	if (c_char < BUFF_SIZE && ft_strchr(n_ret[fd], '\n') == NULL)
	{
		*line = ft_strdup(n_ret[fd]);
		ft_bzero(n_ret[fd], ft_strlen(n_ret[fd]));
		return (0);
	}
	*line = ft_strsub(n_ret[fd], 0, (size_t)(ft_strchr(n_ret[fd], '\n')
	- n_ret[fd]));
	temp = ft_strdup(ft_strchr(n_ret[fd], '\n') + 1);
	free(n_ret[fd]);
	n_ret[fd] = ft_strdup(temp);
	free(temp);
	return (1);
}
