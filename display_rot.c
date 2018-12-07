/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/07 16:49:06 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

double	next_x(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->z = m->array[m->j][m->i];
	m->x2 += m->xlen;
	return (m->x2);
}

double	next_y(t_m *m)
{
	m->y2 = m->yout + m->j * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->z = m->array[m->j][m->i];
	m->y2 += m->ylen;
	return (m->y2);
}

double	***make_tab(t_m m)
{
	m.j = 0;
	if (!(m.tab = (double***)malloc(sizeof(*m.tab) * m.line)))
		exit(0);
	while (m.line-- > 0)
	{
		if (!(m.tab[m.j] = (double**)malloc(sizeof(*m.tab) * 2)))
			exit(0);
		if (!(m.tab[m.j][0] = (double*)malloc(sizeof(*m.tab) * m.column)))
			exit(0);
		if (!(m.tab[m.j][1] = (double*)malloc(sizeof(*m.tab) * m.column)))
			exit(0);
		m.j++;
	}
	return (m.tab);
}

double	***fill_tab(t_m m)
{
	init_rot(&m);
	m.tab = make_tab(m);
	m.tab[m.j][0][m.i] = m.x1;
	m.tab[m.j][1][m.i] = m.y1;
	m.i++;
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		m.tab[m.j][0][m.i] = next_x(&m);
		m.tab[m.j][1][m.i] = next_y(&m);
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.j++;
			m.i = 0;
			m.z = m.array[m.j][m.i];
			m.x2 = m.xout;
			m.y2 = (m.yout + m.j * m.gap);
			xrotate(&m);
			yrotate(&m);
			zrotate(&m);
			m.x2 += m.xlen;
			m.y2 += m.ylen;
			m.tab[m.j][0][m.i] = m.x2;
			m.tab[m.j][1][m.i] = m.y2;
		}
		m.i++;
	}
	if (m.i == m.column - 1 && m.j == m.line - 1)
	{
		m.tab[m.j][0][m.i] = next_x(&m);
		m.tab[m.j][1][m.i] = next_y(&m);
	}
	return (m.tab);
}

void	vert_value(t_m *m)
{
	m->x1 = m->tab[m->j][0][m->i];
	m->y1 = m->tab[m->j][1][m->i];
	m->x2 = m->tab[m->j - 1][0][m->i];
	m->y2 = m->tab[m->j - 1][1][m->i];
}

void	hori_value(t_m *m)
{
	m->x1 = m->tab[m->j][0][m->i];
	m->y1 = m->tab[m->j][1][m->i];
	m->x2 = m->tab[m->j][0][m->i + 1];
	m->y2 = m->tab[m->j][1][m->i + 1];
}

void	draw_rot(t_m m)
{
	m.tab = fill_tab(m);
	printf(", m.tab[0][0][0]: %f, m.tab[0][1][0]: %f\n, m.tab[0][0][1]: %f, m.tab[0][1][1]: %f\n, m.tab[0][0][2]: %f, m.tab[0][1][2]: %f\n, m.tab[0][0][3]: %f, m.tab[0][1][3]: %f\n, m.tab[1][0][0]: %f, m.tab[1][1][0]: %f\n, m.tab[1][0][1]: %f, m.tab[1][1][1]: %f\n, m.tab[1][0][2]: %f, m.tab[1][1][2]: %f\n, m.tab[1][0][3]: %f, m.tab[1][1][3]: %f\n, m.tab[2][0][0]: %f, m.tab[2][1][0]: %f\n, m.tab[2][0][1]: %f, m.tab[2][1][1]: %f\n, m.tab[2][0][2]: %f, m.tab[2][1][2]: %f\n, m.tab[2][0][3]: %f, m.tab[2][1][3]: %f\n", m.tab[0][0][0], m.tab[0][1][0], m.tab[0][0][1], m.tab[0][1][1], m.tab[0][0][2], m.tab[0][1][2], m.tab[0][0][3], m.tab[0][1][3], m.tab[1][0][0], m.tab[1][1][0], m.tab[1][0][1], m.tab[1][1][1], m.tab[1][0][2], m.tab[1][1][2], m.tab[1][0][3], m.tab[1][1][3], m.tab[2][0][0], m.tab[2][1][0], m.tab[2][0][1], m.tab[2][1][1], m.tab[2][0][2], m.tab[2][1][2], m.tab[2][0][3], m.tab[2][1][3]);
	while (m.i < m.column - 1 || m.j + 1 < m.line - 1)
	{
		if (m.j != 0)
		{
			vert_value(&m);
			trace(m);
		}
		if (m.i < m.column - 1)
		{
			hori_value(&m);
			trace(m);
		}
		m.i++;
		if (m.i == m.column - 1 && m.j != 0)
		{
			vert_value(&m);
			trace(m);
		}
		if (m.i >= m.column - 1 && m.j < m.line - 1)
		{
			m.j++;
			m.i = 0;
		}
	}
}
