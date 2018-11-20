/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/20 18:10:26 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdio.h>
#include "fdf.h"

int		test(int key, void *param)
{
	t_all *a;

	a = (t_all *)param;
	if (key == 53)
		exit(0);
	if (key == 69)
	{
		a->t->gap += 2;
		mlx_clear_window(a->t->ptr, a->t->win);
		draw(a->t, a->v, a->s);
		printf("gap = %d\n", a->t->gap);
	}
	if (key == 78)
	{
		a->t->gap -= 2;
		mlx_clear_window(a->t->ptr, a->t->win);
		draw(a->t, a->v, a->s);
		printf("gap = %d\n", a->t->gap);
	}
	else
		ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

void	trace1(t_tool *t, t_trace s, int color)
{
	int		i;

	i = 0;
	while (i++ <= s.cx)
	{
		mlx_pixel_put(t->ptr, t->win, s.x1, s.y1, color);
		s.x1 = s.x1 > s.x2 ? (s.x1 - 1) : (s.x1 + 1);
		s.ex -= s.dy;
		if (s.ex < 0)
		{
			s.y1 = s.y1 > s.y2 ? (s.y1 - 1) : (s.y1 + 1);
			s.ex += s.dx;
		}
	}
}

void	trace2(t_tool *t, t_trace s, int color)
{
	int		i;

	i = 0;
	while (i++ <= s.cy)
	{
		mlx_pixel_put(t->ptr, t->win, s.x1, s.y1, color);
		s.y1 = s.y1 > s.y2 ? (s.y1 - 1) : (s.y1 + 1);
		s.ey -= s.dx;
		if (s.ey < 0)
		{
			s.x1 = s.x1 > s.x2 ? (s.x1 - 1) : (s.x1 + 1);
			s.ey += s.dy;
		}
	}
}

void	trace(t_tool *t, t_trace s, int color)
{
	s.ex = abs(s.x2 - s.x1);
	s.ey = abs(s.y2 - s.y1);
	s.dx = 2 * s.ex;
	s.dy = 2 * s.ey;
	s.cx = s.ex;
	s.cy = s.ey;
	if (s.cx > s.cy)
		trace1(t, s, color);
	else
		trace2(t, s, color);
}

int		main(int ac, char **av)
{
	t_tool		*t;
	t_trace		s;
	t_tri		v;
	t_all		a;
	int			**array;
	int			fd;
	int			line;
	int			column;

	if (!(t = (t_tool*)malloc(sizeof(*t))))
		exit(0);
	t->ptr = mlx_init();
	t->win = mlx_new_window(t->ptr, WIDTH, HEIGHT, "YOLO");

	t->line = 0;
	t->column = 0;
	t->gap = 20;
	v.i = 0;
	v.j = 0;
	v.k = 0;
	if (ac != 2)
	{
		printf("\033[1;33mNEED FILE ! ! !\033[0m\n");
		return (0);
	}
	array = stock(av[1], t);
	t->xinit = WIDTH / 2 - (t->column * t->gap) / 2;
	t->yinit = HEIGHT / 2 - (t->line * t->gap) / 2;
	s.x1 = t->xinit;
	s.y1 = t->yinit;
	fd = open(av[1], O_RDONLY);
	array = fill(array, t, fd, v);
	draw(t, v, s);
	mlx_key_hook(t->win, test, t);
	mlx_loop(t->ptr);
	return (0);
}
