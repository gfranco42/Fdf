/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/02 19:46:34 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/12 16:54:48 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <mlx.h>
# include "./Libft/libft.h"
# include "./colors.h"

# define WIDTH 1000
# define HEIGHT 1000
# define Xinit 500
# define Yinit 100

typedef struct		s_pos
{
	int		x1;
	int		y1;
	int		x2;
	int		y2;
	int		z;
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

int			***parse(t_pos pos, char *file);

#endif
