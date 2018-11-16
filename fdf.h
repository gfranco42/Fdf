/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:46:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/16 16:52:46 by gfranco          ###   ########.fr       */
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

typedef struct		s_pos
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		gap;
}					t_pos;

typedef struct		s_trace
{
	int		ex;
	int		ey;
	int		cx;
	int		cy;
	int		dx;
	int		dy;
}					t_trace;

typedef struct		s_mlx
{
	void	*ptr;
	void	*win;
}					t_mlx;

typedef struct		s_init
{
	int		x;
	int		y;
	int		gap;
}					t_init;

typedef struct		s_tri
{
	int		i;
	int		j;
	int		k;
}					t_tri;

int			**stock(char *file, int *line, int *column);
int			**fill(int **array, t_tri t, int fd);
void		xincr(int *x2, int *y2, t_tri t, t_init init);
void		yincr(int *x2, int *y2, t_tri t, t_init init);
void		move(int *x1, int *y1, int x2, int y2);

#endif
