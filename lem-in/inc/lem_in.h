/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lem_in.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/17 19:18:37 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/09/23 18:08:34 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LEM_IN_H
# define LEM_IN_H

# include "libftprintf.h"
# include <limits.h>
# include <stdlib.h>

typedef struct s_args	t_args;
typedef struct s_main	t_main;
typedef struct s_room	t_room;
typedef struct s_list	t_list;
typedef struct s_line	t_line;
typedef struct s_path	t_path;

/*
** =============================ROOM=========================================
** p - parent
** c - connected
** o - output
** i - input
** n - next
** s - string
** x - x coord
** y - y coord
** a - ants
** v - visited
** w - weight
*/

struct	s_room
{
	t_room	*p;
	t_list	*o;
	t_list	*c;
	t_room	*n;
	char	*s;
	int		x;
	int		y;
	int		v;
	int		a;
	int		w;
	int		d;
};

t_room	*room_new(char *s, int x, int y);
t_room	*room_add(t_room **r, char *s, int x, int y);
t_room	*room_push(t_room **r, char *s, int x, int y);
void	room_free(t_room **r);
void	room_del(t_room **r);

/*
** =============================LIST=========================================
** r - room
** c - cost
** n - next
*/

struct	s_list
{
	t_room	*r;
	int		c;
	t_list	*n;
};

t_list	*list_new(t_room *r);
t_list	*list_add(t_list **l, t_room *r);
t_list	*list_push(t_list **l, t_room *r);
void	list_free(t_list **l);
t_room	*list_del(t_list **l, t_room *d);

/*
** =============================LINE=========================================
** s - string
** n - next
** i - index
*/

struct	s_line
{
	char	*s;
	t_line	*n;
	int		i;
};

t_line	*line_new(char *s);
t_line	*line_push(t_line **l, char *s);
void	line_free(t_line **l);
void	line_del(t_line **l);

/*
** =============================PATH=========================================
** l - list
** n - next
** w - weight
*/

struct	s_path
{
	t_list	*l;
	t_path	*n;
	int		w;
};

t_path	*path_new(t_list *l);
t_path	*path_push(t_path **p, t_list *l);
void	path_free(t_path **p);
void	path_del(t_path **p);

/*
** =============================READ=========================================
*/

void	read_input(t_main *m);

/*
** =============================FIND=========================================
*/

t_room	*room_find(t_room *r, char *s);
t_list	*list_find(t_list *l, t_room *r);
t_path	*path_find(t_main *m);
t_room	*dijkstra(t_main *m);

/*
** =============================PRINT========================================
*/

void	input_print(t_line *i);
void	room_print(t_room *r);
void	list_print(t_list *l);
void	path_print(t_path *p);

/*
** =============================MISC=========================================
*/

int		split_size(char **sp);
int		split_free(char **sp);
int		ft_isnumber(char *s);
int		terminate(t_main *m, char *s);
int		ft_strchrc(char *s, char c);

/*
** =============================ARGS=========================================
** s - silent
** p - print paths
** e - print great errors
** r - print rooms
** m - print moves
*/

struct	s_args
{
	int	s : 1;
	int	p : 1;
	int	e : 1;
	int	r : 1;
	int	m : 1;
};

void	print_usage(char *flag, int ind);
void	read_part(t_args *a, char *flags);
void	read_args(t_main *m, int argc, char *argv[]);
void	process_args(t_main *m);

/*
** =============================MAIN=========================================
** r - all rooms
** s - start room
** e - end room
** i - input lines
** b - bottom line
** p - all paths
** a - arguments of command line
** l - flag if link already read
** m - count of moves
*/

struct	s_main
{
	t_room	*r;
	t_room	*s;
	t_room	*e;
	t_line	*i;
	t_line	*b;
	t_path	*p;
	t_args	a;
	int		l;
	int		m;
};

void	create_disjoint_paths(t_main *m);
void	process_input(t_main *m);
void	run_ants_run(t_main *m, int ants);

/*
** ==========================================================================
*/

#endif
