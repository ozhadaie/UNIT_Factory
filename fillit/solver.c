/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   solver.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:36:38 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/04/16 18:37:38 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include "libft.h"
#include <string.h>
#include <stdio.h>

inline int	check_bites(const t_et *tet, uint16_t *map)
{
	return (!(*(uint64_t *)(map + tet->c.y) & (tet->v >> tet->c.x)));
}

inline void	switch_bites(const t_et *tet, uint16_t *map)
{
	*(uint64_t *)(map + tet->c.y) ^= tet->v >> tet->c.x;
}

static int	solve_map(t_et *tet, const int size, uint16_t *map)
{
	int	pos;

	if (tet->a == 0)
		return (1);
	pos = (tet->l ? (tet->l->c.x + tet->l->c.y * size) : 0);
	tet->c.y = pos / size;
	while (tet->c.y <= size - tet->s.y)
	{
		tet->c.x = (tet->c.y == pos / size ? (pos % size) : 0);
		while (tet->c.x <= size - tet->s.x)
		{
			if (check_bites(tet, map))
			{
				switch_bites(tet, map);
				if (solve_map(tet + 1, size, map))
					return (1);
				switch_bites(tet, map);
			}
			tet->c.x++;
		}
		tet->c.y++;
	}
	tet->c.x = 0;
	tet->c.y = 0;
	return (0);
}

int			solve(t_et *tet, const int count, uint16_t *map)
{
	int	size;

	size = 2;
	while (size * size < count * 4)
		size++;
	while (!solve_map(tet, size, map) && size <= 16)
	{
		ft_bzero(map, sizeof(uint16_t) * 16);
		size++;
	}
	return (size == 17 ? (0) : size);
}
