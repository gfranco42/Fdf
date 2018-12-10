/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/10 18:31:54 by gfranco          ###   ########.fr       */
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
	{
		system("killall afplay");
		exit(0);
	}
	else if (key == 256)
		system("killall afplay");
	else if (key == 69)
	{
		m->gap *= 1.1;
		redraw_zoom_in(m);
	}
	else if (key == 78)
	{
		m->gap *= 0.9;
		redraw_zoom_out(m);
	}
	return (0);
}

int		key_move(int key, void *param)
{
	t_m *m;

	m = (t_m *)param;
	if (key == 123)
		redraw_move(m, -20, 0);
	else if(key == 124)
		redraw_move(m, 20, 0);
	else if (key == 126)
		redraw_move(m, 0, -20);
	else if (key == 125)
		redraw_move(m, 0, 20);
	else if (key == 71)
		paralelle(m);
	return (0);
}

int		key_clean(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (key == 34)// iso
		iso(m);
	else if (key == 35)// para
		paralelle(m);
	else if (key == 8)// conique
		conique(m);
	return (0);
}

int		key_rotate(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;

	if (key == 84)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->xtheta += 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	}
	else if (key == 83)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->xtheta -= 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	}
	else if (key == 87)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ytheta += 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	}
	else if (key == 86)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ytheta -= 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	}
	else if (key == 91)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ztheta += 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	}
	else if (key == 89)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ztheta -= 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	}
	return (0);
}

int		key_sound(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 18)// 1
	{
		system("killall afplay");
		system("afplay ~/Musics/ONE_PUNCH.wav &");
	}
	else if (key == 19)// 2
	{
		system("killall afplay");
		system("afplay ~/musics/ACDC &");
	}
	else if (key == 20)// 3
	{
		system("killall afplay");
		system("afplay ~/Musics/AVICII &");
	}
	else if (key == 21)// 4
	{
		system("killall afplay");
		system("afplay ~/Musics/BoW &");
	}
	else if (key == 23)// 5
	{
		system("killall afplay");
		system("afplay ~/Musics/NARUTO &");
	}
	else if (key == 22)// 6
	{
		system("killall afplay");
		system("afplay ~/Musics/EMINEM &");
	}
	else if (key == 26)// 7
	{
		system("killall afplay");
		system("afplay ~/Musics/FUNKYCOPS &");
	}
	else if (key == 28)// 8
	{
		system("killall afplay");
		system("afplay ~/Musics/BACH &");
	}
	else if (key == 25)// 9
	{
		system("killall afplay");
		system("afplay ~/Musics/ARMSTRONG &");
	}
	else if (key == 29)// 0
	{
		system("killall afplay");
		system("afplay ~/Musics/ELECRICITY &");
	}
	else if (key == 27)// -
	{
		system("killall afplay");
		system("afplay ~/Musics/SSBM &");
	}
	else if (key == 24)// =
	{
		system("killall afplay");
		system("afplay ~/Musics/IRONMAIDEN &");
	}
	return (0);
}

int		key(int key, void *param)
{
	t_m *m;

	m = (t_m*)param;
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 71)
		key_move(key, param);
	else if (key == 69 || key == 78 || key == 53 || key == 256)
		key_zoom(key, param);
	else if (key == 34 || key == 35 || key == 8)
		key_clean(key, param);
	else if (key == 83 || key == 84 || key == 86 || key == 87 || key == 89 ||
			key == 91 || key == 82 || key == 65)
		key_rotate(key, param);
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23 ||
			key == 22 || key == 26 || key == 28 || key == 25 || key == 29 ||
			key == 27 || key == 24)
		key_sound(key, param);
	ft_putnbr(key);
	ft_putchar('|');
	return (0);
}

