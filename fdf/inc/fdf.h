/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ozhadaie <ozhadaie@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/13 14:38:00 by ozhadaie          #+#    #+#             */
/*   Updated: 2019/07/30 21:52:59 by ozhadaie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft.h"
# include <errno.h>
# include <stdio.h>
# include <fcntl.h>
# include <unistd.h>

# define MIN(a, b) (a < b ? a : b)
# define E_USG	"usage: ./fdf [file]"
# define E_VLD	"Invalid map"
# define E_MAP	"Error init map"
# define E_FDF	"Error init fdf"
# define WIDTH	2560
# define HEIGHT	1440
# define TITLE	"FdF - ozhadaie"
# define CWHITE	0xFFFFFF
# define CLOW	0x0000FF
# define CMID	0x00FF00
# define CHIG	0xFF0000

typedef struct s_fdf	t_fdf;
typedef struct s_v2d	t_v2d;
typedef struct s_v3d	t_v3d;
typedef struct s_map	t_map;
typedef struct s_data	t_data;
typedef enum e_prj		t_prj;
typedef unsigned int	t_uns;

enum		e_prj
{
	ISO,
	PAR,
};

struct		s_v2d
{
	int		x;
	int		y;
};

struct		s_v3d
{
	double	x;
	double	y;
	double	z;
	t_uns	c;
};

struct		s_map
{
	t_v2d	s;
	t_v2d	d;
	t_v3d	**p;
};

struct		s_data
{
	void	*mlx;
	void	*win;
	void	*img;
	char	*adr;
	int		bpp;
	int		end;
	int		sl;
	int		scale;
	double	alt;
	t_v2d	offset;
	t_prj	proj;
	t_v3d	ang;
};

struct		s_fdf
{
	t_data	d;
	t_map	*m;
};

int			invalid_map(int fd, char *name, t_map *m);
void		split_del(char **sp);
int			split_size(char **ar);
int			isvalid_line(char **ar);

int			init_map(int fd, char *name, t_map *m);
int			init_fdf(t_fdf *f, t_map *m);
void		draw(t_fdf *f);
int			get_color(t_v3d current, t_v3d start, t_v3d end, t_v3d delta);
t_v3d		project(t_v3d p, t_fdf *f);

int			arrows(int key, t_fdf *f);
int			numpads(int key, t_fdf *f);
int			ft_ctoi(const char *str);
int			ft_isvalid(char *str);

#endif
