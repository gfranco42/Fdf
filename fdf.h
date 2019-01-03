/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:46:34 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/03 17:45:03 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include <stdio.h>
# include "./Libft/libft.h"
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
	double	relief;
	double	xinit;
	double	yinit;
	double	xout;
	double	yout;
	double	xlen;
	double	ylen;
	double	initgap;
	double	savegap;
	double	gap;
	double	xtheta;
	double	ytheta;
	double	ztheta;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	double	z;
	int		i;
	int		j;
	int		k;
}					t_m;


int			**stock(char *file, t_m *m);
int			**fill(int fd, t_m m);
//int			**fill2(m, int fd);
void		string_to_window(t_m *m);
void		trace(t_m m);
void		draw(t_m m);
void		draw_rot(t_m m);
void		init_variable(t_m *m);
void		init_rot(t_m *m);
void		redraw_move(t_m *m, float a, float b);
void		redraw_zoom_in(t_m *m);
void		redraw_zoom_out(t_m *m);
void		redraw_relief(t_m *m);
void		change_relief_up(t_m *m);
void		change_relief_down(t_m *m);
void		zero(t_m *m);
void		back(t_m *m);
void		next(t_m *m);
void		iso(t_m *m);
void		parallele(t_m *m);
void		conique(t_m *m);
void		xrotate(t_m *m);
void		yrotate(t_m *m);
void		zrotate(t_m *m);
void		first_x_rotate(t_m *m);
void		first_y_rotate(t_m *m);
void		first_z_rotate(t_m *m);
void		x1rotate(t_m *m);
void		y1rotate(t_m *m);
void		z1rotate(t_m *m);
/*void		xincr(t_tool *t, t_tri v);
void		yincr(t_tool *t, t_tri v);
void		move(t_tool *t);*/

#endif
