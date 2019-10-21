/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 15:54:24 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 21:30:03 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void		add_pixel(t_fdf *f, int x, int y, int c)
{
	int		i;

	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * f->d.bpp / 8) + (y * f->d.sl);
		f->d.adr[i] = c;
		f->d.adr[++i] = c >> 8;
		f->d.adr[++i] = c >> 16;
	}
}

static void		connect(t_fdf *f, t_v3d s, t_v3d e)
{
	t_v3d	d[3];
	double	err[2];

	d[2] = s;
	d[0].x = fabs(s.x - e.x);
	d[0].y = -fabs(s.y - e.y);
	d[1].x = s.x < e.x ? 1 : -1;
	d[1].y = s.y < e.y ? 1 : -1;
	err[0] = (d[0].x + d[0].y);
	while (42)
	{
		add_pixel(f, (int)d[2].x, (int)d[2].y, get_color(d[2], s, e, d[0]));
		if (fabs(d[2].x - e.x) < 1 && fabs(d[2].y - e.y) < 1)
			break ;
		if ((err[1] = 2 * err[0]) >= d[0].y)
		{
			err[0] += d[0].y;
			d[2].x += d[1].x;
		}
		if (err[1] <= d[0].x)
		{
			err[0] += d[0].x;
			d[2].y += d[1].y;
		}
	}
}

void			draw_background(t_fdf *f)
{
	int	i;
	int	j;

	i = -1;
	while (++i < HEIGHT && (j = -1))
		while (++j < WIDTH)
			add_pixel(f, j, i, 0x282843);
}

void			draw(t_fdf *f)
{
	int	i;
	int	j;

	i = -1;
	draw_background(f);
	while (++i < f->m->s.y && (j = -1))
		while (++j < f->m->s.x)
		{
			if (i != f->m->s.y - 1)
				connect(f, project(f->m->p[i][j], f),
					project(f->m->p[i + 1][j], f));
			if (j != f->m->s.x - 1)
				connect(f, project(f->m->p[i][j], f),
					project(f->m->p[i][j + 1], f));
		}
	mlx_put_image_to_window(f->d.mlx, f->d.win, f->d.img, 0, 0);
}
