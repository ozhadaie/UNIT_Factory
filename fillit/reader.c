/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:36:27 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/04/16 20:18:48 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "fillit.h"

static void		get_size(const char *str, t_xy *m)
{
	unsigned char	i;

	i = -1;
	m[0].x = 3;
	m[0].y = 3;
	m[1].x = 0;
	m[1].y = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if (i % 5 < m[0].x)
				m[0].x = i % 5;
			if (i / 5 < m[0].y)
				m[0].y = i / 5;
			if (i % 5 > m[1].x)
				m[1].x = i % 5;
			if (i / 5 > m[1].y)
				m[1].y = i / 5;
		}
	}
}

static t_et		get_tet(const char *str, const char alpha)
{
	t_et	tet;
	t_xy	m[2];
	t_xy	c;

	get_size(str, m);
	tet.s.x = m[1].x - m[0].x + 1;
	tet.s.y = m[1].y - m[0].y + 1;
	tet.a = alpha;
	tet.v = 0;
	tet.l = NULL;
	c.y = -1;
	str += m[0].x + m[0].y * 5;
	while (++c.y < tet.s.y && (c.x = -1))
		while (++c.x < tet.s.x)
			if (str[c.x + c.y * 5] == '#')
				tet.v |= (1L << (16 * (c.y + 1) - 1 - c.x));
	return (tet);
}

static int		invalid_con(const char *str)
{
	int	i;
	int	con;

	i = -1;
	con = 0;
	while (++i < 20)
	{
		if (str[i] == '#')
		{
			if (i + 1 < 20 && str[i + 1] == '#')
				con += 1;
			if (i + 5 < 20 && str[i + 5] == '#')
				con++;
		}
	}
	return (!(con == 3 || con == 4));
}

int				invalid_block(const char *str, int count)
{
	int	hash;
	int	i;

	i = -1;
	hash = 0;
	while (++i < 20)
	{
		if (i % 5 < 4)
		{
			if (!(str[i] == '#' || str[i] == '.'))
				return (1);
			if (str[i] == '#' && (++hash > 4))
				return (2);
		}
		else if (str[i] != '\n')
			return (3);
	}
	if (count == 21 && (str[20] != '\n'))
		return (4);
	if (invalid_con(str))
		return (5);
	return (0);
}

int				read_tet(int const fd, t_et *tet)
{
	char	buf[22];
	int		count;
	int		i;
	int		j;
	char	cur;

	cur = 'A';
	i = 0;
	while ((count = read(fd, buf, 21)) >= 20)
	{
		if (invalid_block(buf, count))
			return (0);
		tet[i] = get_tet(buf, cur++);
		j = i;
		while (--j >= 0)
		{
			if (tet[j].v == tet[i].v)
				tet[i].l = tet + j;
		}
		i++;
	}
	if (count != 0)
		return (0);
	close(fd);
	return (cur - 'A');
}
