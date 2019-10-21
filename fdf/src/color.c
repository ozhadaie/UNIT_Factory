/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/29 16:20:26 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 16:50:30 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	percent(double start, double end, double current)
{
	double	placement;
	double	distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(double start, double end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		get_color(t_v3d current, t_v3d start, t_v3d end, t_v3d delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.c == end.c)
		return (current.c);
	if (delta.x > delta.y)
		percentage = percent(start.x, end.x, current.x);
	else
		percentage = percent(start.y, end.y, current.y);
	red = get_light(start.c >> 16 & 0xFF, end.c >> 16 & 0xFF, percentage);
	green = get_light(start.c >> 8 & 0xFF, end.c >> 8 & 0xFF, percentage);
	blue = get_light(start.c & 0xFF, end.c & 0xFF, percentage);
	return (red << 16 | green << 8 | blue);
}
