/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/16 18:44:38 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"

int		test2(int key, int *gap)
{
	if (key == 78)
		*gap -= 2;
	else if (key == 69)
		*gap += 2;
	else
		ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

int		test(int key, void *param)
{
	if (key == 53)
		exit(0);
	else
		ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

void	trace1(t_pos pos, t_mlx mlx, t_trace s, int color)
{
	int		i;

	i = 0;
	while (i++ <= s.cx)
	{
		mlx_pixel_put(mlx.ptr, mlx.win, pos.x1, pos.y1, color);
		pos.x1 = pos.x1 > pos.x2 ? (pos.x1 - 1) : (pos.x1 + 1);
		s.ex -= s.dy;
		if (s.ex < 0)
		{
			pos.y1 = pos.y1 > pos.y2 ? (pos.y1 - 1) : (pos.y1 + 1);
			s.ex += s.dx;
		}
	}
}

void	trace2(t_pos pos, t_mlx mlx, t_trace s, int color)
{
	int		i;

	i = 0;
	while (i++ <= s.cy)
	{
		mlx_pixel_put(mlx.ptr, mlx.win, pos.x1, pos.y1, color);
		pos.y1 = pos.y1 > pos.y2 ? (pos.y1 - 1) : (pos.y1 + 1);
		s.ey -= s.dx;
		if (s.ey < 0)
		{
			pos.x1 = pos.x1 > pos.x2 ? (pos.x1 - 1) : (pos.x1 + 1);
			s.ey += s.dy;
		}
	}
}

void	trace(t_pos pos, t_mlx mlx, t_trace s, int color)
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

int		main(int ac, char **av)
{
	t_mlx		mlx;
	t_pos		pos;
	t_init		init;
	t_tri		t;
	t_trace		s;
	int			**array;
	int			fd;
	int			line;
	int			column;

	mlx.ptr = mlx_init();
	mlx.win = mlx_new_window(mlx.ptr, WIDTH, HEIGHT, "YOLO");

	line = 0;
	column = 0;
	init.gap = 20;
	t.i = 0;
	t.j = 0;
	t.k = 0;
	if (ac != 2)
	{
		printf("\033[1;33mNEED FILE ! ! !\033[0m\n");
		return (0);
	}
	array = stock(av[1], &line, &column);
	init.x = WIDTH / 2 - (column * init.gap) / 2;
	init.y = HEIGHT / 2 - (line * init.gap) / 2;
	pos.x1 = init.x;
	pos.y1 = init.y;
	fd = open(av[1], O_RDONLY);
	array = fill(array, t, fd);
	while (t.i < column - 1 || t.j < line - 1)
	{
		if (t.j != 0)
		{
			printf("YOLO\n");
			yincr(&pos.x2, &pos.y2, t, init);
			trace(pos, mlx, s, DGREEN);
		}
		xincr(&pos.x2, &pos.y2, t, init);// donne valeur au point a relier
		printf("x1: %d, y1: %d\n", pos.x1, pos.y1);
		printf("x2: %d, y2: %d\n\n", pos.x2, pos.y2);
		trace(pos, mlx, s, DBLUE);// trace x1;y1 a x2;y2
		move(&pos.x1, &pos.y1, pos.x2, pos.y2);// je deplace x1;y1
		t.i++;
		if (t.i == column - 1 && t.j != 0)
		{
			yincr(&pos.x2, &pos.y2, t, init);
			trace(pos, mlx, s, DGREEN);
		}
		if (t.i == column - 1 && t.j != line - 1)
		{
			t.j++;
			t.i = 0;
			pos.x1 = init.x;
			pos.y1 = init.y + t.j * init.gap;
		}
	}
//	mlx = malloc(sizeof(t_mlx));
/*	pos.x1 = Xinit;
	pos.y1 = Yinit;
	pos.x2 = 590;
	pos.y2 = 190;*/
/*	count = 0;
	trace(pos, mlx, s, LGREEN);
	pos.x1 = 410;
	pos.y1 = (190 + 120);
	pos.x2 = 500;
	pos.y2 = (280 + 120);
	trace(pos, mlx, s, LPURPLE);
	pos.x1 = pos.x2;
	pos.y1 = pos.y2;
	pos.x2 = 590;
	pos.y2 = (190 + 120);
	trace(pos, mlx, s, DPURPLE);
	pos.x1 = 410;
	pos.y1 = 190;
	pos.x2 = 500;
	pos.y2 = 280;
	trace(pos, mlx, s, DBLUE);
	pos.x1 = 410;
	pos.y1 = 190;
	pos.x2 = 500;
	pos.y2 = 100;
	trace(pos, mlx, s, DGREEN);
	pos.x2 = pos.x1;
	pos.y2 = pos.y1 + 120;
	trace(pos, mlx, s, DORANGE);
	pos.x1 = 590;
	pos.y1 = 190;
	pos.x2 = pos.x1;
	pos.y2 = pos.y1 + 120;
	trace(pos, mlx, s, LYELLOW);
	pos.x1 = 500;
	pos.y1 = 280;
	pos.x2 = pos.x1;
	pos.y2 = pos.y1 + 120;
	trace(pos, mlx, s, LORANGE);
	pos.x1 = 500;
	pos.y1 = 280;
	pos.x2 = 590;
	pos.y2 = 190;
	trace(pos, mlx, s, LBLUE);*/
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
	mlx_mouse_hook(mlx.win, test2, (void*)0);
	mlx_key_hook(mlx.win, test, (void*)0);
	mlx_key_hook(mlx.win, test2, (void*)0);
	mlx_loop(mlx.ptr);
	return (0);
}
