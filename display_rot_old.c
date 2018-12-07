/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot_old.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/07 17:20:31 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	first_back(t_m *m)
{
	m->x1 += m->xlen;
	m->y1 += m->ylen;
}

void	back(t_m *m)
{
	m->xinit += m->xlen;
	m->yinit += m->ylen;
}

void	zero(t_m *m)
{
	ft_memset(m->str, 0, WIDTH * HEIGHT * 4);
	mlx_put_image_to_window(m->ptr, m->win, m->img, 0, 0);
	m->xout = 0 - (m->column - 1) * m->gap / 2;
	m->yout = 0 - (m->line - 1) * m->gap / 2;
	m->xlen = 0 + m->xinit + (m->column - 1) * m->gap / 2;
	m->ylen = 0 + m->yinit + (m->line - 1) * m->gap / 2;
	m->x1 = m->xout;
	m->y1 = m->yout;
}

void	init_rot(t_m *m)
{
	m->i = 0;
	m->j = 0;
	zero(m);
	first_x_rotate(m);
	first_y_rotate(m);
	first_z_rotate(m);
	m->z = m->array[0][0];
	first_back(m);
	back(m);
}


/*void		yincr_rot(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
//	printf("WTF\n");
	m->y2 = m->yout + (m->j - 1) * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->z = m->array[m->j][m->i + 1];
	m->x2 += m->xlen;
	m->y2 += m->ylen;
//	printf("A\tx1: %d, y1: %d\n\tx2: %d, y2: %d, z: %d\n", m->x1, m->y1, m->x2, m->y2, m->z);
}

void		xincr_rot(t_m *m)
{
	m->x2 = m->xout + (m->i + 1) * m->gap;
	m->y2 = m->yout + m->j * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->z = m->array[m->j][m->i + 1];
	m->x2 += m->xlen;
	m->y2 += m->ylen;
//	printf("B\tx1: %d, y1: %d\n\tx2: %d, y2: %d, z: %d\n", m->x1, m->y1, m->x2, m->y2, m->z);
}



void		draw_rot(t_m m)
{
	init_rot(&m);
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		m.z = m.array[m.j][m.i + 1];
		if (m.j != 0)
		{
//			printf("WOW\n");
			yincr_rot(&m);
			trace(m);
		}
		xincr_rot(&m);
		m.green += 30;
		trace(m);
		next(&m);
		m.i++;
		if (m.i == m.column - 1 && m.j != 0)
		{
//			printf("YOLO\n");
			yincr_rot(&m);
			trace(m);
		}
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.j++;
			m.i = 0;
			m.z = m.array[m.j][m.i + 1];
			m.x1 = m.xout;
			m.y1 = (m.yout + m.j * m.gap);
			x1rotate(&m);
			y1rotate(&m);
			z1rotate(&m);
			m.x1 += m.xlen;
			m.y1 += m.ylen;
		}
	}
}*/


// REFAIRE entierement l'algo de tracage avec un tableau qui transforme les valeurs
