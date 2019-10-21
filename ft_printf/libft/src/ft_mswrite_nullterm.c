/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mswrite_nullterm.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:00:18 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:01:06 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"

void		ft_mswrite_nullterm(t_multistringer *ms)
{
	if (ms == NULL)
		return ;
	if (ms->sb.type == 'B')
		ft_sbwrite_nullterm((t_stringbuilder *)ms);
	else if (ms->sb.type == 'W')
		ft_swwrite_nullterm((t_stringwriter *)ms);
	else if (ms->sb.type == 'U')
		ft_bwwrite_nullterm((t_stringwriter *)ms);
	else if (ms->sb.type == 'F')
		ft_fdwwrite_nullterm((t_fdwriter *)ms);
}

void		ft_sbwrite_nullterm(t_stringbuilder *sb)
{
	char	*ptr;

	ptr = (char *)ft_hataccess(sb->hat, (int)sb->len);
	if (ptr == NULL)
		return ;
	*ptr = '\0';
	(sb->len)++;
}

void		ft_fdwwrite_nullterm(t_fdwriter *fdw)
{
	char	nt;

	nt = '\0';
	if (fdw == NULL)
		return ;
	write(fdw->fd, &nt, 1);
	fdw->len++;
}

void		ft_swwrite_nullterm(t_stringwriter *sw)
{
	if (sw == NULL || sw->buff == NULL)
		return ;
	if (sw->len >= sw->capacity)
	{
		sw->buff[sw->capacity - 1] = '\0';
		return ;
	}
	sw->buff[sw->len] = '\0';
	(sw->len)++;
	sw->buff[sw->len] = '\0';
}

void		ft_bwwrite_nullterm(t_stringwriter *sw)
{
	if (sw == NULL || sw->buff == NULL)
		return ;
	if (sw->len >= sw->capacity)
		return ;
	sw->buff[sw->len] = '\0';
	(sw->len)++;
}
