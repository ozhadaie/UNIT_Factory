/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hat.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:48:52 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:48:52 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_hat	*ft_hatnew(size_t leaf_capacity, size_t atom_size)
{
	t_hat	*hat;

	hat = (t_hat *)malloc(sizeof(t_hat));
	if (hat == NULL)
		return (NULL);
	hat->leaf_capacity = leaf_capacity;
	hat->atom_size = atom_size;
	hat->head = NULL;
	hat->tail = NULL;
	return (hat);
}

void	ft_hatset(t_hat *hat, int index, void *data)
{
	void	*ptr;

	ptr = ft_hataccess(hat, index);
	if (ptr == NULL)
		return ;
	ft_memcpy(ptr, data, hat->atom_size);
}

void	*ft_hataccess(t_hat *hat, int index)
{
	int		start_index;
	t_hatlf	*lf;
	t_hatlf	*current;

	if (hat == NULL)
		return (NULL);
	current = hat->head;
	start_index = ft_hat_get_start_index(hat, index);
	while (current && current->start_index < start_index)
		current = current->next;
	if (!current || current->start_index != start_index)
	{
		lf = ft_hatlfnew(hat->leaf_capacity, hat->atom_size, start_index);
		if (lf == NULL)
			return (NULL);
		ft_hatinslf(hat, lf);
		return (lf->data + ((index - start_index) * (hat->atom_size)));
	}
	return (current->data + ((index - start_index) * (hat->atom_size)));
}

void	ft_hatdel(t_hat **hat)
{
	t_hatlf	*tmp;

	while ((*hat)->head)
	{
		tmp = (*hat)->head;
		ft_hatdellf(*hat, &tmp);
	}
	free(*hat);
	*hat = NULL;
}
