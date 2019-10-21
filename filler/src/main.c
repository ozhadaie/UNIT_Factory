/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:38:34 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/22 16:41:02 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"
#define TL f->dists.grid[i - 1][j - 1]
#define TM f->dists.grid[i - 1][j]
#define TR f->dists.grid[i - 1][j + 1]
#define ML f->dists.grid[i][j - 1]
#define MR f->dists.grid[i][j + 1]
#define BL f->dists.grid[i + 1][j - 1]
#define BM f->dists.grid[i + 1][j]
#define BR f->dists.grid[i + 1][j + 1]

static void	init_distances(t_filler *f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < f->dists.y && (j = -1))
	{
		while (++j < f->dists.x)
		{
			if (f->board.grid[i][j] == f->me)
				f->dists.grid[i][j] = ME;
			else if (f->board.grid[i][j] == f->op)
				f->dists.grid[i][j] = OP;
			else
				f->dists.grid[i][j] = INT_MAX;
		}
	}
}

static void	update_distance(t_filler *f, int i, int j, int distance)
{
	if (i > 1 && j > 1 && INT_MAX == TL)
		TL = distance;
	if (i > 1 && INT_MAX == TM)
		TM = distance;
	if (i > 1 && j < f->dists.x - 1 && INT_MAX == TR)
		TR = distance;
	if (i > 1 && j > 1 && INT_MAX == ML)
		ML = distance;
	if (i > 1 && j < f->dists.x - 1 && INT_MAX == MR)
		MR = distance;
	if (i < f->dists.y - 1 && j > 1 && INT_MAX == BL)
		BL = distance;
	if (i < f->dists.y - 1 && INT_MAX == BM)
		BM = distance;
	if (i < f->dists.y - 1 && j < f->dists.x - 1 && INT_MAX == BR)
		BR = distance;
}

static void	fill_distances(t_filler *f)
{
	int	distance;
	int	i;
	int	j;

	init_distances(f);
	distance = 0;
	while (++distance <= f->size && (i = -1))
	{
		while (++i < f->dists.y && (j = -1))
		{
			while (++j < f->dists.x)
			{
				if ((f->dists.grid[i][j] == -1) ||
					(f->dists.grid[i][j] == distance - 1 && distance != 1))
					update_distance(f, i, j, distance);
			}
		}
	}
}

static void	make_a_move(t_filler *f)
{
	int	x;
	int	y;
	int	i;
	int	j;
	int	near;

	i = -1;
	x = 0;
	y = 0;
	f->nearest = 0;
	while (++i < f->dists.y && (j = -1))
	{
		while (++j < f->dists.x)
		{
			near = insert_token(f, i, j);
			if (near && (near < f->nearest || !f->nearest))
			{
				f->nearest = near;
				y = i;
				x = j;
			}
		}
	}
	ft_printf("%d %d\n", y, x);
}

int			main(void)
{
	t_filler	f;
	int			i;

	if (ft_get_next_line(0, &f.s) == 1)
	{
		f.me = (*(ft_strchr(f.s, 'p') + 1) == '1' ? 'O' : 'X');
		f.op = (f.me == 'O' ? 'X' : 'O');
		ft_strdel(&f.s);
		while (read_input(&f))
		{
			fill_distances(&f);
			make_a_move(&f);
			i = -1;
			while (++i < f.board.y)
				free(f.board.grid[i]);
			free(f.board.grid);
			i = -1;
			while (++i < f.token.y)
				free(f.token.grid[i]);
			free(f.token.grid);
		}
	}
	return (0);
}
