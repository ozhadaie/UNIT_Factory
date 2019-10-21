/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 18:13:08 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 18:13:15 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int	i;

	i = (int)ft_strlen(s);
	if (c == 0)
		return ((char*)(s + i));
	while (--i >= 0)
		if (s[i] == (char)c)
			return ((char*)(s + i));
	return (NULL);
}
