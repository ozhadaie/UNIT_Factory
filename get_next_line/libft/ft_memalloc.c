/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:04:28 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/10 15:10:52 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*str;

	if ((str = (char*)malloc(size)) == NULL)
		return (NULL);
	i = -1;
	while (++i < size)
		str[i] = 0;
	return (str);
}
