/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event_rot2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/09 15:23:23 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:28:06 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int		key_rotate_z1(int key, void *param)
{
	t_m	*m;
	int	fd;

	m = (t_m *)param;
	if (key == 89)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ztheta -= 0.2;
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

int		key_rotate_z2(int key, void *param)
{
	t_m	*m;
	int	fd;

	m = (t_m *)param;
	if (key == 91)
	{
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
		mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
		m->ztheta += 0.2;
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
