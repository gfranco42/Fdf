/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/29 17:44:29 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_back(t_m *m)
{
	m->x1 = m->tmpx + WIDTH / 2;
	m->y1 = m->tmpy + HEIGHT / 2;
//	draw(*m);
//	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void	back(t_m *m)
{
	m->x2 = m->tmpx + WIDTH / 2;
	m->y2 = m->tmpy + HEIGHT / 2;
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

void		yincr_rot(t_m *m, int *x2, int *y2)
{
	(void)x2;
	(void)y2;
	/*x2*/m->x2 = m->tmpx + m->i * m->gap;
	/*y2*/m->y2 = m->tmpy + (m->j - 1) * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	back(m);
}

void		xincr_rot(t_m *m, int *x2, int *y2)
{
	printf("1x2: %d, 1y2 %d\n", *x2, *y2);
	/*x2*/m->x2 = m->tmpx + (m->i + 1) * m->gap;
	printf("2x2: %d, 2y2 %d\n", *x2, *y2);
	/*y2*/m->y2 = m->tmpy + m->j * m->gap;
	printf("3x2: %d, 3y2 %d\n", *x2, *y2);
	xrotate(m);
	printf("4x2: %d, 4y2 %d\n", *x2, *y2);
	yrotate(m);
	printf("5x2: %d, 5y2 %d\n", *x2, *y2);
	zrotate(m);
	printf("6x2: %d, 6y2 %d\n", *x2, *y2);
	back(m);
	printf("7x2: %d, 7y2 %d\n", *x2, *y2);
}

void		draw_rot(t_m m)
{
	m.i = 0;
	m.j = 0;
	init_rot(&m);
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		if (m.j != 0)
		{
			yincr_rot(&m, &(m.x2), &(m.y2));
			trace(m);
		}
		xincr_rot(&m, &(m.x2), &(m.y2));
		trace(m);
		next(&m);
		m.i++;
		if (m.i == m.column - 1 && m.j != 0)
		{
			yincr_rot(&m, &(m.x2), &(m.y2));
			trace(m);
		}
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.j++;
			m.i = 0;
			m.x1 = m.xinit;
			m.y1 = (m.yinit + m.j * m.gap) / 2;
		}
	}
}
