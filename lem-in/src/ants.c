/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ants.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:47:52 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/23 18:08:15 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

t_path	*profit_path(t_main *m)
{
	t_path	*p;
	t_path	*i;
	int		sum;

	p = m->p;
	while (p)
		if (p->l->n->r == m->e || p->l->n->r->a == 0)
			break ;
		else
			p = p->n;
	if (!p)
		return (NULL);
	i = m->p;
	sum = 0;
	while (i != p)
	{
		sum += p->w - i->w;
		i = i->n;
	}
	if (sum < m->s->a)
		return (p);
	return (NULL);
}

void	run_ants_run(t_main *m, int ants)
{
	int		i;
	t_path	*p;
	t_list	*a[ants];

	ft_bzero(&a, sizeof(t_list *) * ants);
	while (m->e->a < ants && (i = -1))
	{
		while (++i < ants)
			if (!a[i] && (p = profit_path(m)))
			{
				m->s->a -= 1;
				a[i] = p->l->n;
				a[i]->r->a += 1;
				ft_printf("L%d-%s ", i + 1, a[i]->r->s);
			}
			else if (a[i] && a[i]->n)
			{
				a[i]->r->a -= 1;
				a[i] = a[i]->n;
				a[i]->r->a += 1;
				ft_printf("L%d-%s ", i + 1, a[i]->r->s);
			}
		ft_printf("\n");
		m->m++;
	}
}
