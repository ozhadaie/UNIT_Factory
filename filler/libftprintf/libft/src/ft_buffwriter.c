/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_buffwriter.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:44:20 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:44:55 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_stringwriter	*ft_bwnew(char *buff_location, size_t capacity)
{
	t_stringwriter	*sw;

	sw = (t_stringwriter *)malloc(sizeof(t_stringwriter));
	if (sw == NULL)
		return (NULL);
	sw->type = 'U';
	sw->buff = buff_location;
	sw->capacity = capacity;
	sw->len = 0;
	return (sw);
}

void			ft_bwwrite(t_stringwriter *sw, const char *str)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str)
	{
		if (sw->len >= sw->capacity)
			return ;
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
	}
}

void			ft_bwwriten(t_stringwriter *sw, const char *str, size_t n)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str && n)
	{
		if (sw->len >= sw->capacity)
			return ;
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
		n--;
	}
}

void			ft_bwclear(t_stringwriter *sw)
{
	ft_swclear(sw);
}

void			ft_bwdel(t_stringwriter **sw)
{
	ft_swdel(sw);
}
