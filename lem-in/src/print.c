/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 12:45:26 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/23 18:01:41 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define GOTOXY(x, y) ft_printf("\033[%d;%dH", y, x)

void	input_print(t_line *i)
{
	if (i)
		while (i)
		{
			ft_printf("%s\n", i->s);
			i = i->n;
		}
	else
		ft_printf("No input");
	ft_printf("\n");
}

void	room_print(t_room *r)
{
	int	max;

	max = 0;
	if (r)
		while (r)
		{
			if (r->y > max)
				max = r->y;
			GOTOXY(r->x, r->y);
			ft_printf("%c", *(r->s));
			r = r->n;
		}
	else
		ft_printf("No rooms\n");
	GOTOXY(0, max + 1);
}

void	list_print(t_list *l)
{
	if (l)
		while (l)
		{
			ft_printf("%s%s", l->r->s, (l->n) ? "," : "\n");
			l = l->n;
		}
	else
		ft_printf("No lists\n");
}

void	path_print(t_path *p)
{
	t_list	*l;

	if (p)
		while (p)
		{
			l = p->l;
			while (l)
			{
				ft_printf("%s%s", l->r->s, (l->n) ? "->" : "\n");
				l = l->n;
			}
			p = p->n;
		}
	else
		ft_printf("No paths\n");
}
