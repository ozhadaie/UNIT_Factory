/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 14:54:38 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 14:54:39 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memset(void *b, int c, size_t len)
{
	char	*set;
	size_t	i;

	set = (char*)b;
	i = -1;
	while (++i < len)
		set[i] = (char)c;
	return (b);
}
