/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:36:34 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/04/16 20:21:54 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include "fillit.h"
#include "libft.h"

char	*map_new(int size)
{
	char	*str;
	t_xy	c;

	str = ft_strnew((size + 1) * size);
	c.y = -1;
	while (++c.y < size && (c.x = -1))
	{
		while (++c.x < size)
		{
			str[c.y * size + c.y + c.x] = '.';
		}
		str[c.y * size + c.y + c.x] = '\n';
	}
	return (str);
}

void	map_print(t_et *t, int count, int size)
{
	char	*str;
	t_xy	c;

	str = map_new(size);
	while (count > 0 && (c.y = -1))
	{
		while (++c.y < t->s.y && (c.x = -1))
			while (++c.x < t->s.x)
				if ((t->v >> (16 * (c.y + 1) - 1 - c.x)) & 1)
					str[(t->c.y + c.y) * (size + 1) + t->c.x + c.x] = t->a;
		t++;
		count--;
	}
	ft_putstr(str);
	ft_strdel(&str);
}

int		int_putendl(const char *str)
{
	ft_putendl(str);
	return (1);
}

int		main(int argc, char **argv)
{
	t_et		tet[MAX_TETRI + 1];
	uint16_t	map[16];
	int			count;
	int			size;
	char		buf[566];

	if (argc != 2)
		return (int_putendl("usage: ./fillit [source file]"));
	ft_bzero(tet, sizeof(t_et) * (MAX_TETRI + 1));
	if ((count = read_tet(open(argv[1], O_RDONLY), tet)) == 0)
		return (int_putendl("error"));
	size = read(open(argv[1], O_RDONLY), buf, 565);
	if (count * 21 - 1 != size)
		return (int_putendl("error"));
	ft_bzero(map, sizeof(uint16_t) * 16);
	if ((size = solve(tet, count, map)) == 0)
		return (int_putendl("error"));
	map_print(tet, count, size);
	return (0);
}
