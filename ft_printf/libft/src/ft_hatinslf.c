/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatinslf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:58:27 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:58:39 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	insert_first_leaf(t_hat *hat, t_hatlf *lf)
{
	hat->head = lf;
	hat->tail = lf;
	return ;
}

static void	insert_new_head(t_hat *hat, t_hatlf *lf)
{
	lf->next = hat->head;
	hat->head = lf;
}

static void	insert_middle_or_end(t_hat *hat, t_hatlf *lf)
{
	t_hatlf	*current;

	current = hat->head;
	while (current->next && current->next->start_index < lf->start_index)
		current = current->next;
	lf->next = current->next;
	lf->prev = current;
	if (current->next)
		current->next->prev = lf;
	else
		hat->tail = lf;
	current->next = lf;
}

void		ft_hatinslf(t_hat *hat, t_hatlf *lf)
{
	if (hat->head == NULL)
		insert_first_leaf(hat, lf);
	else if (hat->head->start_index > lf->start_index)
		insert_new_head(hat, lf);
	else
		insert_middle_or_end(hat, lf);
}
