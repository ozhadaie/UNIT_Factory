/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:03:11 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/10 16:03:12 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char const	*l;
	char const	*r;
	char		*str;

	l = NULL;
	if (!s)
		return (NULL);
	while (*s)
	{
		if (!(*s == ' ' || *s == '\n' || *s == '\t'))
		{
			l = (l == NULL) ? s : l;
			r = s;
		}
		s++;
	}
	if (l == NULL)
		return (ft_strnew(0));
	if ((str = (char*)malloc(sizeof(char) * (r - l + 2))) == NULL)
		return (NULL);
	s = l;
	while (s <= r)
		*str++ = *s++;
	*str = '\0';
	return (str - (r - l + 1));
}
