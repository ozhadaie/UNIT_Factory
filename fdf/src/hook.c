/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hook.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/30 16:30:09 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 16:42:37 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int	arrows(int key, t_fdf *f)
{
	if (key == 123)
		f->d.offset.x -= 10;
	else if (key == 124)
		f->d.offset.x += 10;
	else if (key == 126)
		f->d.offset.y -= 10;
	else if (key == 125)
		f->d.offset.y += 10;
	return (0);
}

int	numpads(int key, t_fdf *f)
{
	if (key == 69)
		f->d.scale += 1;
	else if (key == 78)
		f->d.scale -= (f->d.scale > 1) ? 1 : 0;
	else if (key == 89)
		f->d.ang.z += 0.05;
	else if (key == 92)
		f->d.ang.z -= 0.05;
	else if (key == 86)
		f->d.ang.y -= 0.05;
	else if (key == 88)
		f->d.ang.y += 0.05;
	else if (key == 83)
		f->d.ang.x -= 0.05;
	else if (key == 85)
		f->d.ang.x += 0.05;
	else if (key == 75)
		f->d.alt += 0.01;
	else if (key == 67)
		f->d.alt -= (f->d.alt > 0.1) ? 0.01 : 0;
	return (0);
}
