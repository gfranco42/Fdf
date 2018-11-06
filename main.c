/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/06 17:54:24 by gfranco          ###   ########.fr       */
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
	return (0);
}

void	trace(t_pos pos, t_mlx *mlx, int color)
{
	double	a;
	double	b;
	int		x;
	int		y;

	a = (double)(pos.y2 - pos.y1) / (pos.x2 - pos.x1);
	printf("a = %f\n", a);
	b = (double)pos.y1 - a * pos.x1;
	printf("b = %f\n", b);
	x = pos.x1;
	while (x >= pos.x2)
	{
		y = (double)(a * x + b);
//		printf("|%d", x);
		mlx_pixel_put(mlx->ptr, mlx->win, x, y, color);
//		printf("|%d", y);
		x--;
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
	pos.x2 = x + 500;
	pos.y2 = y + 750;
	trace(pos, mlx, LYELLOW);//			4er octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 500;
	pos.y2 = y + 250;
	trace(pos, mlx, LGREEN);//			3e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 500;
	pos.y2 = y - 250;
	trace(pos, mlx, LPURPLE);//			2e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x + 500;
	pos.y2 = y - 750;
	trace(pos, mlx, LBLUE);//			1e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x - 500;
	pos.y2 = y - 750;
	trace(pos, mlx, DORANGE);//			8e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x - 500;
	pos.y2 = y - 250;
	trace(pos, mlx, DGREEN);//			7e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x - 500;
	pos.y2 = y + 250;
	trace(pos, mlx, DPURPLE);//			6e octant
	pos.x1 = x;
	pos.y1 = y;
	pos.x2 = x - 500;
	pos.y2 = y + 750;
	trace(pos, mlx, DBLUE);//			5e octant
	mlx_key_hook(mlx->win, test, (void*)0);
	mlx_loop(mlx->ptr);
	return (0);
}
