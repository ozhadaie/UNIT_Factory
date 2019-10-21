/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat_toarr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:57:47 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:58:04 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int	initial_error_checks(t_hat *hat, int index,
				t_hatlf **current, int *local)
{
	if (hat == NULL || hat->head == NULL)
		return (0);
	*current = hat->head;
	while ((int)((*current)->start_index + hat->leaf_capacity) - 1 < index)
		*current = (*current)->next;
	*local = index - (*current)->start_index;
	if (*local < 0 || *local >= (int)(hat->leaf_capacity))
		return (0);
	return (1);
}

static void	*abort_copy(void *arr)
{
	free(arr);
	return (NULL);
}

void		*ft_hat_toarr(t_hat *hat, int index, size_t count)
{
	void	*arr;
	t_hatlf	*cur;
	int		i;
	int		local;

	if (count == 0)
		return (ft_strdup(""));
	if (initial_error_checks(hat, index, &cur, &local) == 0 ||
			(!((arr = ft_memalloc(((count + 1) * hat->atom_size))))))
		return (NULL);
	i = 0;
	while (count--)
	{
		ft_memcpy(arr + i++, cur->data + local, hat->atom_size);
		index++;
		local++;
		if (local == (int)(hat->leaf_capacity))
		{
			cur = cur->next;
			local = 0;
			if ((!cur && count) || (cur != NULL && index != cur->start_index))
				return (abort_copy(arr));
		}
	}
	return (arr);
}
