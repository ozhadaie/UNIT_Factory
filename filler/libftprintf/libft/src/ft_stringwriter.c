/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringwriter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:02:20 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:02:34 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_stringwriter	*ft_swnew(char *buff_location, size_t capacity)
{
	t_stringwriter	*sw;

	sw = (t_stringwriter *)malloc(sizeof(t_stringwriter));
	if (sw == NULL)
		return (NULL);
	sw->type = 'W';
	sw->buff = buff_location;
	sw->capacity = capacity;
	sw->len = 0;
	return (sw);
}

void			ft_swwrite(t_stringwriter *sw, const char *str)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str)
	{
		if (sw->len >= sw->capacity)
		{
			sw->buff[sw->capacity - 1] = '\0';
			return ;
		}
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
	}
	sw->buff[sw->len] = '\0';
}

void			ft_swwriten(t_stringwriter *sw, const char *str, size_t n)
{
	if (sw == NULL || sw->buff == NULL || str == NULL)
		return ;
	while (*str && n)
	{
		if (sw->len >= sw->capacity)
		{
			sw->buff[sw->capacity - 1] = '\0';
			return ;
		}
		sw->buff[sw->len] = *str;
		str++;
		(sw->len)++;
		n--;
	}
	sw->buff[sw->len] = '\0';
}

void			ft_swclear(t_stringwriter *sw)
{
	if (sw == NULL)
		return ;
	sw->len = 0;
	if (sw->buff == NULL)
		return ;
	ft_bzero(sw->buff, sw->capacity);
}

void			ft_swdel(t_stringwriter **sw)
{
	if (sw == NULL || *sw == NULL)
		return ;
	free(*sw);
	*sw = NULL;
}
