/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/22 13:27:44 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/24 21:52:55 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "visualizer.h"

int		start(t_vis *v)
{
	char	*line;
	int		i;

	ft_bzero(v, sizeof(*v));
	i = -1;
	if (ft_get_next_line(0, &line) && ft_strstr(line, "map is"))
		return (1);
	ft_strdel(&line);
	while (++i < 4 && ft_get_next_line(0, &line))
		ft_strdel(&line);
	ft_get_next_line(0, &line);
	i = ft_strrchr(line, '/') - line;
	v->p1.name = ft_strsub(line, i + 1, ft_strlen(line) - i);
	ft_strdel(&line);
	ft_get_next_line(0, &line);
	ft_strdel(&line);
	ft_get_next_line(0, &line);
	i = ft_strrchr(line, '/') - line;
	v->p2.name = ft_strsub(line, i + 1, ft_strlen(line) - i);
	ft_strdel(&line);
	ft_get_next_line(0, &line);
	ft_strdel(&line);
	initscr();
	curs_set(0);
	return (0);
}

void	print_score(t_vis *v)
{
	char	*s1;
	char	*s2;

	s1 = ft_itoa(v->p1.score);
	s2 = ft_itoa(v->p2.score);
	wattron(v->score, COLOR_PAIR(COL_OPL) | A_BOLD);
	mvwaddstr(v->score, 0, OFFSETX, v->p1.name);
	mvwaddstr(v->score, 0, OFFSETX + ft_strlen(v->p1.name) + 1, s1);
	wattron(v->score, COLOR_PAIR(COL_XPL) | A_BOLD);
	mvwaddstr(v->score, 1, OFFSETX, v->p2.name);
	mvwaddstr(v->score, 1, OFFSETX + ft_strlen(v->p2.name) + 1, s2);
	wattroff(v->score, COLOR_PAIR(COL_XPL) | COLOR_PAIR(COL_OPL) | A_BOLD);
	wrefresh(v->score);
	free(s1);
	free(s2);
}

void	handle_map(t_vis *v, char **line)
{
	int		i;
	int		j;
	char	wc;

	i = -1;
	ft_strdel(line);
	while (++i < v->h && ft_get_next_line(0, line) == 1 && (j = 3))
	{
		while (++j < v->w)
		{
			wc = (*line)[j];
			wattron(v->map, what_color(wc));
			mvwaddch(v->map, i, (WIN_WID - v->w) / 2.0 + j, wc);
			wattroff(v->map, what_color(wc));
			v->p1.score += (wc == 'o' ? 1 : 0);
			v->p2.score += (wc == 'x' ? 1 : 0);
		}
		ft_strdel(line);
	}
	print_score(v);
	usleep(10000);
	wrefresh(v->map);
}

void	print_header(t_vis *v)
{
	char	*line;
	int		fd;
	int		len;
	int		i;
	int		j;

	i = -1;
	fd = open("./bonus/head.txt", O_RDONLY);
	set_colors();
	while (++i < 11 && ft_get_next_line(fd, &line) && (j = -1))
	{
		len = ft_strlen(line);
		while (++j < len)
		{
			wattron(v->head, what_h_color(j));
			mvwaddch(v->head, i, (WIN_WID - 111) / 2.0 + j, line[j]);
			wattroff(v->head, what_h_color(j));
		}
		ft_strdel(&line);
	}
	wrefresh(v->head);
	close(fd);
}

int		main(void)
{
	t_vis	v;
	char	*line;

	if (start(&v))
		return (0);
	init_windows(&v);
	while (ft_get_next_line(0, &line) == 1)
	{
		if (!ft_strncmp(line, "Plateau", 7))
		{
			v.h = ft_atoi(ft_strchr(line, ' '));
			v.w = ft_atoi(ft_strrchr(line, ' '));
			ft_strdel(&line);
		}
		else if (!ft_strncmp(line, "   ", 3))
			handle_map(&v, &line);
		else if (!ft_strncmp(line, "== O", 4))
			finish(&v, &line);
		else
			ft_strdel(&line);
	}
	ft_printf("%s:%i\n%s:%i\n", v.p1.name, v.p1.score, v.p2.name, v.p2.score);
	return (0);
}
