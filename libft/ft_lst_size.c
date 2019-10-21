/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lst_size.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 18:13:26 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/10 18:13:27 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lst_size(t_list *lst)
{
	int	i;

	i = 0;
	if (lst)
	{
		i = 1;
		while (lst->next)
		{
			lst = lst->next;
			i++;
		}
	}
	return (i);
}