/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:51:45 by gfranco           #+#    #+#             */
/*   Updated: 2018/11/29 20:19:28 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	xrotate(t_m *m)
{
	m->y2 = cos(m->xtheta) * m->y2 - sin(m->xtheta) * m->z;
	m->z = sin(m->xtheta) * m->y2 + cos(m->xtheta) * m->z;
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

void	first_x_rotate(t_m *m)
{
	m->y1 = cos(m->xtheta) * m->y1 - sin(m->xtheta) * m->z;
	m->z = sin(m->xtheta) * m->y1 + cos(m->xtheta) * m->z;
}

void	first_y_rotate(t_m *m)
{
	m->x1 = cos(m->ytheta) * m->x1 + sin(m->xtheta) * m->z;
	m->z = cos(m->ytheta) * m->z - sin(m->xtheta) * m->x1;
}

void	first_z_rotate(t_m *m)
{
	m->x1 = cos(m->ztheta) * m->x1 - sin(m->ztheta) * m->y1;
	m->y1 = sin(m->ztheta) * m->x1 + cos(m->ztheta) * m->y1;
}

void	x1rotate(t_m *m)
{
	m->y1 = cos(m->xtheta) * m->y1 - sin(m->xtheta) * m->z;
	m->z = sin(m->xtheta) * m->y1 + cos(m->xtheta) * m->z;
}

void	y1rotate(t_m *m)
{
	m->x1 = cos(m->ytheta) * m->x1 + sin(m->xtheta) * m->z;
	m->z = cos(m->ytheta) * m->z - sin(m->xtheta) * m->x1;
}

void	z1rotate(t_m *m)
{
	m->x1 = cos(m->ztheta) * m->x1 - sin(m->ztheta) * m->y1;
	m->y1 = sin(m->ztheta) * m->x1 + cos(m->ztheta) * m->y1;
}
