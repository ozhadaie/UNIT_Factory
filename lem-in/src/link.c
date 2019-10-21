/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   link.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:10:50 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/18 12:34:35 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_link	*link_new(t_room *r1, t_room *r2)
{
	t_link	*k;

	if (!(k = (t_link *)malloc(sizeof(t_link))))
		terminate(NULL, "MALLOC LINK");
	k->r1 = r1;
	k->r2 = r2;
	k->n = NULL;
	return (k);
}

t_link	*link_push(t_link **k, t_room *r1, t_room *r2)
{
	t_link	*t;
	t_link	*i;

	t = link_new(r1, r2);
	if (!*k)
		*k = t;
	else
	{
		i = *k;
		while (i->n)
			if ((i->r1 == r1 && i->r2 == r2) || (i->r2 == r1 && i->r1 == r2))
				terminate(NULL, "DUPLICATE LINK");
			else
				i = i->n;
		if ((i->r1 == r1 && i->r2 == r2) || (i->r2 == r1 && i->r1 == r2))
			terminate(NULL, "DUPLICATE LINK");
		i->n = t;
	}
	return (t);
}

void	link_free(t_link **k)
{
	if (*k)
	{
		free(*k);
		*k = NULL;
	}
}

void	link_del(t_link **k)
{
	t_link	*t;

	while (*k)
	{
		t = *k;
		*k = t->n;
		link_free(&t);
	}
}
