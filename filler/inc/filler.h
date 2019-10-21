/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/20 22:43:21 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/21 12:53:42 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include "libftprintf.h"
# include <stdlib.h>

# define MAX(a, b)	((a) > (b) ? (a) : (b))
# define INT_MAX	2147483647
# define ME	-2
# define OP	-1

typedef struct	s_cfield
{
	char		**grid;
	int			x;
	int			y;
}				t_cfield;

typedef struct	s_ifield
{
	int			**grid;
	int			x;
	int			y;
}				t_ifield;

typedef struct	s_filler
{
	t_cfield	board;
	t_cfield	token;
	t_ifield	dists;
	int			nearest;
	char		*s;
	char		me;
	char		op;
	int			size;
}				t_filler;

int				read_input(t_filler *f);
int				insert_token(t_filler *f, int y, int x);

#endif
