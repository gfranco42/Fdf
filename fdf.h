/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:46:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/21 17:50:53 by gfranco          ###   ########.fr       */
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

# define WIDTH 1000
# define HEIGHT 1000



typedef struct		s_m
{
	void	*ptr;
	int		*win;
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
	double	xinit;
	double	yinit;
	double	initgap;
	double	savegap;
	double	gap;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		i;
	int		j;
	int		k;
}					t_m;

int			**stock(char *file, t_m *m);
int			**fill(int **array, int fd, t_m m);
void		trace(t_m m, int color);
void		draw(t_m m);
void		init_variable(t_m *m);
void		redraw_move(t_m *m, float a, float b);
void		redraw_zoom_in(t_m *m);
void		redraw_zoom_out(t_m *m);
void		clean(t_m *m);
/*void		xincr(t_tool *t, t_tri v);
void		yincr(t_tool *t, t_tri v);
void		move(t_tool *t);*/

#endif
