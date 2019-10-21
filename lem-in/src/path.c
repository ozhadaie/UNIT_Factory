/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:22:41 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/18 15:32:38 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*path_new(t_list *l)
{
	t_path	*p;

	if (!(p = (t_path *)malloc(sizeof(t_path))))
		terminate(NULL, "MALLOC PATH");
	p->l = l;
	p->n = NULL;
	p->w = 1;
	while ((l = l->n))
		++p->w;
	return (p);
}

t_path	*path_push(t_path **p, t_list *l)
{
	t_path	*t;
	t_path	*i;

	t = path_new(l);
	if (!*p)
		*p = t;
	else
	{
		i = *p;
		while (i->n)
			i = i->n;
		i->n = t;
	}
	return (t);
}

void	path_free(t_path **p)
{
	if (*p)
	{
		if ((*p)->l)
			list_free(&((*p)->l));
		free(*p);
		*p = NULL;
	}
}

void	path_del(t_path **p)
{
	t_path	*t;

	while (*p)
	{
		t = *p;
		*p = t->n;
		path_free(&t);
	}
}
