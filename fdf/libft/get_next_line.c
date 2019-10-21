/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/13 17:52:32 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/29 12:52:35 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <unistd.h>

static int	ft_cut_line(const int fd, char **fds, char **line, int ret)
{
	char	*tmp;
	char	*i;

	if ((i = ft_strchr(fds[fd], '\n')))
	{
		*line = ft_strsub(fds[fd], 0, i - fds[fd]);
		tmp = ft_strdup(i + 1);
		free(fds[fd]);
		fds[fd] = tmp;
		if (fds[fd][0] == '\0')
			ft_strdel(&fds[fd]);
	}
	else if (!i)
	{
		if (ret == BUFF_SIZE)
			return (get_next_line(fd, line));
		*line = ft_strdup(fds[fd]);
		ft_strdel(&fds[fd]);
	}
	return (1);
}

int			get_next_line(const int fd, char **line)
{
	static char		*fds[MAX_FD];
	t_read			red;

	if (fd < 0 || line == NULL)
		return (-1);
	while ((red.ret = read(fd, red.buff, BUFF_SIZE)) > 0)
	{
		red.buff[red.ret] = '\0';
		if (fds[fd] == NULL)
			fds[fd] = ft_strnew(0);
		red.tmp = ft_strjoin(fds[fd], red.buff);
		free(fds[fd]);
		fds[fd] = red.tmp;
		if (ft_strchr(red.buff, '\n'))
			break ;
	}
	if (red.ret >= 0)
	{
		if (red.ret == 0 && (fds[fd] == NULL || fds[fd][0] == '\0'))
			return (0);
		return (ft_cut_line(fd, fds, line, red.ret));
	}
	return (red.ret);
}
