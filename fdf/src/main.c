/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/25 14:25:01 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 21:22:47 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_error(char *e)
{
	ft_putendl(e);
	exit(1);
}

void	reset(t_fdf *f)
{
	f->d.scale = MIN(WIDTH / f->m->s.x / 2, HEIGHT / f->m->s.y / 2);
	f->d.alt = 1;
	f->d.ang.x = 0;
	f->d.ang.y = 0;
	f->d.ang.z = 0;
	f->d.offset.x = 0;
	f->d.offset.y = 0;
}

int		key_hook(int key, t_fdf *f)
{
	if (key == 53)
		exit(EXIT_SUCCESS);
	else if (key >= 123 && key <= 126)
		arrows(key, f);
	else if (key >= 67 && key <= 92)
		numpads(key, f);
	else if (key == 15)
		reset(f);
	else if (key == 34)
		f->d.proj = ISO;
	else if (key == 35)
		f->d.proj = PAR;
	draw(f);
	return (0);
}

int		escape(void *param)
{
	(void)param;
	exit(EXIT_SUCCESS);
}

int		main(int argc, char *argv[])
{
	t_fdf	f;
	t_map	m;
	int		fd;

	if (argc != 2)
		ft_error(E_USG);
	fd = 0;
	if (invalid_map(fd, argv[1], &m))
		ft_error(E_VLD);
	if (init_map(fd, argv[1], &m))
		ft_error(E_MAP);
	if (init_fdf(&f, &m))
		ft_error(E_FDF);
	draw(&f);
	mlx_hook(f.d.win, 2, 0, key_hook, &f);
	mlx_hook(f.d.win, 17, 0, escape, &f);
	mlx_loop(f.d.mlx);
	return (0);
}
