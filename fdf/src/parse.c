/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 12:57:50 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 11:55:52 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	split_del(char **sp)
{
	int	i;

	i = -1;
	while (sp[++i])
		free(sp[i]);
	free(sp);
}

int		split_size(char **ar)
{
	int	i;

	i = 0;
	while (ar[i])
		++i;
	return (i);
}

int		invalid_map(int fd, char *name, t_map *m)
{
	char	**zs;
	char	*line;
	int		ret;

	if ((fd = open(name, O_RDONLY)) < 0)
		return (1);
	m->s.y = 0;
	m->s.x = 0;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		zs = ft_strsplit(line, ' ');
		if (!m->s.y)
			m->s.x = split_size(zs);
		else if (m->s.x != split_size(zs))
			return (3);
		free(line);
		split_del(zs);
		m->s.y++;
	}
	if (ret == -1)
		return (4);
	close(fd);
	return (0);
}
