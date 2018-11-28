/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:51:45 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/28 15:45:06 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xrotate(t_m *m)
{
	m->y2 = cos(m->xtheta) * m->y2 - sin(m->xtheta) * m->z;
	m->z = sin(m->xtheta) * m->y2 + cos(m->xtheta) * m->z;
/*	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xinit = 0 - (m->column - 1) * m->initgap / 2;
	m->yinit = 0 - (m->line - 1) * m->initgap / 2;
	m->x1 = m->xinit;
	m->y1 = m->yinit;
	draw(*m);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);*/
}

void	yrotate(t_m *m)
{
	m->x2 = cos(m->ytheta) * m->x2 + sin(m->xtheta) * m->z;
	m->z = cos(m->ytheta) * m->z - sin(m->xtheta) * m->x2;
}

void	zrotate(t_m *m)
{
	m->x2 = cos(m->ztheta) * m->x2 - sin(m->ztheta) * m->y2;
	m->y2 = sin(m->ztheta) * m->x2 + cos(m->ztheta) * m->y2;
}
