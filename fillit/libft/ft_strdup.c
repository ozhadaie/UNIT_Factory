/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:11:13 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/08 16:11:14 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*str;
	size_t	i;
	size_t	len;

	if ((str = (char*)malloc(ft_strlen(s1) + 1)) == NULL)
		return (NULL);
	i = -1;
	len = ft_strlen(s1);
	while (++i < len)
		str[i] = s1[i];
	str[i] = '\0';
	return (str);
}
