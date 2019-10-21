/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 15:36:43 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/10 15:36:45 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	int		i;
	char	*str;

	if (!s || !f)
		return (NULL);
	if ((str = (char*)malloc(ft_strlen(s) + 1)) == NULL)
		return (NULL);
	i = -1;
	while (s[++i])
		str[i] = f((unsigned int)i, s[i]);
	str[i] = '\0';
	return (str);
}
