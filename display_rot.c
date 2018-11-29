/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/29 20:32:40 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*void	first_back(t_m *m)
{
	m->x1 = m->tmpx + WIDTH / 2;
	m->y1 = m->tmpy + HEIGHT / 2;
//	draw(*m);
//	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}*/

void	back(t_m *m)
{
	m->xinit += m->xlen;
	m->yinit += m->ylen;
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
	back(m);
}

//	voir peut etre pour l'utilisation des matrices...
//	voir peut etre pour la valeur de x1 y1 quand je relie...

void	zero(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xout = 0 - (m->column - 1) * m->initgap / 2;
	m->yout = 0 - (m->line - 1) * m->initgap / 2;
	m->xlen = 0 + m->xinit + (m->column - 1) * m->gap / 2;
	m->ylen = 0 + m->yinit + (m->line - 1) * m->gap / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
//	draw(*m);
//	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
}

void		yincr_rot(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
	m->y2 = m->yout + (m->j - 1) * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->x2 += m->xlen;
	m->y2 += m->ylen;
	printf("A x1: %d, y1: %d\nx2: %d, y2: %d\n", m->x1, m->y1, m->x2, m->y2);
}

void		xincr_rot(t_m *m)
{
	m->x2 = m->xout + (m->i + 1) * m->gap;
	m->y2 = m->yout + m->j * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->x2 += m->xlen;
	m->y2 += m->ylen;
	printf("B x1: %d, y1: %d\nx2: %d, y2: %d\n", m->x1, m->y1, m->x2, m->y2);
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
			yincr_rot(&m);
			trace(m);
		}
		xincr_rot(&m);
		m.green += 20;
		trace(m);
		next(&m);
		m.i++;
		if (m.i == m.column - 1 && m.j != 0)
		{
			yincr_rot(&m);
			trace(m);
		}
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.j++;
			m.i = 0;
			m.x1 = m.xout;
			m.y1 = (m.yout + m.j * m.gap) / 2;
			x1rotate(&m);
			y1rotate(&m);
			z1rotate(&m);
			m.x1 += m.xlen;
			m.y1 += m.ylen;
		}
	}
}
