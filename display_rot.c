/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/06 19:47:02 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		next_x(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->z = m->array[m->j][m->i + 1];
	m->x2 += m->xlen;
	return (m->x2);
}

int		next_y(t_m *m)
{
	m->y2 = m->yout + m->j * m->gap;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->z = m->array[m->j][m->i + 1];
	m->y2 += m->xlen;
	return (m->y2);
}

int		***make_tab(t_m m)
{
	int		***tab;

	m.j = 0;
	if (!(tab = (int***)malloc(sizeof(*tab) * m.line)))
		exit(0);
	while (m.line-- > 0)
	{
		if (!(tab[m.j] = (int**)malloc(sizeof(*tab) * 2)))
			exit(0);
		if (!(tab[m.j][0] = (int*)malloc(sizeof(*tab) * m.column)))
			exit(0);
		if (!(tab[m.j][1] = (int*)malloc(sizeof(*tab) * m.column)))
			exit(0);
		m.j++;
	}
	return (tab);
}

int		***fill_tab(t_m m)
{
	int		***tab;

	init_rot(&m);
	tab = make_tab(m);
	tab[m.j][0][m.i] = m.x1;
	tab[m.j][1][m.i] = m.y1;
	m.i++;
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		tab[m.j][0][m.i] = next_x(&m);
		tab[m.j][1][m.i] = next_y(&m);
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.j++;
			m.i = 0;
			m.z = m.array[m.j][m.i + 1];
			m.x2 = m.xout;
			m.y2 = (m.yout + m.j * m.gap);
			xrotate(&m);
			yrotate(&m);
			zrotate(&m);
			m.x2 += m.xlen;
			m.y2 += m.ylen;
		}
		m.i++;
	}
	return (tab);
}

void	vert_value(t_m *m, int ***tab)
{
	m->x1 = tab[m->j][0][m->i];
	m->y1 = tab[m->j][1][m->i];
	m->x2 = tab[m->j - 1][0][m->i];
	m->y2 = tab[m->j - 1][1][m->i];
//	printf("x1: %d, y1: %d, x2: %d, y2: %d", m->x1, m->y1, m->x2, m->y2);
}

void	hori_value(t_m *m, int ***tab)
{
	m->x1 = tab[m->j][0][m->i];
	m->y1 = tab[m->j][1][m->i];
	m->x2 = tab[m->j][0][m->i + 1];
	m->y2 = tab[m->j][1][m->i + 1];
//	printf("x1: %d, y1: %d, x2: %d, y2: %d", m->x1, m->y1, m->x2, m->y2);
}

void	draw_rot(t_m m)
{
	int		***tab;

	tab = fill_tab(m);
	printf(", tab[0][0][0]: %d, tab[0][1][0]: %d\n, tab[0][0][1]: %d, tab[0][1][1]: %d\n, tab[0][0][2]: %d, tab[0][1][2]: %d\n, tab[0][0][3]: %d, tab[0][1][3]: %d\n, tab[1][0][0]: %d, tab[1][1][0]: %d\n, tab[1][0][1]: %d, tab[1][1][1]: %d\n, tab[1][0][2]: %d, tab[1][1][2]: %d\n, tab[1][0][3]: %d, tab[1][1][3]: %d\n, tab[2][0][0]: %d, tab[2][1][0]: %d\n, tab[2][0][1]: %d, tab[2][1][1]: %d\n, tab[2][0][2]: %d, tab[2][1][2]: %d\n, tab[2][0][3]: %d, tab[2][1][3]: %d\n", tab[0][0][0], tab[0][1][0], tab[0][0][1], tab[0][1][1], tab[0][0][2], tab[0][1][2], tab[0][0][3], tab[0][1][3], tab[1][0][0], tab[1][1][0], tab[1][0][1], tab[1][1][1], tab[1][0][2], tab[1][1][2], tab[1][0][3], tab[1][1][3], tab[2][0][0], tab[2][1][0], tab[2][0][1], tab[2][1][1], tab[2][0][2], tab[2][1][2], tab[2][0][3], tab[2][1][3]);
	while (m.i + 1 < m.column - 1 || m.j + 1 < m.line - 1)
	{
		if (m.j != 0)
		{
			vert_value(&m, tab);
			trace(m);
		}
		if (m.i + 1 <= m.column - 1)
		{
			hori_value(&m, tab);
			trace(m);
		}
		m.i++;
		if (m.i + 1 > m.column - 1)
		{
			m.j++;
			m.i = 0;
		}
	}
}
