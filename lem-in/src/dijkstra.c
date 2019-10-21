/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dijkstra.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:47:56 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/23 17:55:21 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_room	*min_distance(t_room *r)
{
	t_room	*t;
	int		min;

	min = INT_MAX;
	t = NULL;
	while (r)
	{
		if (!r->v && r->w < min)
		{
			t = r;
			min = r->w;
		}
		r = r->n;
	}
	return (t);
}

void	init_dijkstra(t_room *r)
{
	while (r)
	{
		r->w = INT_MAX;
		r->p = NULL;
		r->v = 0;
		r = r->n;
	}
}

t_room	*dijkstra(t_main *m)
{
	t_list	*l;
	t_room	*t;

	init_dijkstra(m->r);
	m->s->w = 0;
	while ((t = min_distance(m->r)))
	{
		t->v = 1;
		l = t->o;
		while (l)
		{
			if (!l->r->d && !l->r->v && l->r->w > t->w + 1)
			{
				l->r->w = t->w + 1;
				l->r->p = t;
			}
			l = l->n;
		}
	}
	return (m->e->p);
}

void	process_input(t_main *m)
{
	t_room	*r;
	t_list	*l;

	(!m->s->o) ? terminate(NULL, "NO CONNECTION WITH START") : 0;
	(!m->e->o) ? terminate(NULL, "NO CONNECTION WITH END") : 0;
	while ((r = dijkstra(m)))
	{
		l = NULL;
		list_add(&l, m->e);
		while (r->p)
		{
			r->d = 1;
			list_add(&l, r);
			r = r->p;
		}
		list_add(&l, m->s);
		path_push(&m->p, l);
		if (l->n->r == m->e)
			break ;
	}
	(!m->p) ? terminate(m, "NO PATHS") : 0;
}
