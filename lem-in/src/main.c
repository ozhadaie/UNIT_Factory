/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:48:23 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/23 18:37:23 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		main(int argc, char *argv[])
{
	t_main	m;

	ft_bzero(&m, sizeof(t_main));
	read_args(&m, argc, argv);
	read_input(&m);
	process_input(&m);
	if (!m.a.s)
		input_print(m.i);
	process_args(&m);
	run_ants_run(&m, m.s->a);
	if (m.a.m)
		ft_printf("%d\n", m.m);
	path_del(&m.p);
	room_del(&m.r);
	line_del(&m.i);
	return (0);
}
