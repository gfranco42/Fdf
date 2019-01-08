/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/07 12:07:16 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/08 15:57:53 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./includes/fdf.h"

void	iso(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
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
	if (m->str)
		ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
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