void	trace1(t_m m)
{
	m.i = 0;
	while (m.i++ <= m.cx/* && m.y1 < HEIGHT && m.y1 > 0*/)
	{
		if (m.x1 > 0 && m.x1 < WIDTH && m.y1 < HEIGHT && m.y1 > 0)
		{
			m.str[(m.x1 + m.y1 * WIDTH) * 4] = m.blue;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 1] = m.green;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 2] = m.red;
		}
//		mlx_pixel_put(m.ptr, m.win, m.x1, m.y1, color);
		m.x1 = m.x1 > m.x2 ? (m.x1 - 1) : (m.x1 + 1);
		m.ex -= m.dy;
		if (m.ex < 0)
		{
			m.y1 = m.y1 > m.y2 ? (m.y1 - 1) : (m.y1 + 1);
			m.ex += m.dx;
		}
	}
}

void	trace2(t_m m)
{
	m.i = 0;
	while (m.i++ <= m.cy/* && m.x1 < WIDTH && m.x1 > 0*/)
	{
		if (m.y1 < HEIGHT && m.y1 > 0 && m.x1 < WIDTH && m.x1 > 0)
		{
			m.str[(m.x1 + m.y1 * WIDTH) * 4] = m.blue;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 1] = m.green;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 2] = m.red;
		}
//		mlx_pixel_put(m.ptr, m.win, m.x1, m.y1, color);
		m.y1 = m.y1 > m.y2 ? (m.y1 - 1) : (m.y1 + 1);
		m.ey -= m.dx;
		if (m.ey < 0)
		{
			m.x1 = m.x1 > m.x2 ? (m.x1 - 1) : (m.x1 + 1);
			m.ey += m.dy;
		}
	}
}

void	trace(t_m m)
{
	m.ex = abs(m.x2 - m.x1);
	m.ey = abs(m.y2 - m.y1);
	m.dx = 2 * m.ex;
	m.dy = 2 * m.ey;
	m.cx = m.ex;
	m.cy = m.ey;
	if (m.cx > m.cy)
		trace1(m);
	else
		trace2(m);
}

int		main(int ac, char **av)
{
	t_m			m;
//	int			**array;
	int			fd;

	m.ptr = mlx_init();
	m.img = mlx_new_image(m.ptr, WIDTH, HEIGHT);
	m.str = mlx_get_data_addr(m.img, &(m.bpp), &(m.s_l), &(m.endian));
	m.win = mlx_new_window(m.ptr, WIDTH, HEIGHT, "YOLO");

	m.initgap = 50;
	m.gap = m.initgap;
	m.savegap = m.initgap;
	m.red = 0xff;
	m.green = 0xff;
	m.blue = 0xff;
	m.xtheta = 0;
	m.ytheta = 0;
	m.ztheta = 0;
	m.z = 0;
	m.i = 0;
	m.j = 0;
	m.k = 0;
	m.xout = 0;
	m.yout = 0;
	if (ac != 2)
	{
		printf("\033[1;33mNEED FILE ! ! !\033[0m\n");
		return (0);
	}
	m.array = stock(av[1], &m);
/*	m.lencolumn = (m.column - 1) * m.gap;
	m.lenline = (m.line - 1) * m.gap;
	m.xinit = WIDTH / 2 - m.lencolumn / 2;
	m.yinit = HEIGHT / 2 - m.lenline / 2;
	m.x1 = m.xinit;
	m.y1 = m.yinit;*/
	if ((fd = open(av[1], O_RDONLY)) == -1)
	{
		ft_putstr("Failed to open <FILE>\n");
		exit(EXIT_FAILURE);
	}
	m.array = fill(fd, m);
	paralelle(&m);
	mlx_put_image_to_window(m.ptr, m.win, m.img, 0, 0);
	mlx_hook(m.win, KEYPRESS, KEYPRESSMASK, key, &m);
//	mlx_key_hook(m.win, key, &m);
//	mlx_mouse_hook(m.win, mouse, &m);
	mlx_loop(m.ptr);
	return (0);
}
