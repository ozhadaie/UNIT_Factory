/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   room.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:52:53 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/22 19:01:47 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*room_new(char *s, int x, int y)
{
	t_room	*r;

	if (*s == 'L' || *s == '#')
		terminate(NULL, "INVALID ROOM NAME");
	if (!(r = (t_room *)ft_memalloc(sizeof(t_room))))
		terminate(NULL, "MALLOC ROOM");
	r->s = ft_strdup(s);
	r->x = x;
	r->y = y;
	r->w = INT_MAX;
	return (r);
}

t_room	*room_push(t_room **r, char *s, int x, int y)
{
	t_room	*t;
	t_room	*i;

	t = room_new(s, x, y);
	if (!*r)
		*r = t;
	else
	{
		i = *r;
		while (i->n)
			if (!ft_strcmp(i->s, t->s) || ((i->x == t->x) && (i->y == t->y)))
				terminate(NULL, "DUPLICATE ROOM");
			else
				i = i->n;
		if (!ft_strcmp(i->s, t->s) || ((i->x == t->x) && (i->y == t->y)))
			terminate(NULL, "DUPLICATE ROOM");
		i->n = t;
	}
	return (t);
}

t_room	*room_add(t_room **r, char *s, int x, int y)
{
	t_room	*t;

	t = room_new(s, x, y);
	t->n = *r;
	*r = t;
	return (t);
}

void	room_free(t_room **r)
{
	if (*r)
	{
		if ((*r)->s)
			free((*r)->s);
		list_free(&(*r)->c);
		list_free(&(*r)->o);
		free(*r);
		*r = NULL;
	}
}

void	room_del(t_room **r)
{
	t_room	*t;

	while (*r)
	{
		t = *r;
		*r = t->n;
		room_free(&t);
	}
}
