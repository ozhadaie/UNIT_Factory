/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:27:53 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 15:27:54 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char	*dstt;
	char	*srct;
	size_t	i;

	dstt = (char*)dst;
	srct = (char*)src;
	i = -1;
	while (++i < n)
		dstt[i] = srct[i];
	return (dst);
}
