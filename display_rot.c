/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/10 18:07:07 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

/*double	next_x(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
	m->z = m->array[m->j][m->i];
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->x2 += m->xlen;
	return (m->x2);
}*/

void	next_y(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
	m->y2 = m->yout + m->j * m->gap;
	m->z = m->array[m->j][m->i];
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->x2 += m->xlen;
	m->y2 += m->ylen;
}

int		***make_tab(t_m m)
{
	m.j = 0;
	if (!(m.tab = (int***)malloc(sizeof(*m.tab) * m.line)))
		exit(0);
	while (m.line-- > 0)
	{
		if (!(m.tab[m.j] = (int**)malloc(sizeof(*m.tab) * 2)))
			exit(0);
		if (!(m.tab[m.j][0] = (int*)malloc(sizeof(*m.tab) * m.column)))
			exit(0);
		if (!(m.tab[m.j][1] = (int*)malloc(sizeof(*m.tab) * m.column)))
			exit(0);
		m.j++;
	}
	return (m.tab);
}

int		***fill_tab(t_m m)
{
	init_rot(&m);
	m.tab = make_tab(m);
	m.tab[m.j][0][m.i] = m.x1;
	m.tab[m.j][1][m.i] = m.y1;
	printf("1\tx: %d, y: %d\n", m.x1, m.y1);
	m.i++;
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
	//	m.tab[m.j][0][m.i] = next_x(&m);
		next_y(&m);
		m.tab[m.j][0][m.i] = m.x2;
		m.tab[m.j][1][m.i] = m.y2;
		printf("\tm.tab[x]: %d, mtab[y]: %d\n", m.tab[m.j][0][m.i], m.tab[m.j][0][m.i]);
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.i = 0;
			m.j++;
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
	//	m.tab[m.j][0][m.i] = next_x(&m);
		next_y(&m);
		m.tab[m.j][0][m.i] = m.x2;
		m.tab[m.j][1][m.i] = m.y2;
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
	printf(", m.tab[0][0][0]: %d, m.tab[0][1][0]: %d\n, m.tab[0][0][1]: %d, m.tab[0][1][1]: %d\n, m.tab[0][0][2]: %d, m.tab[0][1][2]: %d\n, m.tab[0][0][3]: %d, m.tab[0][1][3]: %d\n, m.tab[1][0][0]: %d, m.tab[1][1][0]: %d\n, m.tab[1][0][1]: %d, m.tab[1][1][1]: %d\n, m.tab[1][0][2]: %d, m.tab[1][1][2]: %d\n, m.tab[1][0][3]: %d, m.tab[1][1][3]: %d\n, m.tab[2][0][0]: %d, m.tab[2][1][0]: %d\n, m.tab[2][0][1]: %d, m.tab[2][1][1]: %d\n, m.tab[2][0][2]: %d, m.tab[2][1][2]: %d\n, m.tab[2][0][3]: %d, m.tab[2][1][3]: %d\n", m.tab[0][0][0], m.tab[0][1][0], m.tab[0][0][1], m.tab[0][1][1], m.tab[0][0][2], m.tab[0][1][2], m.tab[0][0][3], m.tab[0][1][3], m.tab[1][0][0], m.tab[1][1][0], m.tab[1][0][1], m.tab[1][1][1], m.tab[1][0][2], m.tab[1][1][2], m.tab[1][0][3], m.tab[1][1][3], m.tab[2][0][0], m.tab[2][1][0], m.tab[2][0][1], m.tab[2][1][1], m.tab[2][0][2], m.tab[2][1][2], m.tab[2][0][3], m.tab[2][1][3]);
	while (m.i < m.column - 1 || m.j < m.line - 1)
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
