/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hatdellf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:58:13 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:58:20 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static void	delete_the_only_leaf(t_hat *hat, t_hatlf **lf)
{
	hat->head = NULL;
	hat->tail = NULL;
	free((*lf)->data);
	free(*lf);
	*lf = NULL;
}

static void	delete_head(t_hat *hat, t_hatlf **lf)
{
	hat->head = hat->head->next;
	hat->head->prev = NULL;
	free((*lf)->data);
	free(*lf);
	*lf = NULL;
}

static void	delete_tail(t_hat *hat, t_hatlf **lf)
{
	hat->tail = hat->tail->prev;
	hat->tail->next = NULL;
	free((*lf)->data);
	free(*lf);
	*lf = NULL;
}

static void	delete_middle(t_hatlf **lf)
{
	(*lf)->next->prev = (*lf)->prev;
	(*lf)->prev->next = (*lf)->next;
	free((*lf)->data);
	free(*lf);
	*lf = NULL;
}

void		ft_hatdellf(t_hat *hat, t_hatlf **lf)
{
	if (hat == NULL || lf == NULL || *lf == NULL)
		return ;
	if (*lf == hat->head && *lf == hat->tail)
		delete_the_only_leaf(hat, lf);
	else if (*lf == hat->head)
		delete_head(hat, lf);
	else if (*lf == hat->tail)
		delete_tail(hat, lf);
	else
		delete_middle(lf);
}
