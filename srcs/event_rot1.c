/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rot1.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:34:42 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:28:02 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_rotate_x1(int key, void *param)
{
	t_m	*m;
	int	fd;

	m = (t_m *)param;
	if (key == 83)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->xtheta -= 0.2;
		stock(m->av, m);
		if ((fd = open(m->av, O_RDONLY)) == -1)
			fail(1);
		m->array = fill(fd, *m);
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	return (0);
}

int		key_rotate_x2(int key, void *param)
{
	t_m	*m;
	int	fd;

	m = (t_m *)param;
	if (key == 84)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->xtheta += 0.2;
		stock(m->av, m);
		if ((fd = open(m->av, O_RDONLY)) == -1)
			fail(1);
		m->array = fill(fd, *m);
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	return (0);
}

int		key_rotate_y1(int key, void *param)
{
	t_m	*m;
	int	fd;

	m = (t_m *)param;
	if (key == 86)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ytheta -= 0.2;
		stock(m->av, m);
		if ((fd = open(m->av, O_RDONLY)) == -1)
			fail(1);
		m->array = fill(fd, *m);
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	return (0);
}

int		key_rotate_y2(int key, void *param)
{
	t_m	*m;
	int	fd;

	m = (t_m *)param;
	if (key == 87)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ytheta += 0.2;
		stock(m->av, m);
		if ((fd = open(m->av, O_RDONLY)) == -1)
			fail(1);
		m->array = fill(fd, *m);
		draw_rot(*m);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		string_to_window(m);
	}
	return (0);
}

int		key_rotate(int key, void *param)
{
	t_m	*m;

	m = (t_m*)param;
	if (key == 83)
		key_rotate_x1(key, param);
	else if (key == 84)
		key_rotate_x2(key, param);
	else if (key == 86)
		key_rotate_y1(key, param);
	else if (key == 87)
		key_rotate_y2(key, param);
	else if (key == 89)
		key_rotate_z1(key, param);
	else if (key == 91)
		key_rotate_z2(key, param);
	return (0);
}
