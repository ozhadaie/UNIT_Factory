/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_constructors.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:01:56 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:01:56 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char	*ft_strdup(const char *str)
{
	char	*r;
	int		len;
	int		i;

	len = 0;
	while (str[len])
		len++;
	r = (char *)malloc((sizeof(char) * (len + 1)));
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i <= len)
	{
		r[i] = str[i];
		i++;
	}
	return (r);
}

char	*ft_strnew(size_t size)
{
	size_t	i;
	char	*str;

	str = (char *)malloc(size + 1);
	if (str == NULL)
		return (NULL);
	i = 0;
	while (i <= size)
	{
		str[i] = 0;
		i++;
	}
	return (str);
}

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*r;
	unsigned int	i;

	if (s == NULL)
		return (NULL);
	r = ft_strnew(len);
	if (r == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		r[i] = s[start + i];
		i++;
	}
	return (r);
}
