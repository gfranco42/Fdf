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

int		main()
{
	void	*ptr;
	void	*win;
	int		x;
	int		y;
	t_pos	pos;
	double	a;
	double	b;

	pos.x1 = 100;
	pos.y1 = 100;
	pos.x2 = 450;
	pos.y2 = 327;

	a = (double)(pos.y2 - pos.y1) / (pos.x2 - pos.x1);
	b = pos.y1 - a * pos.x1;
	ptr = mlx_init();
	win = mlx_new_window(ptr, 502, 500, "YOLO");
	x = pos.x1;
	mlx_pixel_put(ptr, win, pos.x1, pos.y1, 0x26F4ED);
	mlx_pixel_put(ptr, win, pos.x2, pos.y2, 0x26F4ED);
	while (x <= pos.x2)
	{
		y = (int)(a * x + b);
		mlx_pixel_put(ptr, win, x, y, 0xFE00F6);
		x++;
	}
	pos.x1 = 150;
	pos.y1 = 200;
	pos.x2 = 323;
	pos.y2 = 127;
	x = pos.x1;
	mlx_pixel_put(ptr, win, pos.x1, pos.y1, 0x26F4ED);
	mlx_pixel_put(ptr, win, pos.x2, pos.y2, 0x26F4ED);
	a = (double)(pos.y2 - pos.y1) / (pos.x2 - pos.x1);
	b = pos.y1 - a * pos.x1;
	while (x <= pos.x2)
	{
		y = (int)(a * x + b);
		mlx_pixel_put(ptr, win, x, y, 0x00FE11);
		x++;
	}
	mlx_key_hook(win, test, (void*)0);
	mlx_loop(ptr);
	return (0);
}
