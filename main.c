/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/21 17:50:36 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"

int		key_zoom(int key, void *param)
{
	t_m *m;

	m = (t_m *)param;
	if (key == 53)
		exit(0);
	if (key == 69)
	{
		m->gap *= 1.1;
		redraw_zoom_in(m);
	}
	if (key == 78)
	{
		m->gap *= 0.9;
		redraw_zoom_out(m);
	}
	ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

int		key_move(int key, void *param)
{
	t_m *m;

	m = (t_m *)param;
	if (key == 124)
		redraw_move(m, -20, 0);
	else if(key == 123)
		redraw_move(m, 20, 0);
	else if (key == 125)
		redraw_move(m, 0, -20);
	else if (key == 126)
		redraw_move(m, 0, 20);
	else if (key == 71)
		clean(m);
	ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

int		key(int key, void *param)
{
	int		a;
	int		b;
	t_m *m;

	m = (t_m*)param;
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 71)
		key_move(key, param);
	else if (key == 69 || key == 78 || key == 53)
		key_zoom(key, param);
	return (0);
}

void	trace1(t_m m, int color)
{
	m.i = 0;
	while (m.i++ <= m.cx)
	{
		mlx_pixel_put(m.ptr, m.win, m.x1, m.y1, color);
		m.x1 = m.x1 > m.x2 ? (m.x1 - 1) : (m.x1 + 1);
		m.ex -= m.dy;
		if (m.ex < 0)
		{
			m.y1 = m.y1 > m.y2 ? (m.y1 - 1) : (m.y1 + 1);
			m.ex += m.dx;
		}
	}
}

void	trace2(t_m m, int color)
{
	m.i = 0;
	while (m.i++ <= m.cy)
	{
		mlx_pixel_put(m.ptr, m.win, m.x1, m.y1, color);
		m.y1 = m.y1 > m.y2 ? (m.y1 - 1) : (m.y1 + 1);
		m.ey -= m.dx;
		if (m.ey < 0)
		{
			m.x1 = m.x1 > m.x2 ? (m.x1 - 1) : (m.x1 + 1);
			m.ey += m.dy;
		}
	}
}

void	trace(t_m m, int color)
{
	m.ex = abs(m.x2 - m.x1);
	m.ey = abs(m.y2 - m.y1);
	m.dx = 2 * m.ex;
	m.dy = 2 * m.ey;
	m.cx = m.ex;
	m.cy = m.ey;
	if (m.cx > m.cy)
		trace1(m, color);
	else
		trace2(m, color);
}

int		main(int ac, char **av)
{
	t_m			m;
	int			**array;
	int			fd;

	m.ptr = mlx_init();
	m.win = mlx_new_window(m.ptr, WIDTH, HEIGHT, "YOLO");

	m.initgap = 50;
	m.gap = m.initgap;
	m.savegap = m.initgap;
	m.i = 0;
	m.j = 0;
	m.k = 0;
	if (ac != 2)
	{
		printf("\033[1;33mNEED FILE ! ! !\033[0m\n");
		return (0);
	}
	array = stock(av[1], &m);
	m.lencolumn = (m.column - 1) * m.gap;
	m.lenline = (m.line - 1) * m.gap;
	m.xinit = WIDTH / 2 - m.lencolumn / 2;
	m.yinit = HEIGHT / 2 - m.lenline / 2;
	m.x1 = m.xinit;
	m.y1 = m.yinit;
	fd = open(av[1], O_RDONLY);
	array = fill(array, fd, m);
	draw(m);
	mlx_key_hook(m.win, key, &m);
//	mlx_key_hook(m.win, key_zoom, &m);
//	mlx_key_hook(m.win, key_move, &m);
//	mlx_mouse_hook(m.win, mouse, &m);
	mlx_loop(m.ptr);
	return (0);
}
