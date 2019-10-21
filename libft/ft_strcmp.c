/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:21:24 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 18:21:25 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strcmp(const char *s1, const char *s2)
{
	size_t	l1;
	size_t	l2;
	size_t	n;
	int		r;

	l1 = ft_strlen(s1);
	l2 = ft_strlen(s2);
	n = (l1 > l2) ? l1 : l2;
	r = ft_memcmp(s1, s2, n);
	return (r);
}
