/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:59:48 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/22 19:01:24 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_list	*list_new(t_room *r)
{
	t_list	*l;

	if (!(l = (t_list *)malloc(sizeof(t_list))))
		terminate(NULL, "MALLOC LIST");
	l->r = r;
	l->n = NULL;
	return (l);
}

t_list	*list_add(t_list **l, t_room *r)
{
	t_list	*t;

	t = list_new(r);
	t->n = *l;
	*l = t;
	return (t);
}

t_list	*list_push(t_list **l, t_room *r)
{
	t_list	*t;
	t_list	*i;

	t = list_new(r);
	if (!*l)
		*l = t;
	else
	{
		i = *l;
		while (i->n)
			if (i->r == r)
				terminate(NULL, "DUPLICATE LINK");
			else
				i = i->n;
		if (i->r == r)
			terminate(NULL, "DUPLICATE LINK");
		i->n = t;
	}
	return (t);
}

void	list_free(t_list **l)
{
	t_list	*t;

	while (*l)
	{
		t = *l;
		*l = t->n;
		free(t);
	}
}

t_room	*list_del(t_list **l, t_room *r)
{
	t_list	*t;
	t_list	*d;

	if (!r || !*l)
		return (NULL);
	t = *l;
	if (t->r == r)
	{
		*l = t->n;
		free(t);
		return (r);
	}
	while (t->n)
		if (t->n->r == r)
			break ;
		else
			t = t->n;
	if (!t->n)
		return (NULL);
	d = t->n;
	t->n = d->n;
	free(d);
	return (r);
}
