/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:51:26 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/18 20:52:21 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*room_find(t_room *r, char *s)
{
	while (r)
		if (!ft_strcmp(r->s, s))
			return (r);
		else
			r = r->n;
	return (r);
}

t_list	*list_find(t_list *l, t_room *r)
{
	while (l)
		if (l->r == r)
			return (l);
		else
			l = l->n;
	return (l);
}
