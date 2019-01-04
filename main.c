/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/04 14:42:18 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

int		key_zoom(int key, void *param)
{
	t_m *m;

	m = (t_m *)param;
	printf("relief : %f\n", m->relief);
	if (key == 53)
	{
		if (m->k != 0)
			system("killall afplay");
		exit(0);
	}
	else if (key == 256)
	{
		if (m->k != 0)
		{
			system("killall afplay");
			m->k = 0;
		}
	}
	else if (key == 69)
	{
		m->gap *= 1.1;
		m->relief *= 1.1;
		redraw_zoom_in(m);
	}
	else if (key == 78)
	{
		m->gap *= 0.9;
		m->relief *= 0.9;
		redraw_zoom_out(m);
	}
	else if (key == 88)
	{
		m->relief += 0.3;
		redraw_relief(m);
	}
	else if (key == 85)
	{
		m->relief -= 0.3;
		redraw_relief(m);
	}
	return (0);
}

int		key_move(int key, void *param)
{
	t_m *m;

	m = (t_m *)param;
	if (key == 124)
		redraw_move(m, 20, 0);
	else if(key == 123)
		redraw_move(m, -20, 0);
	else if (key == 125)
		redraw_move(m, 0, 20);
	else if (key == 126)
		redraw_move(m, 0, -20);
	else if (key == 71)
	{
		m->relief = 1;
		m->alpha = 0;
		m->dblue = 0xff;
		m->dgreen = 0xff;
		m->dred = 0xff;
		parallele(m);
	}
	return (0);
}

int		key_clean(int key, void *param)
{
	t_m	*m;

	m = (t_m *)param;
	if (key == 33)
		iso(m);
	else if (key == 35)
		parallele(m);
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
		string_to_window(m);
	}
	else if (key == 83)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->xtheta -= 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	else if (key == 87)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ytheta += 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	else if (key == 86)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ytheta -= 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	else if (key == 91)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ztheta += 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	else if (key == 89)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ztheta -= 0.1;
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	return (0);
}

int		key_sound(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 18)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/ONE_PUNCH.wav &");
		m->k = 1;
	}
	else if (key == 19)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/ACDC &");
		m->k = 1;
	}
	else if (key == 20)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/AVICII &");
		m->k = 1;
	}
	else if (key == 21)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/BoW &");
		m->k = 1;
	}
	else if (key == 23)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/NARUTO &");
		m->k = 1;
	}
	else if (key == 22)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/EMINEM &");
		m->k = 1;
	}
	else if (key == 26)
	{
			system("killall afplay");
		system("afplay ./musics/FUNKYCOPS &");
		m->k = 1;
	}
	else if (key == 28)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/BACH &");
		m->k = 1;
	}
	else if (key == 25)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/ARMSTRONG &");
		m->k = 1;
	}
	else if (key == 29)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/ELECRICITY &");
		m->k = 1;
	}
	else if (key == 27)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/SSBM &");
		m->k = 1;
	}
	else if (key == 24)
	{
		if (m->k != 0)
			system("killall afplay");
		system("afplay ./musics/IRONMAIDEN &");
		m->k = 1;
	}
	return (0);
}

int		key_color(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 45)
	{
		if (m->alpha + 16 != 0)
			m->alpha += 16;
		redraw_relief(m);
	}
	if (key == 46)
	{
		if (m->alpha - 16 != 0)
			m->alpha -= 16;
		redraw_relief(m);
	}
	if (key == 0)
	{
		m->dred = rand();
		m->dgreen = rand();
		m->dblue = rand();
		redraw_relief(m);
	}
	if (key == 15)
	{
		m->dred = 0xff;
		m->dgreen = 0;
		m->dblue = 0;
		redraw_relief(m);
	}
	if (key == 17)
	{
		m->dgreen = 0xff;
		m->dred = 0;
		m->dblue = 0;
		redraw_relief(m);
	}
	if (key == 16)
	{
		m->dblue = 0xff;
		m->dgreen = 0;
		m->dred = 0;
		redraw_relief(m);
	}
	if (key == 32)
	{
		m->dred = 0xff;
		m->dgreen = 0x9b;
		m->dblue = 0;
		redraw_relief(m);
	}
	if (key == 34)
	{
		m->dred = 0xe6;
		m->dgreen = 0;
		m->dblue = 0xff;
		redraw_relief(m);
	}
	if (key == 31)
	{
		m->dred = 0xff;
		m->dgreen = 0xf0;
		m->dblue = 0;
		redraw_relief(m);
	}
	if (key == 14)
	{
		m->dred = 0xff;
		m->dgreen = 0xff;
		m->dblue = 0xff;
		redraw_relief(m);
	}
	return (0);
}

