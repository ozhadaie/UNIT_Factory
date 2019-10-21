/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_range.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/24 18:49:24 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/10/24 18:49:26 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int	*ft_range(int min, int max)
{
	int	*array;
	int i;

	if (min >= max)
		return (NULL);
	array = (int*)malloc((max - min) * 4);
	i = -1;
	while (min++ < max)
		array[++i] = min - 1;
	return (array);
}
