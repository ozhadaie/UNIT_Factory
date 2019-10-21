/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 23:32:02 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/21 12:55:56 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "filler.h"

static char	*ft_strtoupper(char *s)
{
	int	i;

	i = -1;
	while (s[++i])
		if (s[i] >= 'a' && s[i] <= 'z')
			s[i] -= 32;
	return (s);
}

static int	read_board_size(t_filler *f)
{
	int	i;

	if (ft_get_next_line(0, &f->s) == 1)
	{
		f->board.y = ft_atoi(ft_strchr(f->s, ' '));
		f->board.x = ft_atoi(ft_strrchr(f->s, ' '));
		f->dists.y = f->board.y;
		f->dists.x = f->board.x;
		f->size = MAX(f->board.y, f->board.x);
		f->board.grid = (char**)malloc(sizeof(char*) * f->board.y);
		f->dists.grid = (int**)malloc(sizeof(int*) * f->dists.y);
		ft_strdel(&f->s);
		i = -1;
		while (++i < f->board.y)
			f->dists.grid[i] = (int*)malloc(sizeof(int) * f->dists.x);
		return (1);
	}
	return (0);
}

static int	read_token_size(t_filler *f)
{
	if (ft_get_next_line(0, &f->s) == 1)
	{
		f->token.y = ft_atoi(ft_strchr(f->s, ' '));
		f->token.x = ft_atoi(ft_strrchr(f->s, ' '));
		ft_strdel(&f->s);
		f->token.grid = (char**)malloc(sizeof(char*) * f->token.y);
		return (1);
	}
	return (0);
}

int			read_input(t_filler *f)
{
	int		i;

	if ((i = -1) && !read_board_size(f))
		return (0);
	ft_get_next_line(0, &f->s);
	ft_strdel(&f->s);
	while (++i < f->board.y && ft_get_next_line(0, &f->s) == 1)
	{
		f->board.grid[i] = ft_strtoupper(ft_strdup(ft_strchr(f->s, ' ') + 1));
		ft_strdel(&f->s);
	}
	if ((i = -1) && !read_token_size(f))
		return (0);
	while (++i < f->token.y && ft_get_next_line(0, &f->s) == 1)
	{
		f->token.grid[i] = ft_strtoupper(ft_strdup(f->s));
		ft_strdel(&f->s);
	}
	return (1);
}

int			insert_token(t_filler *f, int y, int x)
{
	int	i;
	int	j;
	int	touches;
	int	near;

	touches = 0;
	i = -1;
	near = 0;
	while (++i < f->token.y && (j = -1))
		while (++j < f->token.x)
			if (y + i < f->board.y && x + j < f->board.x && touches <= 1)
			{
				if (f->dists.grid[y + i][x + j] == -1 &&
						f->token.grid[i][j] == 42)
					return (0);
				if (f->token.grid[i][j] == 42 &&
						f->dists.grid[y + i][x + j] == -2)
					++touches;
				else if (f->token.grid[i][j] == 42)
					near += f->dists.grid[y + i][x + j];
			}
			else
				return (0);
	return (touches != 1 ? 0 : near);
}
