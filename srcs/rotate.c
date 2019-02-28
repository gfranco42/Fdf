/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/22 12:51:45 by gfranco           #+#    #+#             */
/*   Updated: 2019/01/14 16:28:42 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void	rotate(t_m *m)
{
	int		x;
	int		y;
	int		z;

	y = m->y2;
	z = m->z;
	m->y2 = cos(m->xtheta) * y - sin(m->xtheta) * z;
	m->z = sin(m->xtheta) * y + cos(m->xtheta) * z;
	x = m->x2;
	z = m->z;
	m->x2 = cos(m->ytheta) * x + sin(m->ytheta) * z;
	m->z = cos(m->ytheta) * z - sin(m->ytheta) * x;
	x = m->x2;
	y = m->y2;
	m->x2 = cos(m->ztheta) * x - sin(m->ztheta) * y;
	m->y2 = sin(m->ztheta) * x + cos(m->ztheta) * y;
}

void	first_rotate(t_m *m)
{
	int		x;
	int		y;
	int		z;

	y = m->y1;
	z = m->z;
	m->y1 = cos(m->xtheta) * y - sin(m->xtheta) * z;
	m->z = sin(m->xtheta) * y + cos(m->xtheta) * z;
	x = m->x1;
	z = m->z;
	m->x1 = cos(m->ytheta) * x + sin(m->ytheta) * z;
	m->z = cos(m->ytheta) * z - sin(m->ytheta) * x;
	x = m->x1;
	y = m->y1;
	m->x1 = cos(m->ztheta) * x - sin(m->ztheta) * y;
	m->y1 = sin(m->ztheta) * x + cos(m->ztheta) * y;
}
