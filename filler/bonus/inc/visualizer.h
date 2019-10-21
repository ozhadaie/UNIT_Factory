/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 14:07:44 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/24 21:42:13 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "libftprintf.h"
# include <fcntl.h>
# include <ncurses.h>
# include <unistd.h>
# include <stdlib.h>
# include <locale.h>
# define COL_XPL	100
# define COL_OPL	101
# define WIN_WID	150
# define WIN_HEI	200
# define OFFSETX	(WIN_WID - v->w) / 2.0
# define HEAD_H		15

typedef struct	s_pl
{
	char		*name;
	int			score;
	char		icon;
}				t_pl;

typedef struct	s_clr
{
	int			fg;
	int			bg;
	int			afg;
	int			abg;
}				t_clr;

typedef struct	s_vis
{
	t_pl		p1;
	t_pl		p2;
	int			w;
	int			h;
	char		**board;
	WINDOW		*head;
	WINDOW		*map;
	WINDOW		*score;
}				t_vis;

int				what_color(char c);
int				what_h_color(int j);
void			set_colors(void);
void			init_windows(t_vis *v);
void			finish(t_vis *v, char **line);
void			print_header(t_vis *v);
void			print_score(t_vis *v);

#endif
