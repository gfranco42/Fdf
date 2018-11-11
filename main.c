/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/11 16:49:02 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"

int		test(int key, void *param)
{
	if (key == 53)
		exit(0);
	else
		ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

/*void	trace(t_pos pos, t_mlx *mlx, int color)
{
	double		a;
	double		x;
	double		y;
	double		e;

	a = (double)(pos.y2 - pos.y1) / (double)(pos.x2 - pos.x1);
	e = a * -1 + 1;
	x = pos.x1;
	y = pos.y1;
	e = 0;
	while (x <= pos.x2)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, (int)x, (int)y, color);
		e -= a;
		if (e < -0.5)
		{
			y--;
			e += 1;
		}
		x++;
	}
}*/

void	trace1(t_pos pos, t_mlx *mlx, t_trace s, int color)
{
	int		i;

	i = 0;
	while (i++ <= s.cx)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, pos.x1, pos.y1, color);
		pos.x1 = pos.x1 > pos.x2 ? (pos.x1 - 1) : (pos.x1 + 1);
		s.ex -= s.dy;
		if (s.ex < 0)
		{
			pos.y1 = pos.y1 > pos.y2 ? (pos.y1 - 1) : (pos.y1 + 1);
			s.ex += s.dx;
		}
	}
}

void	trace2(t_pos pos, t_mlx *mlx, t_trace s, int color)
{
	int		i;

	i = 0;
	while (i++ <= s.cy)
	{
		mlx_pixel_put(mlx->ptr, mlx->win, pos.x1, pos.y1, color);
		pos.y1 = pos.y1 > pos.y2 ? (pos.y1 - 1) : (pos.y1 + 1);
		s.ey -= s.dx;
		if (s.ey < 0)
		{
			pos.x1 = pos.x1 > pos.x2 ? (pos.x1 - 1) : (pos.x1 + 1);
			s.ey += s.dy;
		}
	}
}

void	trace(t_pos pos, t_mlx *mlx, t_trace s, int color)
{
	s.ex = abs(pos.x2 - pos.x1);
	s.ey = abs(pos.y2 - pos.y1);
	s.dx = 2 * s.ex;
	s.dy = 2 * s.ey;
	s.cx = s.ex;
	s.cy = s.ey;
	if (s.cx > s.cy)
		trace1(pos, mlx, s, color);
	else
		trace2(pos, mlx, s, color);
}

int		main()
{
	t_mlx		*mlx;
	t_pos		pos;
	t_trace		s;
	int			count;
	int			line;
	int			column;
	int			i;
	int			z = -20;
	i = 0;
	line = 4; // si 5 lignes : line = ligne - 1
	column = 8; // si 9 colonnes : column = colonne - 1

	pos.x1 = Xinit;
	pos.y1 = Yinit;
	pos.x2 = 620;
	pos.y2 = 220;

	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "YOLO");

	count = 0;
	trace(pos, mlx, s, LGREEN);
	pos.x1 = 440;
	pos.y1 = 160;
	pos.x2 = 560;
	pos.y2 = 280;
	trace(pos, mlx, s, LBLUE);
	pos.x1 = 410;
	pos.y1 = 190;
	pos.x2 = 530;
	pos.y2 = 310;
	trace(pos, mlx, s, DBLUE);
	pos.x1 = 470;
	pos.y1 = 130;
	pos.x2 = 500;
	pos.y2 = 160 + z;// 160 + (-10) = 150
	trace(pos, mlx, s, DGREEN);// 1er vert
	pos.x1 = pos.x2;
	pos.y1 = pos.y2;
	pos.x2 = 530;
	pos.y2 = 190;
	trace(pos, mlx, s, DGREEN);// 2e vert
	pos.x1 = pos.x2;
	pos.y1 = pos.y2;
	pos.x2 = 590;
	pos.y2 = 250;
	trace(pos, mlx, s, DGREEN);// 3e vert
	pos.x1 = 410;
	pos.y1 = 190;
	pos.x2 = 500;
	pos.y2 = 100;
	trace(pos, mlx, s, PINK);
	pos.x1 = 440;
	pos.y1 = 220;
	pos.x2 = 470;
	pos.y2 = 190;
	trace(pos, mlx, s, LPURPLE);// 1e violet
	pos.x1 = pos.x2;
	pos.y1 = pos.y2;
	pos.x2 = 500;
	pos.y2 = 160 + z;
	trace(pos, mlx, s, LPURPLE);// 2e violet
	pos.x1 = pos.x2;
	pos.y1 = pos.y2;
	pos.x2 = 530;
	pos.y2 = 130;
	trace(pos, mlx, s, LPURPLE);// 3e violet
	pos.x1 = 470;
	pos.y1 = 250;
	pos.x2 = 560;
	pos.y2 = 160;
	trace(pos, mlx, s, DPURPLE);
	pos.x1 = 500;
	pos.y1 = 280;
	pos.x2 = 590;
	pos.y2 = 190;
	trace(pos, mlx, s, RED);
	pos.x1 = 530;
	pos.y1 = 310;
	pos.x2 = 620;
	pos.y2 = 220;
	trace(pos, mlx, s, DORANGE);
/*	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 321;
	pos.y2 = y - 95;
	trace(pos, mlx, LPURPLE);//			1e octant X++ Y-
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1;
	pos.y2 = y - 154;
	trace(pos, mlx, LBLUE);//			2e octant X+ Y--
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x - 30;
	pos.y2 = y - 1348;
	trace(pos, mlx, DORANGE);//			3e octant X- Y--
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x - 1445;
	pos.y2 = y - 342;
	trace(pos, mlx, DGREEN);//			4e octant X-- Y-
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x - 1964;
	pos.y2 = y + 258;
	trace(pos, mlx, DPURPLE);//			5e octant X-- Y+
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x - 369;
	pos.y2 = y + 1456;
	trace(pos, mlx, DBLUE);//			6e octant X- Y++
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 147;
	pos.y2 = y + 17410;
	trace(pos, mlx, LYELLOW);//			7er octant X+ Y++
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1268;
	pos.y2 = y + 289;
	trace(pos, mlx, LGREEN);//			8e octant X++ Y+*/
	mlx_mouse_hook(mlx->win, test, (void*)0);
	mlx_key_hook(mlx->win, test, (void*)0);
	mlx_loop(mlx->ptr);
	return (0);
}
