/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:32:59 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 16:15:07 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

static void	rotate_x(double *y, double *z, double alpha)
{
	double	tmp;

	tmp = *y;
	*y = tmp * cos(alpha) + *z * sin(alpha);
	*z = -tmp * sin(alpha) + *z * cos(alpha);
}

static void	rotate_y(double *x, double *z, double beta)
{
	double	tmp;

	tmp = *x;
	*x = tmp * cos(beta) + *z * sin(beta);
	*z = -tmp * sin(beta) + *z * cos(beta);
}

static void	rotate_z(double *x, double *y, double gamma)
{
	t_v3d	tmp;

	tmp.x = *x;
	tmp.y = *y;
	*x = tmp.x * cos(gamma) - tmp.y * sin(gamma);
	*y = tmp.x * sin(gamma) + tmp.y * cos(gamma);
}

static void	iso(double *x, double *y, double z)
{
	t_v3d	tmp;

	tmp.x = *x;
	tmp.y = *y;
	*x = (tmp.x - tmp.y) * cos(0.523599);
	*y = -z + (tmp.x + tmp.y) * sin(0.523599);
}

t_v3d		project(t_v3d p, t_fdf *f)
{
	p.x *= f->d.scale;
	p.y *= f->d.scale;
	p.z *= f->d.scale / f->d.alt;
	p.x -= (f->m->s.x * f->d.scale) / 2.0;
	p.y -= (f->m->s.y * f->d.scale) / 2.0;
	rotate_x(&p.y, &p.z, f->d.ang.x);
	rotate_y(&p.x, &p.z, f->d.ang.y);
	rotate_z(&p.x, &p.y, f->d.ang.z);
	if (f->d.proj == ISO)
		iso(&p.x, &p.y, p.z);
	p.x += WIDTH / 2.0 + f->d.offset.x;
	p.y += (HEIGHT + f->m->s.y * f->d.scale) / 2.0 + f->d.offset.y;
	return (p);
}
