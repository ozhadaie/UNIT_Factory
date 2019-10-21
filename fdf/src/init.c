/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 18:04:54 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 21:53:10 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_v3d	new_point(t_map *m, int y, int x)
{
	t_v3d	point;

	point.x = x;
	point.y = y;
	point.z = m->p[y][x].z;
	point.c = CWHITE;
	return (point);
}

int		convert_map(char **line, t_map *m, int h)
{
	int		i;
	char	**t;

	i = -1;
	while (++i < m->s.x)
	{
		t = ft_strsplit(line[i], ',');
		if (t[1] && !ft_isvalid(t[1]))
			return (1);
		m->p[h][i].z = ft_atoi(line[i]);
		m->p[h][i].c = t[1] ? ft_ctoi(t[1]) : CWHITE;
		m->p[h][i].y = h;
		m->p[h][i].x = i;
		split_del(t);
	}
	return (0);
}

int		init_map(int fd, char *name, t_map *m)
{
	char	**zs;
	char	*line;
	int		ret;
	int		i;

	if ((fd = open(name, O_RDONLY)) < 0)
		return (1);
	if (!(m->p = (t_v3d**)malloc(sizeof(*m->p) * m->s.y)))
		return (2);
	i = -1;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		zs = ft_strsplit(line, ' ');
		if (!(m->p[++i] = (t_v3d*)malloc(sizeof(t_v3d) * m->s.x)))
			return (3);
		if (convert_map(zs, m, i))
			return (4);
		split_del(zs);
		free(line);
	}
	if (ret == -1)
		return (5);
	return (0);
}

int		init_fdf(t_fdf *f, t_map *m)
{
	f->m = m;
	f->d.mlx = mlx_init();
	f->d.win = mlx_new_window(f->d.mlx, WIDTH, HEIGHT, TITLE);
	f->d.img = mlx_new_image(f->d.mlx, WIDTH, HEIGHT);
	f->d.adr = mlx_get_data_addr(f->d.img, &f->d.bpp, &f->d.sl, &f->d.end);
	f->d.scale = MIN(WIDTH / f->m->s.x / 2, HEIGHT / f->m->s.y / 2);
	f->m->d.y = 2147483647;
	f->m->d.x = -2147483648;
	f->d.alt = 1;
	f->d.ang.x = 0;
	f->d.ang.y = 0;
	f->d.ang.z = 0;
	f->d.offset.x = 0;
	f->d.offset.y = 0;
	return (0);
}
