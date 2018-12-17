/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_rot.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gfranco <gfranco@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/28 18:30:55 by gfranco           #+#    #+#             */
/*   Updated: 2018/12/17 12:47:43 by gfranco          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	next_y(t_m *m)
{
	m->x2 = m->xout + m->i * m->gap;
	m->y2 = m->yout + m->j * m->gap;
	m->z = m->array[m->j][m->i] * m->relief;
	m->z = m->z >= MAX_Z ? 1000 : m->z;
	m->z = m->z <= MIN_Z ? -1000 : m->z;
	xrotate(m);
	yrotate(m);
	zrotate(m);
	m->x2 += m->xlen;
	m->y2 += m->ylen;
}

int		***make_tab(t_m m)
{
	m.j = 0;
	if (!(m.tab = (int***)malloc(sizeof(int**) * m.line)))
		exit(0);
	while (m.line-- > 0)
	{
		if (!(m.tab[m.j] = (int**)malloc(sizeof(int*) * 2)))
			exit(0);
		if (!(m.tab[m.j][0] = (int*)malloc(sizeof(int) * m.column)))
			exit(0);
		if (!(m.tab[m.j][1] = (int*)malloc(sizeof(int) * m.column)))
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
	m.i++;
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		next_y(&m);
		m.tab[m.j][0][m.i] = m.x2;
		m.tab[m.j][1][m.i] = m.y2;
		if (m.i == m.column - 1 && m.j != m.line - 1)
		{
			m.i = 0;
			m.j++;
			m.z = m.array[m.j][m.i] * m.relief;
			m.z = m.z >= MAX_Z ? 1000 : m.z;
			m.z = m.z <= MIN_Z ? -1000 : m.z;
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

void	draw_rot(t_m m, t_color *color)
{
//	int		i = 0;
//	int		j = 0;
	m.tab = fill_tab(m);
/*	while (i < m.line - 1)
	{
		while (j < m.column - 1)
		{
			printf("\ttab[%d][0][%d]: %d, tab[%d][0][%d]: %d\n", i, j, m.tab[i][0][j], i, j, m.tab[i][1][j]);
			j++;
		}
		i++;
		j = 0;
	}
	printf("\n\n");*/
	/*	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[0][0][0], m.tab[0][1][0]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[0][0][0], m.tab[0][1][0]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[0][0][1], m.tab[0][1][1]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[0][0][1], m.tab[0][1][1]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[0][0][2], m.tab[0][1][2]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[0][0][2], m.tab[0][1][2]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[0][0][3], m.tab[0][1][3]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[0][0][3], m.tab[0][1][3]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[1][0][0], m.tab[1][1][0]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[1][0][0], m.tab[1][1][0]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[1][0][1], m.tab[1][1][1]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[1][0][1], m.tab[1][1][1]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[1][0][2], m.tab[1][1][2]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[1][0][2], m.tab[1][1][2]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[1][0][3], m.tab[1][1][3]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[1][0][3], m.tab[1][1][3]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[2][0][0], m.tab[2][1][0]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[2][0][0], m.tab[2][1][0]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[2][0][1], m.tab[2][1][1]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[2][0][1], m.tab[2][1][1]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[2][0][2], m.tab[2][1][2]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[2][0][2], m.tab[2][1][2]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[2][0][3], m.tab[2][1][3]);
	printf("\ttab[x]: %d, tab[y]: %d\n", m.tab[2][0][3], m.tab[2][1][3]);*/
	while (m.i < m.column - 1 || m.j < m.line - 1)
	{
		if (m.j != 0)
		{
			vert_value(&m);
			printf("xinit: %f, yinit: %f\n", m.xinit, m.yinit);
			trace(m, color);
		}
		if (m.i < m.column - 1)
		{
			hori_value(&m);
			printf("xinit: %f, yinit: %f\n", m.xinit, m.yinit);
			trace(m, color);
		}
		m.i++;
		if (m.i == m.column - 1 && m.j != 0)
		{
			vert_value(&m);
			printf("xinit: %f, yinit: %f\n", m.xinit, m.yinit);
			trace(m, color);
		}
		if (m.i >= m.column - 1 && m.j < m.line - 1)
		{
			m.j++;
			m.i = 0;
		}
	}
}
