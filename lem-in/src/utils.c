/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 18:00:57 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/23 18:37:36 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int	ft_strchrc(char *s, char c)
{
	int	i;
	int	k;

	i = 0;
	k = -1;
	while (s[++k])
		if (s[k] == c)
			++i;
	return (i);
}

int	split_size(char **sp)
{
	int	i;

	i = 0;
	while (sp[i])
		++i;
	return (i);
}

int	split_free(char **sp)
{
	int	i;

	i = -1;
	while (sp[++i])
		free(sp[i]);
	free(sp);
	return (0);
}

int	ft_isnumber(char *s)
{
	if (*s == '-' || *s == '+')
		++s;
	if (!*s)
		return (0);
	while (*s)
		if (!(*s >= '0' && *s <= '9'))
			return (0);
		else
			++s;
	return (1);
}

int	terminate(t_main *m, char *s)
{
	if (m && m->a.e)
	{
		if (m->b)
			ft_printf("%d \"%s\" ", m->b->i, m->b->s);
		ft_printf("%s\n", s);
	}
	else
		ft_printf("ERROR\n");
	exit(EXIT_FAILURE);
}
