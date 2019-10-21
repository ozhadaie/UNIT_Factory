/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 13:08:51 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/23 18:19:35 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_room	*read_room(t_main *m, int a)
{
	char	**s;
	t_room	*r;

	if (!a || m->l)
		terminate(m, "Unspecified input format");
	if (!((s = ft_strsplit(m->b->s, ' ')) && split_size(s) == 3 &&
			ft_isnumber(s[1]) && ft_isnumber(s[2])))
		terminate(m, "Invalid room");
	r = room_push(&(m->r), s[0], ft_atoi(s[1]), ft_atoi(s[2]));
	split_free(s);
	return (r);
}

static void		read_link(t_main *m)
{
	char	**s;
	t_room	*r1;
	t_room	*r2;
	t_room	*i;

	if (!((s = ft_strsplit(m->b->s, '-')) && split_size(s) == 2))
		terminate(m, "Invalid link");
	i = m->r;
	r1 = NULL;
	r2 = NULL;
	while (i)
	{
		if (!ft_strcmp(i->s, s[0]))
			r1 = i;
		else if (!ft_strcmp(i->s, s[1]))
			r2 = i;
		i = i->n;
	}
	(!r1) ? terminate(m, "Can't find left room") : 0;
	(!r2) ? terminate(m, "Can't find right room") : 0;
	list_push(&r1->o, r2);
	list_push(&r2->o, r1);
	m->l = 1;
	split_free(s);
}

static void		read_ants(t_main *m, int *a)
{
	if (*a > 0)
		terminate(m, "Unspecified input format");
	if ((*a = ft_atoi(m->b->s)) <= 0)
		terminate(m, "Invalid count of ants");
}

static void		read_comm(t_main *m, int a)
{
	char	*line;
	char	*t;

	if (!ft_strcmp(m->b->s, "##start") || !ft_strcmp(m->b->s, "##end"))
	{
		t = m->b->s;
		if (ft_get_next_line(0, &line) <= 0)
			terminate(NULL, "Invalid input after command");
		m->b = line_push(&(m->i), line);
		if ((ft_strchrc(line, ' ') == 2))
		{
			if (t[2] == 's' && !m->s)
				m->s = read_room(m, a);
			else if (t[2] == 'e' && !m->e)
				m->e = read_room(m, a);
			else
				terminate(m, "Duplicate start or end");
		}
		else
			terminate(m, "Invalid room format after command");
	}
}

void			read_input(t_main *m)
{
	char	*line;
	int		ret;
	int		a;

	a = 0;
	while ((ret = ft_get_next_line(0, &line)) > 0)
	{
		m->b = line_push(&(m->i), line);
		if (*line == '#')
			read_comm(m, a);
		else if ((ft_strchrc(m->b->s, ' ') == 2) && a)
			read_room(m, a);
		else if ((ft_strchrc(m->b->s, '-') == 1) && m->r)
			read_link(m);
		else if (ft_isnumber(line))
			read_ants(m, &a);
		else
			break ;
	}
	(ret < 0) ? terminate(m, "CAN'T READ") : 0;
	(!a) ? terminate(m, "NO ANTS") : 0;
	(!m->s) ? terminate(m, "NO START ROOM") : 0;
	(!m->e) ? terminate(m, "NO END ROOM") : 0;
	(!m->l) ? terminate(m, "NO LINKS") : 0;
	m->s->a = a;
}
