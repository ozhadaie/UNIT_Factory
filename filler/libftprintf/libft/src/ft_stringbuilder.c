/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stringbuilder.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/12 18:02:09 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/12 18:02:17 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

t_stringbuilder	*ft_sbnew(void)
{
	t_stringbuilder	*sb;

	sb = (t_stringbuilder *)malloc(sizeof(t_stringbuilder));
	if (sb == NULL)
		return (NULL);
	sb->hat = ft_hatnew(FT_STRINGBUILDER_LEAFSIZE, 1);
	if (sb->hat == NULL)
	{
		free(sb);
		return (NULL);
	}
	sb->len = 0;
	sb->type = 'B';
	return (sb);
}

void			ft_sbwrite(t_stringbuilder *sb, const char *str)
{
	char	*ptr;

	ptr = NULL;
	if (str == NULL)
		return ;
	while (*str)
	{
		if (ptr == NULL || sb->len % sb->hat->leaf_capacity == 0)
			ptr = (char *)ft_hataccess(sb->hat, (int)sb->len);
		if (ptr == NULL)
			return ;
		*ptr = *str;
		ptr++;
		str++;
		(sb->len)++;
	}
}

void			ft_sbwriten(t_stringbuilder *sb, const char *str, size_t n)
{
	char	*ptr;

	ptr = NULL;
	if (str == NULL)
		return ;
	while (*str && n)
	{
		if (ptr == NULL || sb->len % sb->hat->leaf_capacity == 0)
			ptr = (char *)ft_hataccess(sb->hat, (int)(sb->len));
		if (ptr == NULL)
			return ;
		*ptr = *str;
		ptr++;
		str++;
		(sb->len)++;
		n--;
	}
}

void			ft_sbdel(t_stringbuilder **sb)
{
	if (sb == NULL || *sb == NULL)
		return ;
	ft_hatdel(&(((*sb)->hat)));
	free(*sb);
	*sb = NULL;
}

void			ft_sbclear(t_stringbuilder *sb)
{
	t_hatlf *tmp;

	if (sb == NULL)
		return ;
	while (sb->hat->head->next)
	{
		tmp = sb->hat->head->next;
		ft_hatdellf(sb->hat, &tmp);
	}
	ft_bzero(sb->hat->head->data, sb->hat->leaf_capacity);
	sb->len = 0;
}
