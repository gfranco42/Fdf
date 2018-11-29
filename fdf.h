/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:46:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/29 16:57:35 by gfranco          ###   ########.fr       */
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
# include "colors.h"
# include <math.h>

# define WIDTH 1000
# define HEIGHT 1000



typedef struct		s_m
{
	void	*ptr;
	void	*img;
	int		*win;
	char	*str;
	char	red;
	char	green;
	char	blue;
	char	alpha;
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
	int		lenline;
	int		column;
	int		lencolumn;
	double	tmpx;
	double	tmpy;
	double	xinit;
	double	yinit;
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
	int		z;
	int		i;
	int		j;
	int		k;
}					t_m;

int			**stock(char *file, t_m *m);
int			**fill(int **array, int fd, t_m m);
void		trace(t_m m);
void		draw(t_m m);
void		draw_rot(t_m m);
void		init_variable(t_m *m);
void		redraw_move(t_m *m, float a, float b);
void		redraw_zoom_in(t_m *m);
void		redraw_zoom_out(t_m *m);
void		zero(t_m *m);
void		back(t_m *m);
void		next(t_m *m);
void		iso(t_m *m);
void		paralelle(t_m *m);
void		conique(t_m *m);
void		xrotate(t_m *m);
void		yrotate(t_m *m);
void		zrotate(t_m *m);
void		first_x_rotate(t_m *m);
void		first_y_rotate(t_m *m);
void		first_z_rotate(t_m *m);
/*void		xincr(t_tool *t, t_tri v);
void		yincr(t_tool *t, t_tri v);
void		move(t_tool *t);*/

#endif
