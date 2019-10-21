/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/16 18:40:03 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/04/16 19:20:43 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# define MAX_TETRI 26

# include <string.h>
# include <stdint.h>

typedef struct s_et	t_et;
typedef struct		s_xy
{
	uint8_t			x;
	uint8_t			y;
}					t_xy;
struct				s_et
{
	uint64_t		v;
	uint8_t			a;
	t_et			*l;
	t_xy			c;
	t_xy			s;
};

int					read_tet(int const fd, t_et *tet);
int					solve(t_et *tet, const int count, uint16_t *map);
int					check_bites(const t_et *tet, uint16_t *map);
void				switch_bites(const t_et *tet, uint16_t *map);
int					int_putendl(const char *str);
#endif