int		key(int key, void *param)
{
	t_m *m;

	m = (t_m*)param;
	if (key == 123 || key == 124 || key == 125 || key == 126 || key == 71)
		key_move(key, param);
	else if (key == 69 || key == 78 || key == 53 || key == 256 || key == 88 ||
			key == 85)
		key_zoom(key, param);
	else if (key == 33 || key == 35)
		key_clean(key, param);
	else if (key == 83 || key == 84 || key == 86 || key == 87 || key == 89 ||
			key == 91 || key == 82 || key == 65)
		key_rotate(key, param);
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23 ||
			key == 22 || key == 26 || key == 28 || key == 25 || key == 29 ||
			key == 27 || key == 24)
		key_sound(key, param);
	else if (key == 15 || key == 17 || key == 31 || key == 34 || key == 32 ||
			 key == 16 || key == 14 || key == 0 || key == 45 || key == 46)
		key_color(key, param);
	return (0);
}

void	trace1(t_m m)
{
	m.i = 0;
	while (m.i++ <= m.cx)
	{
		if (m.x1 > 0 && m.x1 < WIDTH && m.y1 < HEIGHT && m.y1 > 0)
		{
			m.str[(m.x1 + m.y1 * WIDTH) * 4] = m.blue + m.dblue;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 1] = m.green + m.dgreen;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 2] = m.red + m.dred;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 3] = m.alpha;
		}
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
	while (m.i++ <= m.cy)
	{
		if (m.y1 < HEIGHT && m.y1 > 0 && m.x1 < WIDTH && m.x1 > 0)
		{
			m.str[(m.x1 + m.y1 * WIDTH) * 4] = m.blue + m.dblue;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 1] = m.green + m.dgreen;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 2] = m.red + m.dred;
			m.str[(m.x1 + m.y1 * WIDTH) * 4 + 3] = m.alpha;
		}
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

void	init_variables(t_m *m)
{
	m->img = mlx_new_image(m->ptr, WIDTH, HEIGHT);
	m->str = mlx_get_data_addr(m->img, &(m->bpp), &(m->s_l), &(m->endian));
	m->win = mlx_new_window(m->ptr, WIDTH, HEIGHT, "FDF GFRANCO");
	m->initgap = 50;
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->relief = 1;
	m->tab = NULL;
	m->red = 0;
	m->green = 0;
	m->blue = 0;
	m->alpha = 0;
	m->dred = 0xff;
	m->dgreen = 0xff;
	m->dblue = 0xff;
	m->xtheta = 0;
	m->ytheta = 0;
	m->ztheta = 0;
	m->z = 0;
	m->i = 0;
	m->j = 0;
	m->k = 0;
	m->xout = 0;
	m->yout = 0;
}

void	fail(int i)
{
	if (i == 1)
		ft_putstr("Failed to open <FILE>\n");
	if (i == 2)
		ft_putstr("usage: ./fdf target_file\n");
	if (i == 3)
		ft_putstr("ERROR: impossible to initialize mlx_ptr\n");
	if (i == 4)
		ft_putstr("ERROR: Window size must be 2560x1400\n");
	exit(0);
}

int		main(int ac, char **av)
{
	t_m			m;
	int			fd;

	if (ac != 2)
		fail(2);
	if (!(m.ptr = mlx_init()))
		fail(3);
	if (WIDTH != 2560 || HEIGHT != 1400)
		fail(4);
	init_variables(&m);
	m.array = stock(av[1], &m);
	if ((fd = open(av[1], O_RDONLY)) == -1)
		fail(1);
	m.array = fill(fd, m);
	parallele(&m);
	mlx_hook(m.win, KEYPRESS, KEYPRESSMASK, key, &m);
	mlx_loop(m.ptr);
	return (0);
}
