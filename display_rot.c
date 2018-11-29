/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/29 16:57:32 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		yincr_rot(t_m m, int *x2, int *y2)
{
	*x2 = m.xinit + m.i * m.gap;
	*y2 = m.yinit + (m.j - 1) * m.gap;
	xrotate(&m);
	yrotate(&m);
	zrotate(&m);
}

void		xincr_rot(t_m m, int *x2, int *y2)
{
	*x2 = m.xinit + (m.i + 1) * m.gap;
	*y2 = m.yinit + m.j * m.gap;
	xrotate(&m);
	yrotate(&m);
	zrotate(&m);
}

void	first_back(t_m *m)
{
	m->x1 = m->tmpx + WIDTH / 2;
	m->y1 = m->tmpy + HEIGHT / 2;
//	draw(*m);
//	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	back(t_m *m)
{
	m->xinit = m->tmpx + WIDTH / 2;
	m->yinit = m->tmpy + HEIGHT / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
//	draw(*m);
//	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	init_rot(t_m *m)
{
	m->i = 0;
	m->j = 0;
	zero(m);
	first_x_rotate(m);
	first_y_rotate(m);
	first_z_rotate(m);
	first_back(m);
}

void	zero(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit = 0 - (m->column - 1) * m->initgap / 2;
	m->yinit = 0 - (m->line - 1) * m->initgap / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	m->tmpx = m->xinit;
	m->tmpy = m->yinit;
//	draw(*m);
//	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void		draw_rot(t_m m)
{
	m.i = 0;
	m.j = 0;
//	init_rot(&m);
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		if (m.j != 0)
		{
			yincr_rot(m, &(m.x2), &(m.y2));
			trace(m);
		}
		xincr_rot(m, &(m.x2), &(m.y2));
		trace(m);
		next(&m);
		m.i++;
		if (m.i == m.column - 1 && m.j != 0)
		{
			yincr_rot(m, &(m.x2), &(m.y2));
			trace(m);
		}
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.j++;
			m.i = 0;
			m.x1 = m.tmpx;
			m.y1 = (m.tmpy + m.j * m.gap) / 2;
		}
	}
}
