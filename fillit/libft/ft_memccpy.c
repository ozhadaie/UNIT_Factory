/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:27:58 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 15:57:50 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char	*dstt;
	unsigned char	*srct;
	size_t			i;

	dstt = (unsigned char*)dst;
	srct = (unsigned char*)src;
	i = -1;
	while (++i < n)
	{
		dstt[i] = srct[i];
		if (srct[i] == (unsigned char)c)
			return ((void*)(dstt + i + 1));
	}
	return (NULL);
}
