/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:37:18 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 16:37:19 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncpy(char *dst, const char *src, size_t len)
{
	size_t	i;
	size_t	n;

	n = ft_strlen(src);
	i = -1;
	while (++i < len)
		if (i < n)
			dst[i] = src[i];
		else if (i >= n)
			dst[i] = '\0';
	return (dst);
}
