/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:07:16 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/09 13:21:35 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	iso(t_m *m)
{
	int		fd;

	mlx_destroy_image(m->ptr, m->img);
	m->img = mlx_new_image(m->ptr, WIDTH, HEIGHT);
	m->str = mlx_get_data_addr(m->img, &(m->bpp), &(m->s_l), &(m->endian));
	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	m->gap = m->initgap;
	while (m->gap * m->line > HEIGHT - 200 || m->gap * m->column > WIDTH - 200)
		m->gap *= 0.9;
	m->savegap = m->gap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	m->xtheta = 0.6;
	m->ytheta = -0.6;
	m->ztheta = 0.6;
	m->relief = 5.2;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}

void	parallele(t_m *m)
{
	int		fd;

	m->img = mlx_new_image(m->ptr, WIDTH, HEIGHT);
	m->str = mlx_get_data_addr(m->img, &(m->bpp), &(m->s_l), &(m->endian));
	stock(m->av, m);
	if ((fd = open(m->av, O_RDONLY)) == -1)
		fail(1);
	m->array = fill(fd, *m);
	m->gap = m->initgap;
	while (m->gap * m->line > HEIGHT - 200 || m->gap * m->column > WIDTH - 200)
		m->gap *= 0.9;
	m->savegap = m->gap;
	m->xinit = WIDTH / 2 - ((m->column - 1) * m->gap) / 2;
	m->yinit = HEIGHT / 2 - ((m->line - 1) * m->gap) / 2;
	m->xtheta = 0;
	m->ytheta = 0;
	m->ztheta = 0;
	m->relief = 5.2;
	draw_rot(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	string_to_window(m);
}
