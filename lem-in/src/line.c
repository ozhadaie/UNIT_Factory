/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:01:38 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/18 12:33:48 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_line	*line_new(char *s)
{
	static int	i = 1;
	t_line		*l;

	if (!(l = (t_line *)malloc(sizeof(t_line))))
		terminate(NULL, "MALLOC LINE");
	l->s = s;
	l->n = NULL;
	l->i = i++;
	return (l);
}

t_line	*line_push(t_line **l, char *s)
{
	t_line	*t;
	t_line	*i;

	t = line_new(s);
	if (!*l)
		*l = t;
	else
	{
		i = *l;
		while (i->n)
			i = i->n;
		i->n = t;
	}
	return (t);
}

void	line_free(t_line **l)
{
	if (*l)
	{
		if ((*l)->s)
			free((*l)->s);
		free(*l);
		*l = NULL;
	}
}

void	line_del(t_line **l)
{
	t_line	*t;

	while (*l)
	{
		t = *l;
		*l = t->n;
		line_free(&t);
	}
}
