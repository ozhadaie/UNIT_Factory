/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 15:34:13 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 15:34:16 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	char	*dstt;
	char	*srct;
	size_t	i;
	int		nt;

	i = -1;
	nt = (int)n;
	dstt = (char*)dst;
	srct = (char*)src;
	if (srct < dstt)
		while (--nt >= 0)
			dstt[nt] = srct[nt];
	else
		while (++i < n)
			dstt[i] = srct[i];
	return (dst);
}
