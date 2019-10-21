/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/22 17:25:04 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/23 18:07:29 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"
#define Y(f) "\033[33;1m" f "\033[0m"
#define CLEAR() ft_printf("\e[1;1H\e[2J")

void	print_usage(char *flag, int ind)
{
	if (flag && ind)
		ft_printf("Unknow flag '%c'\n", flag[ind]);
	else if (flag)
		ft_printf("Unknow flag \"%s\"\n", flag);
	ft_printf("Usage: ./lem-in [flags] < map\n");
	ft_printf("\t\t%s, %s\n\t\t\tPrint no output\n", Y("-s"), Y("--silent"));
	ft_printf("\t\t%s, %s\n\t\t\tPrint all paths\n", Y("-p"), Y("--paths"));
	ft_printf("\t\t%s, %s\n\t\t\tPrint full error\n", Y("-e"), Y("--error"));
	ft_printf("\t\t%s, %s\n\t\t\tPrint all rooms\n", Y("-r"), Y("--rooms"));
	ft_printf("\t\t%s, %s\n\t\t\tPrint num moves\n", Y("-m"), Y("--moves"));
	exit(EXIT_SUCCESS);
}

void	read_part(t_args *a, char *flags)
{
	int	k;

	k = 0;
	if (flags[0] == '-' && flags[1] != '-')
		while (flags[++k])
			if (flags[k] == 's')
				a->s = 1;
			else if (flags[k] == 'p')
				a->p = 1;
			else if (flags[k] == 'e')
				a->e = 1;
			else if (flags[k] == 'r')
				a->r = 1;
			else if (flags[k] == 'm')
				a->m = 1;
			else
				print_usage(flags, k);
	else
		print_usage(flags, 0);
}

void	read_args(t_main *m, int argc, char *argv[])
{
	int	i;

	i = 0;
	while (++i < argc)
		if (argv[i][0] == '-' && argv[i][1] == '\0')
			print_usage(argv[i], 0);
		else if (!ft_strcmp(argv[i], "--silent"))
			m->a.s = 1;
		else if (!ft_strcmp(argv[i], "--paths"))
			m->a.p = 1;
		else if (!ft_strcmp(argv[i], "--errors"))
			m->a.e = 1;
		else if (!ft_strcmp(argv[i], "--rooms"))
			m->a.r = 1;
		else if (!ft_strcmp(argv[i], "--moves"))
			m->a.m = 1;
		else
			read_part(&m->a, argv[i]);
}

void	process_args(t_main *m)
{
	if (m->a.p && !(m->a.p = 0))
		path_print(m->p);
	if (m->a.r && !(m->a.r = 0))
	{
		CLEAR();
		room_print(m->r);
	}
}
