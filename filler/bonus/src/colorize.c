/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colorize.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/24 15:40:59 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/24 21:52:05 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

void	set_colors(void)
{
	start_color();
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, 208, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_GREEN, COLOR_BLACK);
	init_pair(5, COLOR_CYAN, COLOR_BLACK);
	init_pair(6, COLOR_BLUE, COLOR_BLACK);
	init_pair(7, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(8, COLOR_RED, COLOR_BLACK);
	init_pair(9, COLOR_CYAN, COLOR_CYAN);
	init_pair(10, COLOR_BLUE, COLOR_BLUE);
	init_pair(11, COLOR_YELLOW, COLOR_YELLOW);
	init_pair(12, 60, 60);
	init_pair(13, COLOR_WHITE, COLOR_WHITE);
	init_pair(COL_XPL, COLOR_BLUE, COLOR_BLUE);
	init_pair(COL_OPL, COLOR_YELLOW, COLOR_YELLOW);
}

int		what_h_color(int j)
{
	if (j < 15)
		return (COLOR_PAIR(1));
	if (j < 29)
		return (COLOR_PAIR(2));
	if (j < 43)
		return (COLOR_PAIR(3));
	if (j < 57)
		return (COLOR_PAIR(4));
	if (j < 71)
		return (COLOR_PAIR(5));
	if (j < 85)
		return (COLOR_PAIR(6));
	if (j < 97)
		return (COLOR_PAIR(7));
	return (COLOR_PAIR(8));
}

int		what_color(char c)
{
	if (c == '.')
		return (COLOR_PAIR(12));
	if (c == 'O')
		return (COLOR_PAIR(COL_OPL));
	if (c == 'o')
		return (COLOR_PAIR(9));
	if (c == 'X')
		return (COLOR_PAIR(COL_XPL));
	if (c == 'x')
		return (COLOR_PAIR(13));
	return (0);
}

void	init_windows(t_vis *v)
{
	v->head = newwin(11, WIN_WID, 0, 0);
	print_header(v);
	v->score = newwin(5, WIN_WID, HEAD_H, 0);
	v->p1.score = 0;
	v->p2.score = 0;
	v->map = newwin(WIN_HEI - HEAD_H - 10, WIN_WID, HEAD_H + 10, 0);
}

void	finish(t_vis *v, char **line)
{
	ft_strdel(line);
	ft_get_next_line(0, line);
	ft_strdel(line);
	print_score(v);
	usleep(3000000);
	delwin(v->score);
	delwin(v->map);
	delwin(v->head);
	endwin();
}
