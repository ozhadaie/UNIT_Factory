/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fildeswriter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:45:28 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:45:54 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "libft.h"

t_fdwriter	*ft_fdwnew(int fd)
{
	t_fdwriter	*fdw;

	fdw = (t_fdwriter *)malloc(sizeof(t_fdwriter));
	if (fdw == NULL)
		return (NULL);
	fdw->type = 'F';
	fdw->len = 0;
	fdw->fd = fd;
	return (fdw);
}

void		ft_fdwwrite(t_fdwriter *fdw, const char *str)
{
	if (fdw == NULL || str == NULL)
		return ;
	while (*str)
	{
		write(fdw->fd, str, 1);
		str++;
		fdw->len++;
	}
}

void		ft_fdwwriten(t_fdwriter *fdw, const char *str, size_t n)
{
	if (fdw == NULL || str == NULL)
		return ;
	while (*str && n)
	{
		write(fdw->fd, str, 1);
		str++;
		fdw->len++;
		n--;
	}
}

void		ft_fdwclear(t_fdwriter *fdw)
{
	fdw->len = 0;
}

void		ft_fdwdel(t_fdwriter **fdw)
{
	if (fdw == NULL || *fdw == NULL)
		return ;
	free(*fdw);
	*fdw = NULL;
}
