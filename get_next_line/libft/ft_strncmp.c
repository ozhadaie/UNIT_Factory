/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:24:38 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 18:24:39 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	l1;
	size_t	l2;
	size_t	l;
	int		r;

	l1 = ft_strlen(s1) + 1;
	l2 = ft_strlen(s2) + 1;
	l = (l1 < n) ? l1 : n;
	l = (l2 < l) ? l2 : l;
	r = ft_memcmp(s1, s2, l);
	return (r);
}
