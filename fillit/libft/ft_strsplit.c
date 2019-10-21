/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:15:08 by ozhadaie          #+#    #+#             */
/*   Updated: 2018/11/10 16:15:09 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
	size_t		count;
	char const	*str;

	count = 0;
	str = s;
	while (*str != '\0')
	{
		if (*str != c && (*(str - 1) == c || (str - 1) < s))
			count++;
		str++;
	}
	return (count);
}

static int		ft_copy_words(char const *s, char c, size_t count, char **ret)
{
	size_t	i;
	size_t	l;

	i = 0;
	l = 0;
	while (i < count)
	{
		if (*s != c && *s != '\0')
			l++;
		else if (l)
		{
			if ((ret[i] = (char*)malloc(l + 1)) == NULL)
				return (1);
			ft_strncpy(ret[i], s - l, l);
			ret[i++][l] = '\0';
			l = 0;
		}
		s++;
	}
	return (0);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**ret;
	size_t	count_words;

	if (!s)
		return (NULL);
	count_words = ft_count_words(s, c);
	if ((ret = (char**)malloc(sizeof(char**) * (count_words + 1))) == NULL)
		return (NULL);
	if (ft_copy_words(s, c, count_words, ret))
		return (NULL);
	ret[count_words] = NULL;
	return (ret);
}
