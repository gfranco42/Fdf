/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/05 14:25:54 by gfranco           #+#    #+#             */
/*   Updated: 2019/02/04 11:22:03 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key(int key, void *param)
{
	t_m *m;

	m = (t_m*)param;
	if (key == 69 || key == 78)
		key_zoom(key, param);
	else if (key == 53 || key == 256)
		key_stop(key, param);
	else if (key == 124 || key == 123 || key == 125 || key == 126)
		key_move(key, param);
	else if (key == 33 || key == 35 || key == 71)
		key_clean(key, param);
	else if (key == 83 || key == 84 || key == 86 || key == 87 || key == 89 ||
			key == 91 || key == 82)
		key_rotate(key, param);
	else if (key == 18 || key == 19 || key == 20 || key == 21 || key == 23 ||
			key == 22 || key == 26 || key == 28 || key == 25 || key == 29 ||
			key == 27 || key == 24)
		key_sounds(key, param);
	else if (key == 15 || key == 17 || key == 31 || key == 34 || key == 32 ||
			key == 16 || key == 14 || key == 0 || key == 45 || key == 46)
		key_color(key, param);
	return (0);
}

void	init_variables(t_m *m)
{
	m->initgap = 50;
	m->gap = m->initgap;
	m->savegap = m->initgap;
	m->relief = 1;
	m->rel_v = 0.5;
	m->tab = NULL;
	m->array = NULL;
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
		ft_putstr("Failed to open file\n");
	if (i == 2)
		ft_putstr("usage: ./fdf target_file\n");
	if (i == 3)
		ft_putstr("ERROR: impossible to initialize mlx_ptr\n");
	if (i == 4)
		ft_putstr("ERROR: window size must be 2560x1400\n");
	if (i == 5)
		ft_putstr("ERROR: incorrect map\n");
	if (i == 6)
		ft_putstr("ERROR: empty file\n");
	if (i == 7)
		ft_putstr("ERROR: file doesn't exist\n");
	exit(0);
}

int		main(int ac, char **av)
{
	t_m			m;

	if (ac != 2)
		fail(2);
	if (!av[1])
		fail(7);
	m.av = av[1];
	if (!(m.ptr = mlx_init()))
		fail(3);
	if (WIDTH != 2560 || HEIGHT != 1400)
		fail(4);
	init_variables(&m);
	first_draw(&m);
	m.win = mlx_new_window(m.ptr, WIDTH, HEIGHT, "FDF GFRANCO");
	m.img = mlx_new_image(m.ptr, WIDTH, HEIGHT);
	m.str = mlx_get_data_addr(m.img, &(m.bpp), &(m.s_l), &(m.endian));
	draw_rot(m);
	mlx_put_image_to_window(m.ptr, m.win, m.img, 0, 0);
	string_to_window(&m);
	mlx_hook(m.win, KEYPRESS, KEYPRESSMASK, key, &m);
	mlx_loop(m.ptr);
	return (0);
}
