/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:46:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/20 18:00:07 by gfranco          ###   ########.fr       */
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



typedef struct		s_trace
{
	int		ex;
	int		ey;
	int		cx;
	int		cy;
	int		dx;
	int		dy;
	int		x1;
	int		y1;
	int		x2;
	int		y2;
}					t_trace;

typedef struct		s_tri
{
	int		i;
	int		j;
	int		k;
}					t_tri;

typedef struct		s_tool
{
	void	*ptr;
	int		*win;
	int		xinit;
	int		yinit;
	int		gap;
	int		line;
	int		column;
}					t_tool;

typedef struct		s_all
{
	t_tool	*t;
	t_trace	s;
	t_tri	v;
}					t_all;

int			**stock(char *file, t_tool *t);
int			**fill(int **array, t_tool *t, int fd, t_tri v);
void		trace(t_tool *t, t_trace s, int color);
void		draw(t_tool *t, t_tri v, t_trace s);
/*void		xincr(t_tool *t, t_tri v);
void		yincr(t_tool *t, t_tri v);
void		move(t_tool *t);*/

#endif
