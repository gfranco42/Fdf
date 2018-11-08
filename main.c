/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/08 19:31:39 by gfranco          ###   ########.fr       */
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

void	trace(t_pos pos, t_mlx *mlx, int color)
{
	int		e;
	int		dx;
	int		dy;

	e = abs(pos.x2 - pos.x1);
	dx = 2 * e;
	dy = 2 * abs(pos.y2 - pos.y1);

	while (pos.x1 <= pos.x2)
	{
		pos.x1++;
		e -= dy;
		if (e < 0)
		{
			pos.y1--;
			e += dx;
		}
	}
}

int		main()
{
	t_mlx	*mlx;
	t_pos	pos;
	int		count;
	int		x = WIDTH / 2;
	int		y = HEIGHT / 2;
	double	a;
	double	b;
	int		line;

	line = 4 + 1;

	mlx->ptr = mlx_init();
	mlx->win = mlx_new_window(mlx->ptr, WIDTH, HEIGHT, "YOLO");


	count = 0;


	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1000;
	pos.y2 = y + 100;
	trace(pos, mlx, LPURPLE);//			1e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1000;
	pos.y2 = y + 200;
	trace(pos, mlx, LBLUE);//			2e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1000;
	pos.y2 = y + 300;
	trace(pos, mlx, DORANGE);//			3e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1000;
	pos.y2 = y + 400;
	trace(pos, mlx, DGREEN);//			4e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1000;
	pos.y2 = y + 500;
	trace(pos, mlx, DPURPLE);//			5e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1000;
	pos.y2 = y + 600;
	trace(pos, mlx, DBLUE);//			6e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1000;
	pos.y2 = y + 700;
	trace(pos, mlx, LYELLOW);//			7er octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 1000;
	pos.y2 = y + 800;
	trace(pos, mlx, LGREEN);//			8e octant
	mlx_mouse_hook(mlx->win, test, (void*)0);
	mlx_key_hook(mlx->win, test, (void*)0);
	mlx_loop(mlx->ptr);
	return (0);
}
