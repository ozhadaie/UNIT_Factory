/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_nullterm_ptrarray.c                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 17:25:01 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 17:45:23 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	ft_destroy_nullterm_ptrarray(void ***arr)
{
	int		i;

	if (arr == NULL || *arr == NULL)
		return ;
	i = 0;
	while ((*arr)[i] != NULL)
	{
		free(((*arr)[i]));
		(*arr)[i] = NULL;
		i++;
	}
	free(*arr);
	*arr = NULL;
}
