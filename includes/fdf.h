/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:46:34 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/11 14:55:55 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include "../srcs/Libft/libft.h"
# include "macros.h"
# include <math.h>

# define WIDTH 2560
# define HEIGHT 1400
# define MAX_Z 1000
# define MIN_Z -1000

typedef struct		s_m
{
	void	*ptr;
	void	*img;
	int		*win;
	char	*str;
	char	*av;
	int		**array;
	int		***tab;
	char	blue;
	char	green;
	char	red;
	char	alpha;
	char	dblue;
	char	dgreen;
	char	dred;
	int		bpp;
	int		s_l;
	int		endian;
	int		ex;
	int		ey;
	int		cx;
	int		cy;
	int		dx;
	int		dy;
	int		line;
	int		column;
	int		a;
	int		b;
	float	coef;
	float	rel_v;
	float	relief;
	float	xinit;
	float	yinit;
	float	xout;
	float	yout;
	float	xlen;
	float	ylen;
	float	initgap;
	float	savegap;
	float	gap;
	float	xtheta;
	float	ytheta;
	float	ztheta;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	float	z;
	int		i;
	int		j;
	int		k;
}					t_m;

void				back(t_m *m);
void				draw_rot(t_m m);
void				fail(int i);
int					**fill(int fd, t_m m);
int					***fill_tab(t_m m);
void				first_rotate(t_m *m);
void				init_rot(t_m *m);
void				iso(t_m *m);
int					check_rel(t_m *m, int key);
int					key_clean(int kay, void *param);
int					key_color(int kay, void *param);
int					key_move(int kay, void *param);
int					key_relief(int kay, void *param);
int					key_rotate(int kay, void *param);
int					key_rotate_z1(int key, void *param);
int					key_rotate_z2(int key, void *param);
int					key_sounds(int kay, void *param);
int					key_stop(int kay, void *param);
int					key_zoom(int kay, void *param);
void				parallele(t_m *m);
void				redraw(t_m *m);
void				redraw_move(t_m *m, float a, float b);
void				redraw_zoom_in(t_m *m);
void				redraw_zoom_out(t_m *m);
void				rotate(t_m *m);
void				stock(char *file, t_m *m);
void				string_to_window(t_m *m);
void				trace(t_m m);
void				zero(t_m *m);

#endif
